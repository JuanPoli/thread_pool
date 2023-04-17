#pragma once
#include "ITask.h"

class MultiplicationTask : public ITask {
public:
    MultiplicationTask(int a, int b, int& result);
    ~MultiplicationTask();
    virtual void run();

private:
    int a;
    int b;
    int& result;
};

