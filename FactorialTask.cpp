#include "FactorialTask.h"


FactorialTask::FactorialTask(int n, int& result) : n(n), result(result) {}
FactorialTask::~FactorialTask(){}

void FactorialTask::run() {
        result = factorial(n);
    }


int FactorialTask::factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}


