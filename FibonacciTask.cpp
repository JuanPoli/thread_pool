#include "FibonacciTask.h"

FibonacciTask::FibonacciTask(int n, int& result) : n(n), result(result) {}
FibonacciTask::~FibonacciTask(){}

void FibonacciTask::run() {
    if (n <= 1) {
        result = n;
    }
    else {
        int a = 0;
        int b = 1;
        for (int i = 2; i <= n; i++) {
            int next = a + b;
            a = b;
            b = next;
        }
        result = b;
    }
}

