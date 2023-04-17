// Thread_Pool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ThreadPool.h"
#include "MultiplicationTask.h"
#include "AdderTask.h"
#include "FibonacciTask.h"
#include "FactorialTask.h"


/*void runThreadPool() {
    const int num_threads = 4;
    ThreadPool thread_pool(num_threads);

    thread_pool.start();

    for (int i = 1; i <= 10; i++) {
        int a = i;
        int b = i + 1;
        int multiplicationResult = 0;

        ITask* multiplicationTask = new MultiplicationTask(a, b, multiplicationResult);
        thread_pool.addTask(multiplicationTask);

        std::string message = "Multiplication Task " + std::to_string(i);
        pthread_t ptid = pthread_self();
        uint64_t threadId = 0;
        memcpy(&threadId, &ptid, std::min(sizeof(threadId), sizeof(ptid)));
        std::cout << "Multiplication of " << a << " * " << b << " = " << multiplicationResult << " And is running on thread: " << threadId << std::endl;
    }

   
    for (int i = 1; i <= 10; i++) {
        int a = i;
        int b = i + 1;
        int adderResult = 0;

        ITask* adderTask = new AdderTask(a, b, adderResult);
        thread_pool.addTask(adderTask);

        std::string message = "Addition Task " + std::to_string(i);
        pthread_t ptid = pthread_self();
        uint64_t threadId = 0;
        memcpy(&threadId, &ptid, std::min(sizeof(threadId), sizeof(ptid)));
        std::cout << "addition of " << a << " + " << b << " = " << adderResult << " And is running on thread: " << threadId << std::endl;
    }
}*/

void runThreadPool() {
    const int num_threads = 2;
    ThreadPool thread_pool(num_threads);

    thread_pool.start();

    for (int i = 1; i <= 10; i++) {
        int a = i;
        int b = i + 1;
        int multiplicationResult = 0;
        int adderResult = 0;
        int fibonacciResult = 0;
        int factorialResult = 0;

        ITask* multiplicationTask = new MultiplicationTask(a, b, multiplicationResult);
        thread_pool.addTask(multiplicationTask);

        ITask* adderTask = new AdderTask(a, b, adderResult);
        thread_pool.addTask(adderTask);

        ITask* fibonacciTask = new FibonacciTask(i, fibonacciResult);
        thread_pool.addTask(fibonacciTask);

        ITask* factorialTask = new FactorialTask(i, factorialResult);
        thread_pool.addTask(factorialTask);

        std::string message = "Task " + std::to_string(i);
        pthread_t ptid = pthread_self();
        uint64_t threadId = 0;
        memcpy(&threadId, &ptid, std::min(sizeof(threadId), sizeof(ptid)));
        std::cout << "Multiplication of " << a << " * " << b << " = " << multiplicationResult << " And is running on thread: " << threadId << std::endl;
        //ptid = adderTask->thread_id_;
        //threadId = 0;
        //memcpy(&threadId, &ptid, std::min(sizeof(adderTask->thread_id_), sizeof(ptid)));
        ptid = pthread_self();
        threadId = 0;
        memcpy(&threadId, &ptid, std::min(sizeof(threadId), sizeof(ptid)));
        std::cout << "Addition of " << a << " + " << b << " = " << adderResult << " And is running on thread: " << threadId << std::endl;
        ptid = pthread_self();
        threadId = 0;
        memcpy(&threadId, &ptid, std::min(sizeof(threadId), sizeof(ptid)));
        std::cout << "Fibonacci of " << a << " * " << b << " = " << fibonacciResult << " And is running on thread: " << threadId << std::endl;
        ptid = pthread_self();
        threadId = 0;
        memcpy(&threadId, &ptid, std::min(sizeof(threadId), sizeof(ptid)));
        std::cout << "Factorial of " << a << " + " << b << " = " << factorialResult << " And is running on thread: " << threadId << std::endl;
    }
}

int main() {
    runThreadPool();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
