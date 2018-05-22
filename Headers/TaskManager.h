#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "FileManager.h"

struct singleTask // struct containing everything that is needed by task
{
  operations_t taskID;
  std::vector<int> parameters;
  int paramCount;
};

class TaskManager
{
public:
  explicit TaskManager(FileManager &fileManagerObject);
  errorCode_t saveToStruct(const std::string &line);
  ~TaskManager();
  singleTask singleTaskStructObject; // singleTask struct obj
  singleTask getSingleTaskStruct();

private:
  DISABLE_DEFAULT_CONSTUCTORS(TaskManager);
  FileManager &fileManagerObject; //object of FileManager class, used to get tasks from file
};

#endif //TASK_MANAGER_H