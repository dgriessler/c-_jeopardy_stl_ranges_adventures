MAKEFILE_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
PROJDIR := $(abspath $(MAKEFILE_DIR)/../..)
CONTRIB_DIR := $(abspath $(PROJDIR)/contrib)
GTEST_DIR := $(abspath $(CONTRIB_DIR)/googletest_install)
OUT_DIR := $(abspath $(MAKEFILE_DIR)/out)
CXX := clang++
CXXFLAGS += -I"$(PROJDIR)" -Wall -g -std=c++20

CXXFLAGS += -I$(GTEST_DIR)/include
LDFLAGS += -L$(GTEST_DIR)/lib -lgtest -lgmock -lgtest_main -pthread

SRCS = attempt.cc
OBJS := $(patsubst %.cc,$(OUT_DIR)/%.o,$(SRCS))

ANS_SRCS = answer.cc
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

.PHONY: test
test: $(TEST_EXECUTABLE)
	$(TEST_EXECUTABLE)

answer_test: $(TEST_ANS_EXECUTABLE)
	$(TEST_ANS_EXECUTABLE)

clean:
	rm -r out/ 2>/dev/null || true