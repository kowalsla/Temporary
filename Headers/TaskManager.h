#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "FileManager.h"

class TaskManager
{
public:
  TaskManager(FileManager &fileManagerObject);
  errorCode_t extractTask(std::string line);
  errorCode_t executeTask();

  void computeSUM();            //this function should not return any error, unless completely corrupted arguments are used
  void computeMULTIPLICATION(); //this function should not return any error, unless completely corrupted arguments are used
  errorCode_t computeXOR();
  errorCode_t computePOWER();
  errorCode_t computeFACTORIAL();
  errorCode_t computeFIBONACCI();
  errorCode_t computeGCD();
  errorCode_t computeFIRST_PRIME_NUMBER();
  errorCode_t computeHIGHEST_PRIME_NUMBER_LT_PARAM();
  errorCode_t computeDISTANCE_AXIS();
  errorCode_t computeCOUNT_BINARY_ONES();
  errorCode_t computeCHECKSUM();
  ~TaskManager();

private:
  DISABLE_DEFAULT_CONSTUCTORS(TaskManager);

  FileManager &fileManagerObject; //object of FileManager class, used to get tasks
  operations_t taskID;            //ID of a task
  std::vector<int> parameters;    //vector of parameters
  int param_count;                //amount of parameters
};

#endif //TASK_MANAGER_H