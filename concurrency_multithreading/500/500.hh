#pragma once

#include <mutex>
#include <queue>
#include <string>
#include <vector>

// Simulate a restaurant with multiple cooks and waiters working concurrently.
// Orders are placed by customers, cooked by chefs, and served by waiters — all
// running in separate threads. Use mutexes and condition variables to safely
// coordinate the flow of orders.

struct Order {
  int id;
  std::string item;
};

// Random item generator
static const std::vector<std::string> menu = {"Burger", "Pizza", "Salad",
                                              "Pasta", "Soup"};

std::string random_item();

// Customer thread: places orders
void customer(int id, std::mutex &order_mutex, std::queue<Order> &order_queue,
              std::condition_variable &order_cv);

// Cook thread: processes orders into ready meals
void cook(int id, std::mutex &order_mutex, std::queue<Order> &order_queue,
          std::condition_variable &order_cv, std::atomic<bool> &open,
          std::mutex &ready_mutex, std::queue<Order> &ready_queue,
          std::condition_variable &ready_cv);

// Waiter thread: serves ready meals
void waiter(int id, std::mutex &ready_mutex, std::queue<Order> &ready_queue,
            std::condition_variable &ready_cv, std::atomic<bool> &open,
            std::vector<Order> &served_orders);
