#include "concurrency_multithreading/500/500.hh"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <future>
#include <thread>

using ::testing::Each;
using ::testing::IsSubsetOf;

TEST(Simulate, Restaurant) {

  // Shared resources
  std::queue<Order> order_queue;
  std::queue<Order> ready_queue;
  std::mutex order_mutex, ready_mutex;
  std::condition_variable order_cv, ready_cv;
  std::atomic<bool> open{true};
  std::vector<std::thread> customers, cooks, waiters;
  std::vector<std::vector<Order>> served_orders;

  for (int i = 0; i < 3; ++i)
    customers.emplace_back(customer, i + 1, std::ref(order_mutex),
                           std::ref(order_queue), std::ref(order_cv));
  for (int i = 0; i < 2; ++i)
    cooks.emplace_back(cook, i + 1, std::ref(order_mutex),
                       std::ref(order_queue), std::ref(order_cv),
                       std::ref(open), std::ref(ready_mutex),
                       std::ref(ready_queue), std::ref(ready_cv));
  served_orders.resize(2);
  for (int i = 0; i < served_orders.size(); ++i) {
    waiters.emplace_back(waiter, i + 1, std::ref(ready_mutex),
                         std::ref(ready_queue), std::ref(ready_cv),
                         std::ref(open), std::ref(served_orders[i]));
  }

  for (auto &c : customers)
    c.join();

  // Signal cooks and waiters to finish
  {
    std::scoped_lock lock(order_mutex, ready_mutex);
    open = false;
  }
  order_cv.notify_all();
  ready_cv.notify_all();

  for (auto &t : cooks) {
    t.join();
  }

  std::vector<Order> all_items;
  for (size_t i = 0; i < waiters.size(); i++) {
    waiters[i].join();
  }
  for (size_t i = 0; i < waiters.size(); i++) {
    all_items.insert(all_items.end(), served_orders[i].begin(),
                     served_orders[i].end());
  }
  EXPECT_GE(all_items.size(), 4);
  for (const auto &order : all_items) {
    EXPECT_NE(std::find(menu.begin(), menu.end(), order.item), menu.end());
  }
}
