#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>

void producer(std::mutex &mtx, std::condition_variable &cv,
              std::queue<int> &data_queue, bool &finished);

void consumer(std::mutex &queue_mtx, std::condition_variable &cv,
              std::queue<int> &data_queue, std::mutex &result_mtx,
              std::vector<int> &result, bool &finished);
