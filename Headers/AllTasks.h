#ifndef ALLTASKS_H
#define ALLTASKS_H

#include "TaskManager.h"

class AllTasks
{
  public:
    ~AllTasks() {}
    explicit AllTasks(singleTask &incommingTask);

  private:
    inline void checkParam(int paramCount, int expectedParamCount, errorCode_t &flag);
    std::vector<int> parameters;
    int paramCount;
    operations_t taskID;
    DISABLE_DEFAULT_CONSTUCTORS(AllTasks);
    errorCode_t executeTask(operations_t taskID, int &inputVal); // function executes tasks, used by extractTask(const string&) function

    void computeSUM(int &inputVal);            //this function should not return any error, unless completely corrupted arguments are used
    void computeMULTIPLICATION(int &inputVal); //this function should not return any error, unless completely corrupted arguments are used
    errorCode_t computeXOR(int &inputVal);
    errorCode_t computePOWER(int &inputVal); //Exponentiation by squaring used, more effective than function pow() from cmath library
    errorCode_t computeFACTORIAL(int &inputVal);
    errorCode_t computeFIBONACCI(int &inputVal);
    errorCode_t computeGCD(int &inputVal);
    errorCode_t computeNTH_PRIME_NUMBER(int &inputVal);
    errorCode_t computeHIGHEST_PRIME_NUMBER_LT_PARAM(int &inputVal);
    errorCode_t computeDISTANCE_AXIS(int &inputVal);
    errorCode_t computeCOUNT_BINARY_ONES(int &inputVal);
    errorCode_t computeCHECKSUM(int &inputVal);
};

#endif //ALLTASKS_H