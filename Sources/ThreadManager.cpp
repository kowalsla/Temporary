#include "../Headers/ThreadManager.h"

void ThreadManager::calculateSingleTask(singleTask &taskToCalculate)
{
    LARGE_INTEGER start_fun, end_fun, frequency; // flags - start and end of function
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_fun);
    AllTasks newTask(taskToCalculate);
    if (NO_ERR == newTask.executeTask(taskToCalculate.result)) //execute every task line by line, save result to singleTask struct
    {
        taskToCalculate.errorFlag = true;
    }
    else
    {
        taskToCalculate.errorFlag = false;
    }
    QueryPerformanceCounter(&end_fun);
    taskToCalculate.timeMS = static_cast<double>(end_fun.QuadPart - start_fun.QuadPart) / (frequency.QuadPart / 1000.0); // in ms
}

void ThreadManager::threadCalculateTasks(std::vector<singleTask> *vectorOfTasks, const int &vecSize, int begin, int end)
{
    if (begin > vecSize)
    {
        begin = vecSize;
    }
    if (end > vecSize)
    {
        end = vecSize;
    }
    for (int i = begin; i <= end; ++i)
    {
        this->calculateSingleTask((*vectorOfTasks)[i]);
    }
}

ThreadManager::ThreadManager(const FileManager &newFmObject) : fmObject(newFmObject), step(0), begVec(0), endVec(0), tasksVecSize(0)
{
    additionalThreads = fmObject.getThreadAmount();
    threadAmount = 1 + additionalThreads;         // one thread + additional amount from config file
    linesVector = fmObject.getlinesVector();      // saves every line from file in string vector
    tasksDataVec = fmObject.getTasksDataVector(); //this vector holds all the data needed by task
    tasksVecSize = tasksDataVec.size();
    calculationThreads = new std::thread[threadAmount];
}

void ThreadManager::init()
{
    if (threadAmount > tasksVecSize) // if there is more threads than
    {
        threadAmount = tasksVecSize;
    }

    if (tasksVecSize % threadAmount)
    {
        step = tasksVecSize / threadAmount;
    }
    else
    {
        step = tasksVecSize / threadAmount - 1;
    }
    begVec = 0, endVec = step;
}

void ThreadManager::startThreads()
{
    for (int i = 0; i < threadAmount; ++i)
    {
        calculationThreads[i] = std::thread(&ThreadManager::threadCalculateTasks, this, &tasksDataVec, tasksVecSize - 1, begVec, endVec);
        begVec = endVec + 1;
        endVec = begVec + step;
    }
}

void ThreadManager::joinThreads()
{
    for (int i = 0; i < threadAmount; ++i)
    {
        calculationThreads[i].join();
    }
}

ThreadManager::~ThreadManager()
{
    delete calculationThreads;
}

std::vector<singleTask> ThreadManager::getCalculatedTasks()
{
    return tasksDataVec;
}
