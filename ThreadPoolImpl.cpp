#pragma once
#include "ThreadPool.h"
#define STACK_SIZE 100
#include <queue>
#include <iostream>

ThreadPool::ThreadPool(int num_threads)
    : num_threads_(num_threads),
    next_thread_(0),
    threads_(num_threads),
    stop_requested_(false)
{
    if (pthread_mutex_init(&queue_mutex_, NULL) != 0) {
        throw std::runtime_error("Failed to initialize queue mutex");
    }

    if (pthread_cond_init(&queue_cv_, NULL) != 0) {
        pthread_mutex_destroy(&queue_mutex_);
        throw std::runtime_error("Failed to initialize queue condition variable");
    }

    if (pthread_mutex_init(&stop_mutex_, NULL) != 0) {
        pthread_mutex_destroy(&queue_mutex_);
        pthread_cond_destroy(&queue_cv_);
        throw std::runtime_error("Failed to initialize stop mutex");
    }
}

ThreadPool::~ThreadPool()
{
    stop();
}

void ThreadPool::start()
{
    for (int i = 0; i < num_threads_; i++) {
        if (pthread_create(&threads_[i], NULL,
            [](void* arg) -> void* {
            ThreadPool* tp = static_cast<ThreadPool*>(arg);
        tp->workerLoop();
        return nullptr;
        }, this) != 0)
        {
            throw std::runtime_error("Failed to create thread");
        }
    }
}

void ThreadPool::stop()
{
    {
        pthread_mutex_lock(&stop_mutex_);
        stop_requested_ = true;
        pthread_mutex_unlock(&stop_mutex_);
    }
    pthread_cond_broadcast(&queue_cv_);

    for (auto& thread : threads_) {
        if (pthread_join(thread, NULL) != 0) {
            throw std::runtime_error("Failed to join worker thread");
        }
    }
}

void ThreadPool::addTask(ITask* task) {
    if (task) {
        // Lock the mutex to ensure exclusive access to the task queue and thread index
        pthread_mutex_lock(&queue_mutex_);

        // Add the task to the queue
        task_queue_.push(task);

        // Increment the index of the next thread to add a task to
        next_thread_ = (next_thread_ + 1) % num_threads_;

        // Signal one of the waiting threads to wake up and start executing tasks
        pthread_cond_signal(&queue_cv_);

        // Unlock the mutex to allow other threads to access the task queue and thread index
        pthread_mutex_unlock(&queue_mutex_);
    }
}

/*void ThreadPool::addTask(ITask* task) {
    if (task) {
        pthread_mutex_lock(&queue_mutex_);
        task_queue_.push(task);
        pthread_mutex_unlock(&queue_mutex_);
        pthread_cond_signal(&queue_cv_);
    }
}*/

void ThreadPool::workerLoop()
{
    while (true) {
        ITask* task = nullptr;
        {
            pthread_mutex_lock(&queue_mutex_);
            while (task_queue_.empty() && !stop_requested_) {
                pthread_cond_wait(&queue_cv_, &queue_mutex_);
            }

            if (stop_requested_) {
                pthread_mutex_unlock(&queue_mutex_);
                break;
            }

            task = task_queue_.front();
            task_queue_.pop();
            pthread_mutex_unlock(&queue_mutex_);
        }
        task->run();
        delete task;
    }
}