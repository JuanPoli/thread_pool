#pragma once
#include "ITask.h"
#include <string>

class Task: public ITask {
public:
    Task(const std::string& message);
    ~Task();
    void run();

private:
    std::string message_;
};
