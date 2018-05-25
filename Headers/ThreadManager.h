#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "Common.h"
#include "FileManager.h"
#include "AllTasks.h"
class ThreadManager
{
public:
  explicit ThreadManager(const FileManager &newFmObject);
  std::vector<singleTask> getCalculatedTasks();

  void init();
  void startThreads();
  void joinThreads();

  ~ThreadManager();

private:
  DISABLE_DEFAULT_CONSTUCTORS(ThreadManager);
  void threadCalculateTasks(std::vector<singleTask> *vectorOfTasks, const int &maxSize, int begin, int end);
  void calculateSingleTask(singleTask &taskToCalculate);

  FileManager fmObject;
  int additionalThreads;
  int threadAmount;
  int step;
  int begVec;
  int endVec;
  int tasksVecSize;

  std::thread *calculationThreads;
  std::vector<std::string> linesVector;
  std::vector<singleTask> tasksDataVec;
};

#endif //THREADPOOL_H