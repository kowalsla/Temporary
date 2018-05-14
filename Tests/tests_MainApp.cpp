#include "../Headers/MainApp.h"
#include "../Headers/FileManager.h"
#include "../Headers/TaskManager.h"

using namespace std;
/**
 *  param[in] argc should be eq to 3 - name of program, input.txt, output.txt 
 *  argv[] should be : argv[0] == "./name", argv[1] == "input.txt", argv[2] == "output.txt"
*/
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Wrong amount of parameters. Example command: './exec input.txt output.txt' " << endl;
        return -1;
    }
    FileManager fmObject(argv[1]);

    TaskManager tmObject(fmObject);
    vector<string> tasks = fmObject.getTasksVector();
    
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);
    
    for (unsigned int i = 0; i < tasks.size(); ++i)
    {

        tmObject.extractTask(tasks[i]);
    }

    LARGE_INTEGER end;
    QueryPerformanceCounter(&end);

    // for microseconds use 1000000.0
    double interval = static_cast<double>(end.QuadPart- start.QuadPart) / 
                      frequency.QuadPart; // in seconds
    std::cout << interval;
    return 0;
}