#include "Task.h"
#include <iostream>

Task::Task(const std::string& message) : message_(message) {
}

Task::~Task() {

}

void Task::run() {
    std::cout << "Executing task: " << message_ << std::endl;
    // Perform task logic here
}

