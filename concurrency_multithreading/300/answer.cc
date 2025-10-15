#include "concurrency_multithreading/300/300.hh"
#include <iostream>
#include <thread>

void producer(std::mutex &mtx, std::condition_variable &cv,
              std::queue<int> &data_queue, bool &finished) {
  for (int i = 1; i <= 5; ++i) {
    {
      std::lock_guard lock(mtx);
      data_queue.push(i);
      std::cout << "[Producer] produced " << i << '\n';
    }
    cv.notify_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
  {
    std::lock_guard lock(mtx);
    finished = true;
  }
  cv.notify_all(); // wake consumers to end
}

void consumer(std::mutex &queue_mtx, std::condition_variable &cv,
              std::queue<int> &data_queue, std::mutex &result_mtx,
              std::vector<int> &result, bool &finished) {
  while (true) {
    std::unique_lock lock(queue_mtx);
    cv.wait(lock, [&] { return !data_queue.empty() || finished; });
    if (data_queue.empty() || finished)
      break;

    int value = data_queue.front();
    data_queue.pop();
    lock.unlock();

    std::cout << "    [Consumer] processed " << value << '\n';
    std::unique_lock result_lock(result_mtx);
    result.emplace_back(value);
  }
  std::cout << "[Consumer] done.\n";
}
