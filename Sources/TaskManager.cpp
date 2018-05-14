#include "../Headers/TaskManager.h"

TaskManager::TaskManager(FileManager &fileManagerObject) : fileManagerObject(fileManagerObject), taskID(START), parameters(0), param_count(0)
{
    fileManagerObject.readFile();
}

TaskManager::~TaskManager() {}
int TaskManager::getResult()
{
    return result;
}

errorCode_t TaskManager::extractTask(std::string line)
{
    std::stringstream stream(line);
    int iter = 0;
    int n;
    while (1)
    {
        stream >> n;
        if (!stream)
            break;
        if (iter == 0)
        {
            taskID = (operations_t)n;
        }
        else
        {
            parameters.push_back(n);
        }

        ++iter;
    }
    param_count = --iter;
    return executeTask();
}

errorCode_t TaskManager::executeTask()
{
    errorCode_t retFlag = NO_ERR;
    switch (taskID)
    {
    case SUM:
        computeSUM();
        break;
    case MULTIPLICATION:
        computeMULTIPLICATION();
        break;
    case XOR:
        retFlag = computeXOR();
        break;
    case POWER:
        retFlag = computePOWER();
        break;
    case FACTORIAL:
        retFlag = computeFACTORIAL();
        break;
    case FIBONACCI:
        retFlag = computeFIBONACCI();
        break;
    case GCD:
        retFlag = computeGCD();
    case NTH_PRIME_NUMBER:
        retFlag = computeNTH_PRIME_NUMBER();
        break;
    case HIGHEST_PRIME_NUMBER_LT_PARAM:
        retFlag = computeHIGHEST_PRIME_NUMBER_LT_PARAM();
        break;
    case DISTANCE_AXIS:
        retFlag = computeDISTANCE_AXIS();
        break;
    case COUNT_BINARY_ONES:
        retFlag = computeCOUNT_BINARY_ONES();
        break;
    case CHECKSUM:
        retFlag = computeCHECKSUM();
        break;
    default:
        retFlag = INVALID_PARAM;
        break;
    }
    return retFlag;
}

void TaskManager::computeSUM()
{
    int sum = 0;
    for (int i = 0; i < param_count; ++i)
    {
        sum += parameters[i];
    }
    result = sum;
    parameters.clear();
}
void TaskManager::computeMULTIPLICATION()
{
    int product = 0;
    if (param_count > 0)
    {
        product = parameters[0];
        for (int i = 1; i < param_count; ++i)
        {
            product *= parameters[i];
        }
    }
    result = product;
    parameters.clear();
}
errorCode_t TaskManager::computeXOR()
{
    errorCode_t retFlag = NO_ERR;
    if (param_count != 2)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else if ((parameters[0] < 0) || (parameters[1]) < 0)
    {
        retFlag = INVALID_PARAM;
    }
    if (NO_ERR == retFlag)
    {
        result = int(parameters[0] ^ parameters[1]);
    }
    parameters.clear();
    return retFlag;
}

errorCode_t TaskManager::computePOWER()
{
    errorCode_t retFlag = NO_ERR;
    if (param_count != 2)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else if ((parameters[0] < 0) || (parameters[1]) < 0)
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        result = 1;
        for (;;)
        {
            if (parameters[1] & 1)
                result *= parameters[0];
            parameters[1] >>= 1;
            if (!parameters[1])
                break;
            parameters[0] *= parameters[0];
        }
    }
    parameters.clear();
    return retFlag;
}

errorCode_t TaskManager::computeFACTORIAL()
{
    errorCode_t retFlag = NO_ERR;
    if (param_count != 1)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else if (parameters[0] < 0)
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        result = 1;
        for (int i = 1; i <= parameters[0]; ++i)
        {
            result *= i;
        }
    }
    parameters.clear();
    return retFlag;
}

errorCode_t TaskManager::computeFIBONACCI()
{
    errorCode_t retFlag = NO_ERR;
    if (param_count != 1)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else if (parameters[0] < 0)
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        //do smth
    }
    parameters.clear();
    return retFlag;
}
errorCode_t TaskManager::computeGCD()
{
    std::cout << "computeGCD\n";
    errorCode_t retFlag = NO_ERR;
    if (param_count < 2 || param_count > 4)
    {
        std::cout << "ERRR\n";
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else if ((parameters[0] < 0) || (parameters[1] < 0) || (parameters[2] < 0))
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        //do smth
    }
    parameters.clear();
    return retFlag;
}
errorCode_t TaskManager::computeNTH_PRIME_NUMBER()
{
    std::cout << "computeNTH_PRIME_NUMBER \n";
    errorCode_t retFlag = NO_ERR;
    if (param_count != 1)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else if (parameters[0] < 0)
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        if (parameters[0] == 1)
        {
            result = 2;
        }
        //todo
    }
    parameters.clear();
    return retFlag;
}

errorCode_t TaskManager::computeHIGHEST_PRIME_NUMBER_LT_PARAM()
{
    std::cout << "computeHIGHEST_PRIME_NUMBER_LT_PARAM \n";
    errorCode_t retFlag = NO_ERR;
    if (param_count != 1)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        //do smth
    }
    parameters.clear();
    return retFlag;
}

errorCode_t TaskManager::computeDISTANCE_AXIS()
{
    errorCode_t retFlag = NO_ERR;
    if (param_count != 4)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else
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
        result = abs((parameters[0] + parameters[1]) - (parameters[2] + parameters[3]));
    }
    parameters.clear();
    return retFlag;
}

errorCode_t TaskManager::computeCOUNT_BINARY_ONES()
{
    errorCode_t retFlag = NO_ERR;
    if (param_count != 1)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else if (parameters[0] < 0)
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
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
        result = count;
    }
    parameters.clear();
    return retFlag;
}

errorCode_t TaskManager::computeCHECKSUM()
{
    std::cout << "computeCHECKSUM \n";
    errorCode_t retFlag = NO_ERR;
    if (param_count != 1)
    {
        retFlag = WRONG_AMOUNT_PARAM;
    }
    else if (parameters[0] < 0)
    {
        retFlag = INVALID_PARAM;
    }
    else if (NO_ERR == retFlag)
    {
        //todo
    }
    parameters.clear();
    return retFlag;
}
