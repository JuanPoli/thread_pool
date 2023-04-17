#pragma once
#include "ITask.h"

class FibonacciTask : public ITask {
public:
    FibonacciTask(int n, int& result);
    ~FibonacciTask();
    virtual void run();

private:
    int n;
    int& result;
};

