#include "MultiplicationTask.h"

MultiplicationTask::MultiplicationTask(int a, int b, int& result): a(a), b(b), result(result) {}
MultiplicationTask::~MultiplicationTask() {}
void MultiplicationTask::run(){
    result = a * b;
}
