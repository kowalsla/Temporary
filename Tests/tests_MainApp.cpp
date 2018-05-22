#include "../Headers/MainApp.h"
#include "../Headers/AllTasks.h"
using namespace std;

/**/

int main(int argc, char *argv[]) // temporary functionality here, it should be moved to MainApp.cpp soon
{
    LARGE_INTEGER start, end;         // flags -start and end of program
    LARGE_INTEGER start_fun, end_fun; // flags - start and end of function
    QueryPerformanceCounter(&start);

    std::string inputFileName;
    cin >> inputFileName;
    //cout << "test: " << test << "\n";
    FileManager fmObject(inputFileName);

    int amountOfThreads;
    fmObject.readConfig(amountOfThreads); // read config to get amount of tasks

    TaskManager tmObject(fmObject);
    vector<string> tasks = fmObject.getTasksVector(); // saves every line from file in vector

    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    double interval;

    vector<singleTask> allDataNeededToRunTask; //this vector holds all the data needed by task
    for (unsigned int i = 0; i < tasks.size(); ++i)
    {
        tmObject.saveToStruct(tasks[i]);                                  //this parses string and saves needed data to struct
        allDataNeededToRunTask.push_back(tmObject.getSingleTaskStruct()); //and this adds it to vector
    }

    int resultHolder;

    for (unsigned int i = 0; i < tasks.size(); ++i)
    {
        QueryPerformanceCounter(&start_fun);
        AllTasks newTask(allDataNeededToRunTask[i]);
        if (NO_ERR == newTask.executeTask(resultHolder)) //execute every task line by line, passes resultHolder by reference, then function saves result to resultHolder
        {
            cout << tasks[i] << " ==> " << resultHolder;
        }
        else
        {
            cout << "Error at line " << i + 1 << " in txt file with input data";
        }
        QueryPerformanceCounter(&end_fun);
        interval = static_cast<double>(end_fun.QuadPart - start_fun.QuadPart) / (frequency.QuadPart / 1000.0); // in ms
        cout << " ==> " << interval << endl;
    }

    QueryPerformanceCounter(&end);
    interval = static_cast<double>(end.QuadPart - start.QuadPart) / (frequency.QuadPart / 1000.0); // result in ms
    std::cout << "\nTotal time: " << interval << "ms" << endl;

    return 0;
}
