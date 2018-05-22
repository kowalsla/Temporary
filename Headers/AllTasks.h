#ifndef ALLTASKS_H
#define ALLTASKS_H

#include "TaskManager.h"

class AllTasks
{
public:
  ~AllTasks() {}
  explicit AllTasks(singleTask &incommingTask);
  errorCode_t executeTask(int &retResult); // function executes tasks, used by extractTask(const string&) function

private:
  inline void checkParam(int paramCount, int expectedParamCount, errorCode_t &flag);
  std::vector<int> parameters;
  int paramCount;
  operations_t taskID;
  DISABLE_DEFAULT_CONSTUCTORS(AllTasks);

  void computeSUM(int &retResult);            //this function should not return any error, unless completely corrupted arguments are used
  void computeMULTIPLICATION(int &retResult); //this function should not return any error, unless completely corrupted arguments are used
  errorCode_t computeXOR(int &retResult);
  errorCode_t computePOWER(int &retResult); //Exponentiation by squaring used, more effective than function pow() from cmath library
  errorCode_t computeFACTORIAL(int &retResult);
  errorCode_t computeFIBONACCI(int &retResult);
  errorCode_t computeGCD(int &retResult);
  errorCode_t computeNTH_PRIME_NUMBER(int &retResult);
  errorCode_t computeHIGHEST_PRIME_NUMBER_LT_PARAM(int &retResult);
  errorCode_t computeDISTANCE_AXIS(int &retResult);
  errorCode_t computeCOUNT_BINARY_ONES(int &retResult);
  errorCode_t computeCHECKSUM(int &retResult);

  bool isPrimeNumber(int &val); //additional function which helps with computing prime numbers, used by computeNTH_PRIME_NUMBER and computeHIGHEST_PRIME_NUMBER_LT_PARAM
};

#endif //ALLTASKS_H