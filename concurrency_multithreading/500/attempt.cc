#include "concurrency_multithreading/500/500.hh"
#include <iostream>
#include <random>
#include <thread>

std::string random_item() { return menu[0]; }

void customer(int id, std::mutex &order_mutex, std::queue<Order> &order_queue,
              std::condition_variable &order_cv) {}

void cook(int id, std::mutex &order_mutex, std::queue<Order> &order_queue,
          std::condition_variable &order_cv, std::atomic<bool> &open,
          std::mutex &ready_mutex, std::queue<Order> &ready_queue,
          std::condition_variable &ready_cv) {}

void waiter(int id, std::mutex &ready_mutex, std::queue<Order> &ready_queue,
            std::condition_variable &ready_cv, std::atomic<bool> &open,
            std::vector<Order> &served_orders) {}
