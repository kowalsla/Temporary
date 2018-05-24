#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "Common.h"
#include "FileManager.h"

class ThreadPool //TODO
{
public:
  explicit ThreadPool(const FileManager &newFmObject);
  ~ThreadPool() {}

private:
  DISABLE_DEFAULT_CONSTUCTORS(ThreadPool);
  FileManager fmObject;
};

#endif //THREADPOOL_H