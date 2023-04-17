#pragma once
#include "ITask.h"

class FactorialTask : public ITask {
public:
    FactorialTask(int n, int& result);
    ~FactorialTask();
    virtual void run();

private:
    int n;
    int& result;

    int factorial(int n);
};

