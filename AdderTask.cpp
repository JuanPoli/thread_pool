#include "AdderTask.h"

AdderTask::AdderTask(int a, int b, int& result):a(a) ,b(b), result(result) {}
AdderTask::~AdderTask(){}
void AdderTask::run() {
	result = a + b;
	//thread_id_ = pthread_self();
}
