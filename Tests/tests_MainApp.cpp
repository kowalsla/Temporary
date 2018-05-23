#include "../Headers/MainApp.h"
#include "../Headers/AllTasks.h"

using namespace std;
std::mutex mutexLock;

void calculateSingleTask(singleTask &taskToCalculate)
{
    LARGE_INTEGER start_fun, end_fun, frequency; // flags - start and end of function
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start_fun);
    AllTasks newTask(taskToCalculate);
    if (NO_ERR == newTask.executeTask((taskToCalculate).result)) //execute every task line by line, save result to singleTask struct
    {
        (taskToCalculate).errorFlag = 0;
    }
    else
    {
        (taskToCalculate).errorFlag = -1;
    }
    QueryPerformanceCounter(&end_fun);
    (taskToCalculate).timeMS = static_cast<double>(end_fun.QuadPart - start_fun.QuadPart) / (frequency.QuadPart / 1000.0); // in ms
}

void threadCalculateTasks(vector<singleTask> *vectorOfTasks, int maxSize, int begin, int end)
{
    if (begin > maxSize)
    {
        begin = maxSize;
    }
    if (end > maxSize)
    {
        end = maxSize;
    }
    for (int i = begin; i <= end; ++i)
    {
        calculateSingleTask((*vectorOfTasks)[i]);
    }
}

int main(int argc, char *argv[]) // temporary functionality here, it should be moved to MainApp.cpp soon
{
    LARGE_INTEGER start, end; // flags -start and end of program

    string inputFileName;
    QueryPerformanceCounter(&start);
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    if (argc == 1)
    {
        cout << "Input file name: \n";
        cin >> inputFileName;
    }
    else if (argc == 2)
    {
        inputFileName = argv[1];
    }
    else
    {
        cout << "Too many arguments! Example: \"./exec.exe tasks.txt > out.txt\"" << endl;
        exit(1);
    }

    FileManager fmObject(inputFileName);
    int additionalThreads;
    fmObject.readConfig(additionalThreads); // read config to get amount of threads

    TaskManager tmObject(fmObject);
    vector<string> taskStringVector = fmObject.getTasksVector(); // saves every line from file in string vector

    double interval;

    vector<singleTask> allDataNeededToRunTask; //this vector holds all the data needed by task

    for (unsigned int i = 0; i < taskStringVector.size(); ++i)
    {
        tmObject.saveToStruct(taskStringVector[i]);                       //this parses string and saves data to singleTask struct
        allDataNeededToRunTask.push_back(tmObject.getSingleTaskStruct()); //and this adds object of singleTask struct to vector
    }

    int threadAmount = 1 + additionalThreads; // one thread + additional amount from config file
    int tasksVecSize = allDataNeededToRunTask.size();

    while (threadAmount > tasksVecSize)
    {
        threadAmount = tasksVecSize;
    }
    cout << "size: " << tasksVecSize << "TR AMNT: " << threadAmount << endl; //debug print
    int step = tasksVecSize / threadAmount;

    std::thread calculationThreads[threadAmount];

    int begVec = 0, endVec = step;

    for (int i = 0; i < threadAmount; ++i)
    {
        calculationThreads[i] = thread(threadCalculateTasks, &allDataNeededToRunTask, tasksVecSize, begVec, endVec);
        begVec = endVec + 1;
        endVec = begVec + step;
    }

    for (int i = 0; i < threadAmount; ++i)
    {
        calculationThreads[i].join();
    }

    for (int i = 0; i < tasksVecSize; ++i)
    {
        cout << "Line: " << i + 1 << " Result = " << allDataNeededToRunTask[i].result << endl;
    }

    QueryPerformanceCounter(&end);
    interval = static_cast<double>(end.QuadPart - start.QuadPart) / (frequency.QuadPart / 1000.0); // result in ms
    std::cout << "\nTotal time: " << interval << "ms" << endl;

    return 0;
}
