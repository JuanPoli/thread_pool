#pragma once
#include "Task.h"

interface IThreadPool
{
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void addTask(ITask* task) = 0;
};

