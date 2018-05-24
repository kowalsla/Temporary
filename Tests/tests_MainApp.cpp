#include "../Headers/MainApp.h"
#include "../Headers/AllTasks.h"

using namespace std;

void calculateSingleTask(singleTask &taskToCalculate)
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
    LARGE_INTEGER start, end;              // flags -start and end of program
    QueryPerformanceCounter(&start);       //time measurment
    LARGE_INTEGER frequency;               //time measurment
    QueryPerformanceFrequency(&frequency); //time measurment
    double interval;                       //time measurment

    string inputFileName;
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
    MainApp mainAppObject(inputFileName);

    FileManager fmObject(inputFileName);
    fmObject.readFromFile();
    int additionalThreads;
    fmObject.readConfig(additionalThreads); // read config to get amount of threads

    vector<string> taskStringVector = fmObject.getlinesVector(); // saves every line from file in string vector

    vector<singleTask> allDataNeededToRunTask = fmObject.getSingleTasksVector(); //this vector holds all the data needed by task

    int threadAmount = 1 + additionalThreads; // one thread + additional amount from config file
    int tasksVecSize = allDataNeededToRunTask.size();

    while (threadAmount > tasksVecSize)
    {
        threadAmount = tasksVecSize;
    }

    int step;

    if (tasksVecSize % threadAmount)
    {
        step = tasksVecSize / threadAmount;
    }
    else
    {
        step = tasksVecSize / threadAmount - 1;
    }

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
        if (allDataNeededToRunTask[i].errorFlag == false)
        {
            cout << "Error at line " << i + 1 << " in txt file"
                 << " ==> " << allDataNeededToRunTask[i].timeMS << endl;
        }
        else
        {
            cout << taskStringVector[i] << " ==> " << allDataNeededToRunTask[i].result << " ==> " << allDataNeededToRunTask[i].timeMS << endl;
        }
    }

    QueryPerformanceCounter(&end);
    interval = static_cast<double>(end.QuadPart - start.QuadPart) / (frequency.QuadPart / 1000.0); // result in ms
    std::cout << "\nTotal time: " << interval << "ms" << endl;

    return 0;
}
