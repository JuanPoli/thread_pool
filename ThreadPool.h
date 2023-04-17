#pragma once

#include "IThreadPool.h"
#include "Task.h"
#include <queue>
#ifndef _TIMESPEC_DEFINED
#define _TIMESPEC_DEFINED
#include <pthread.h>
#endif
#include <stdexcept>
#include <vector>


class ThreadPool : public IThreadPool {
public:
	ThreadPool(int num_threads);
	~ThreadPool();

    void start();
    void stop();
    void addTask(ITask* task);

private:
    void workerLoop();

    int num_threads_;
    std::vector<pthread_t> threads_;
    std::queue<ITask*> task_queue_;
    pthread_mutex_t queue_mutex_;
    pthread_cond_t queue_cv_;
    bool stop_requested_;
    pthread_mutex_t stop_mutex_;
    int next_thread_;
};