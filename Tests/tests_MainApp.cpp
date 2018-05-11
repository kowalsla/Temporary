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
    FileManager obj(argv[1]);
    cout << argv[1];
    obj.readFile();
    return 0;
}