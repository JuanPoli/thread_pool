#pragma once
#define interface struct

interface ITask
{
    virtual void run() = 0;
    //pthread_t thread_id_;
};

