#include "../Headers/AllTasks.h"

inline void AllTasks::checkParam(int paramCount, int expectedParamCount, errorCode_t &flag)
{
    if (paramCount != expectedParamCount)
    {
        flag = WRONG_AMOUNT_PARAM;
    }
    else
    {
        flag = NO_ERR;
    }
}
AllTasks::AllTasks(singleTask incommingTask) : parameters(incommingTask.parameters), paramCount(incommingTask.paramCount), taskID(incommingTask.taskID)
{
}
errorCode_t AllTasks::executeTask(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    switch (taskID)
    {
    case SUM:
        computeSUM(inputVal);
        break;
    case MULTIPLICATION:
        computeMULTIPLICATION(inputVal);
        break;
    case XOR:
        retFlag = computeXOR(inputVal);
        break;
    case POWER:
        retFlag = computePOWER(inputVal);
        break;
    case FACTORIAL:
        retFlag = computeFACTORIAL(inputVal);
        break;
    case FIBONACCI:
        retFlag = computeFIBONACCI(inputVal);
        break;
    case GCD:
        retFlag = computeGCD(inputVal);
        break;
    case NTH_PRIME_NUMBER:
        retFlag = computeNTH_PRIME_NUMBER(inputVal);
        break;
    case HIGHEST_PRIME_NUMBER_LT_PARAM:
        retFlag = computeHIGHEST_PRIME_NUMBER_LT_PARAM(inputVal);
        break;
    case DISTANCE_AXIS:
        retFlag = computeDISTANCE_AXIS(inputVal);
        break;
    case COUNT_BINARY_ONES:
        retFlag = computeCOUNT_BINARY_ONES(inputVal);
        break;
    case CHECKSUM:
        retFlag = computeCHECKSUM(inputVal);
        break;
    default:
        retFlag = INVALID_PARAM;
        break;
    }
    return retFlag;
}

void AllTasks::computeSUM(int &inputVal)
{
    int sum = 0;
    for (int i = 0; i < paramCount; ++i)
    {
        sum += parameters[i];
    }
    inputVal = sum;
}

void AllTasks::computeMULTIPLICATION(int &inputVal)
{
    int product = 0;
    if (paramCount > 0)
    {
        product = parameters[0];
        for (int i = 1; i < paramCount; ++i)
        {
            product *= parameters[i];
        }
    }
    inputVal = product;
}

errorCode_t AllTasks::computeXOR(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    checkParam(paramCount, 2, retFlag);

    if (((parameters[0] < 0) || (parameters[1]) < 0) && (NO_ERR == retFlag))
    {
        retFlag = INVALID_PARAM;
    }
    if (NO_ERR == retFlag)
    {
        inputVal = static_cast<int>(parameters[0] ^ parameters[1]);
    }
    return retFlag;
}

errorCode_t AllTasks::computePOWER(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    checkParam(paramCount, 2, retFlag);

    if (((parameters[0] < 0) || (parameters[1]) < 0) && (NO_ERR == retFlag))
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        inputVal = 1;
        for (;;)
        {
            if (parameters[1] & 1)
            {
                inputVal *= parameters[0];
            }
            parameters[1] >>= 1;
            if (!parameters[1])
            {
                break;
            }
            parameters[0] *= parameters[0];
        }
    }
    return retFlag;
}

errorCode_t AllTasks::computeFACTORIAL(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    checkParam(paramCount, 1, retFlag);

    if ((parameters[0] < 0) && (NO_ERR == retFlag))
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        inputVal = 1;
        for (int i = 1; i <= parameters[0]; ++i)
        {
            inputVal *= i;
        }
    }
    return retFlag;
}

errorCode_t AllTasks::computeFIBONACCI(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    checkParam(paramCount, 1, retFlag);

    if (parameters[0] < 0 && (NO_ERR == retFlag))
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        //do smth
    }
    return retFlag;
}

errorCode_t AllTasks::computeGCD(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    if (paramCount < 2 || paramCount > 4)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else
    {
        for (int i = 0; i < paramCount; ++i)
        {
            if (parameters[i] < 0)
            {
                retFlag = INVALID_PARAM;
            }
        }
    }
    if (NO_ERR == retFlag)
    {
        //do smth
    }
    return retFlag;
}

errorCode_t AllTasks::computeNTH_PRIME_NUMBER(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    checkParam(paramCount, 1, retFlag);

    if ((parameters[0] < 0) && (NO_ERR == retFlag))
    {
        retFlag = INVALID_PARAM;
    }
    if (NO_ERR == retFlag)
    {
        if (parameters[0] == 1)
        {
            inputVal = 2;
        }
        //todo
    }
    return retFlag;
}

errorCode_t AllTasks::computeHIGHEST_PRIME_NUMBER_LT_PARAM(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    checkParam(paramCount, 1, retFlag);
    if (NO_ERR == retFlag)
    {
        //do smth
    }
    return retFlag;
}

errorCode_t AllTasks::computeDISTANCE_AXIS(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    checkParam(paramCount, 2, retFlag);
    if (NO_ERR == retFlag)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (parameters[i] < 0)
            {
                retFlag = INVALID_PARAM;
                break;
            }
        }
    }
    if (NO_ERR == retFlag)
    {
        inputVal = abs((parameters[0] + parameters[1]) - (parameters[2] + parameters[3]));
    }
    return retFlag;
}

errorCode_t AllTasks::computeCOUNT_BINARY_ONES(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    checkParam(paramCount, 1, retFlag);
    if (parameters[0] < 0 && (NO_ERR == retFlag))
    {
        retFlag = INVALID_PARAM;
    }
    if (NO_ERR == retFlag)
    {
        int count = 0;
        parameters[0];
        for (unsigned int i = 0; i < sizeof(int) * 8; ++i)
        {
            if ((parameters[0] >> i) & 1)
            {
                ++count;
            }
        }
        inputVal = count;
    }
    return retFlag;
}

errorCode_t AllTasks::computeCHECKSUM(int &inputVal)
{
    errorCode_t retFlag = NO_ERR;
    checkParam(paramCount, 1, retFlag);
    if (parameters[0] < 0 && (NO_ERR == retFlag))
    {
        retFlag = INVALID_PARAM;
    }
    if (NO_ERR == retFlag)
    {
        //todo
    }
    return retFlag;
}
