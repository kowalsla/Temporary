#include "../Headers/MainApp.h"
#include "../Headers/FileManager.h"
#include "../Headers/TaskManager.h"

using namespace std;
/**
 *  param[in] argc should be eq to 3 - name of program, input.txt, output.txt 
 *  argv[] should be : argv[0] == "./name", argv[1] == "input.txt", argv[2] == "output.txt"
*/
int main(int argc, char *argv[]) // temporary functionality here, it should be moved to MainApp.cpp soon
{
    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start);
    if (argc != 3)
    {
        cout << "Wrong amount of parameters. Example command: './exec input.txt output.txt' " << endl;
        return -1;
    }
    FileManager fmObject(argv[1], argv[2]);

    TaskManager tmObject(fmObject);
    vector<string> tasks = fmObject.getTasksVector();

    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    LARGE_INTEGER start_fun;
    LARGE_INTEGER end_fun;
    double interval;
    for (unsigned int i = 0; i < tasks.size(); ++i)
    {
        QueryPerformanceCounter(&start_fun);
        if (NO_ERR == tmObject.extractTask(tasks[i]))
        {
            cout << tasks[i] << "==>";
            cout << tmObject.getResult();
            QueryPerformanceCounter(&end_fun);
            interval = static_cast<double>(end_fun.QuadPart - start_fun.QuadPart) / (frequency.QuadPart / 1000.0); // in ms
            cout << "==>" << interval << endl;
            fmObject.saveToFile("test");
        }
        else
        {
            cout << "Error at line " << i + 1 << " in txt file with input data" << endl;
        }
    }

    QueryPerformanceCounter(&end);
    interval = static_cast<double>(end.QuadPart - start.QuadPart) / (frequency.QuadPart / 1000.0); // in ms
    std::cout << "\nTotal time: " << interval << "ms" << endl;

    return 0;
}