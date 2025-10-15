#include "concurrency_multithreading/300/300.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <thread>

using ::testing::UnorderedElementsAre;

class Fixture : public ::testing::Test {
protected:
  std::mutex queue_mtx;
  std::condition_variable cv;
  std::queue<int> data_queue;
  bool finished = false;
  std::mutex result_mtx;
  std::vector<int> result;
};

TEST_F(Fixture, Producer1Consumer) {

  std::thread t1(producer, std::ref(queue_mtx), std::ref(cv),
                 std::ref(data_queue), std::ref(finished));
  std::thread t2(consumer, std::ref(queue_mtx), std::ref(cv),
                 std::ref(data_queue), std::ref(result_mtx), std::ref(result),
                 std::ref(finished));

  t1.join();
  t2.join();

  EXPECT_THAT(result, UnorderedElementsAre(1, 2, 3, 4, 5));
}

TEST_F(Fixture, Producer5Consumer) {

  std::thread t1(producer, std::ref(queue_mtx), std::ref(cv),
                 std::ref(data_queue), std::ref(finished));
  std::thread t2(consumer, std::ref(queue_mtx), std::ref(cv),
                 std::ref(data_queue), std::ref(result_mtx), std::ref(result),
                 std::ref(finished));
  std::thread t3(consumer, std::ref(queue_mtx), std::ref(cv),
                 std::ref(data_queue), std::ref(result_mtx), std::ref(result),
                 std::ref(finished));
  std::thread t4(consumer, std::ref(queue_mtx), std::ref(cv),
                 std::ref(data_queue), std::ref(result_mtx), std::ref(result),
                 std::ref(finished));
  std::thread t5(consumer, std::ref(queue_mtx), std::ref(cv),
                 std::ref(data_queue), std::ref(result_mtx), std::ref(result),
                 std::ref(finished));
  std::thread t6(consumer, std::ref(queue_mtx), std::ref(cv),
                 std::ref(data_queue), std::ref(result_mtx), std::ref(result),
                 std::ref(finished));

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();

  EXPECT_THAT(result, UnorderedElementsAre(1, 2, 3, 4, 5));
}
