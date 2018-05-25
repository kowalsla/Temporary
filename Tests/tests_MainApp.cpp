#include "../Headers/ThreadManager.h"

using namespace std;

int main(int argc, char *argv[])
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

    FileManager fmObject(inputFileName);

    if (NO_ERR != fmObject.readFromFile())
    {
        cout << "Cant open file! Abort." << endl;
        exit(1);
    }

    fmObject.readConfig(); // read config to get amount of threads

    //start new threads (minimum 1 will start + additional from config.txt)

    ThreadManager threadMgrObj(fmObject); //create thread
    threadMgrObj.init();                  //initialize data
    threadMgrObj.startThreads();          //start threads which take care of calculating tasks
    threadMgrObj.joinThreads();           //join threads

    /*print results*/

    int tasksVecSize = fmObject.getTasksDataVector().size();
    vector<singleTask> calculatedTasks = threadMgrObj.getCalculatedTasks();

    for (int i = 0; i < tasksVecSize; ++i)
    {
        if (calculatedTasks[i].errorFlag == false)
        {
            cout << "Error at line " << i + 1 << " in txt file"
                 << " ==> " << calculatedTasks[i].timeMS << endl;
        }
        else
        {
            cout << fmObject.getlinesVector()[i] << " ==> " << calculatedTasks[i].result << " ==> " << calculatedTasks[i].timeMS << endl;
        }
    }

    QueryPerformanceCounter(&end);
    interval = static_cast<double>(end.QuadPart - start.QuadPart) / (frequency.QuadPart / 1000.0); // result in ms
    std::cout << "\nTotal time: " << interval << "ms" << endl;

    return 0;
}
