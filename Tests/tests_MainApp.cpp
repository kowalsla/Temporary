#include "../Headers/MainApp.h"
#include "../Headers/AllTasks.h"
using namespace std;
/**
 *  param[in] argc should be eq to 3 - name of program, input.txt, output.txt 
 *  argv[] should be : argv[0] == "./name", argv[1] == "input.txt", argv[2] == "output.txt"
*/
void callFromThread()
{
    cout << "kek";
}
int main(int argc, char *argv[]) // temporary functionality here, it should be moved to MainApp.cpp soon
{
    thread t1(callFromThread);
    t1.join();
    if (argc != 3)
    {
        cout << "Wrong amount of parameters. Example command: './exec input.txt output.txt' " << endl;
        return -1;
    }
    LARGE_INTEGER start, end;         // flags -start and end of program
    LARGE_INTEGER start_fun, end_fun; // flags - start and end of function
    QueryPerformanceCounter(&start);

    FileManager fmObject(argv[1], argv[2]);
    TaskManager tmObject(fmObject);
    vector<string> tasks = fmObject.getTasksVector();

    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    double interval;
    /*   for (unsigned int i = 0; i < tasks.size(); ++i)
    {

        if (NO_ERR == tmObject.extractTask(tasks[i]))
        {
            cout << tasks[i] << "==>";
            cout << tmObject.getResult();

            cout << "==>" << interval << endl;
            fmObject.saveToFile("test");
        }
        else
        {
            cout << "Error at line " << i + 1 << " in txt file with input data" << endl;
        }
    }*/

    vector<singleTask> allDataNeededToRunTask;
    for (unsigned int i = 0; i < tasks.size(); ++i)
    {
        tmObject.saveToStruct(tasks[i]);
        allDataNeededToRunTask.push_back(tmObject.getSingleTaskStruct());
    }

    int result;

    for (unsigned int i = 0; i < tasks.size(); ++i)
    {
        QueryPerformanceCounter(&start_fun);
        AllTasks newTask(allDataNeededToRunTask[i]);
        if (NO_ERR == newTask.executeTask(result))
        {
            std::cout << "Line: " << i + 1 << " Result: " << result;
        }
        else
        {
            cout << "Error at line " << i + 1 << " in txt file with input data. ";
        }
        QueryPerformanceCounter(&end_fun);
        interval = static_cast<double>(end_fun.QuadPart - start_fun.QuadPart) / (frequency.QuadPart / 1000.0); // in ms
        cout << " Time: " << interval << endl;
    }

    QueryPerformanceCounter(&end);
    interval = static_cast<double>(end.QuadPart - start.QuadPart) / (frequency.QuadPart / 1000.0); // result in ms
    std::cout << "\nTotal time: " << interval << "ms" << endl;

    return 0;
}
