MAKEFILE_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
PROJDIR := $(abspath $(MAKEFILE_DIR)/../..)
CONTRIB_DIR := $(abspath $(PROJDIR)/contrib)
GTEST_DIR := $(abspath $(CONTRIB_DIR)/googletest_install)
CXX := clang++
CXXFLAGS += -I"$(PROJDIR)" -Wall -g -std=c++20

CXXFLAGS += -I$(GTEST_DIR)/include
LDFLAGS += -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread

SRCS = attempt.cc
OBJS = $(SRCS:.cc=.o)

ANS_SRCS = answer.cc
ANS_OBJS = $(ANS_SRCS:.cc=.o)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

TEST_SOURCES = 100_test.cc
TEST_OBJECTS = $(TEST_SOURCES:.cc=.o)
TEST_EXECUTABLE = 100_test
TEST_ANS_EXECUTABLE = 100_ans_test

$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(TEST_ANS_EXECUTABLE): $(TEST_OBJECTS) $(ANS_OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

.PHONY: test
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

answer_test: $(TEST_ANS_EXECUTABLE)
	./$(TEST_ANS_EXECUTABLE)

clean:
	rm *.o 2>/dev/null || true
	rm 100_test 2>/dev/null || true
	rm 100_ans_test 2>/dev/null || true