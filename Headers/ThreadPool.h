#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "Common.h"

class ThreadPool //TODO
{
public:
  explicit ThreadPool(const int &amountOfThreads);

private:
  DISABLE_DEFAULT_CONSTUCTORS(ThreadPool);
};

#endif //THREADPOOL_H