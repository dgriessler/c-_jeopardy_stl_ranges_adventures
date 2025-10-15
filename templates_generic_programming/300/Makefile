MAKEFILE_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
PROJDIR := $(abspath $(MAKEFILE_DIR)/../..)
CONTRIB_DIR := $(abspath $(PROJDIR)/contrib)
GTEST_DIR := $(abspath $(CONTRIB_DIR)/googletest_install)
OUT_DIR := $(abspath $(MAKEFILE_DIR)/out)
CXX := clang++
CXXFLAGS += -I"$(PROJDIR)" -Wall -g -std=c++20

CXXFLAGS += -I$(GTEST_DIR)/include
ifeq ($(ANSWER),1)
CXXFLAGS += -DANSWER=1
endif
LDFLAGS += -L$(GTEST_DIR)/lib -lgtest -lgmock -lgtest_main -pthread

SRCS =
OBJS := $(patsubst %.cc,$(OUT_DIR)/%.o,$(SRCS))

ANS_SRCS =
ANS_OBJS := $(patsubst %.cc,$(OUT_DIR)/%.o,$(ANS_SRCS))

$(OUT_DIR)/%.o: %.cc
	mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

TEST_SOURCES = 300_test.cc
TEST_OBJECTS := $(patsubst %.cc,$(OUT_DIR)/%.o,$(TEST_SOURCES))
TEST_EXECUTABLE = $(OUT_DIR)/300_test
TEST_ANS_EXECUTABLE = $(OUT_DIR)/300_ans_test

$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(TEST_ANS_EXECUTABLE): $(TEST_OBJECTS) $(ANS_OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)

.PHONY: test inner_test answer_test inner_answer_test
test: clean
	$(MAKE) inner_test

inner_test: $(TEST_EXECUTABLE)
	$(TEST_EXECUTABLE)

answer_test: clean
	$(MAKE) ANSWER=1 inner_answer_test

inner_answer_test: $(TEST_ANS_EXECUTABLE)
	$(TEST_ANS_EXECUTABLE)

clean:
	rm -r out/ 2>/dev/null || true