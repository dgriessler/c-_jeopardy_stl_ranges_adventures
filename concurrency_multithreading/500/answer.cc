#include "concurrency_multithreading/500/500.hh"
#include <iostream>
#include <random>
#include <thread>

std::string random_item() {
  static std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<> dist(0, menu.size() - 1);
  return menu[dist(rng)];
}

void customer(int id, std::mutex &order_mutex, std::queue<Order> &order_queue,
              std::condition_variable &order_cv) {
  for (int i = 0; i < 3; ++i) {
    Order o{id * 10 + i, random_item()};
    {
      std::scoped_lock lock(order_mutex);
      order_queue.push(o);
    }
    order_cv.notify_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

void cook(int id, std::mutex &order_mutex, std::queue<Order> &order_queue,
          std::condition_variable &order_cv, std::atomic<bool> &open,
          std::mutex &ready_mutex, std::queue<Order> &ready_queue,
          std::condition_variable &ready_cv) {
  while (true) {
    std::unique_lock lock(order_mutex);
    order_cv.wait(lock, [&] { return !order_queue.empty() || !open; });
    if (!open && order_queue.empty())
      break;

    Order o = order_queue.front();
    order_queue.pop();
    lock.unlock();

    std::cout << "Cook " << id << " preparing order " << o.id << " (" << o.item
              << ")\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    {
      std::scoped_lock ready_lock(ready_mutex);
      ready_queue.push(o);
    }
    ready_cv.notify_one();
  }
}

void waiter(int id, std::mutex &ready_mutex, std::queue<Order> &ready_queue,
            std::condition_variable &ready_cv, std::atomic<bool> &open,
            std::vector<Order> &served_orders) {
  while (true) {
    std::unique_lock lock(ready_mutex);
    ready_cv.wait(lock, [&] { return !ready_queue.empty() || !open; });
    if (!open && ready_queue.empty())
      break;

    Order o = ready_queue.front();
    ready_queue.pop();
    lock.unlock();

    std::cout << "Waiter " << id << " served order " << o.id << " (" << o.item
              << ")\n";
    served_orders.emplace_back(o);
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
  }
}
