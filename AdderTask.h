#pragma once
#include "ITask.h"

class AdderTask : public ITask {
public:
    AdderTask(int a, int b, int& result);
    ~AdderTask();
    void run();

private:
    int a, b;
    int& result;
};

