#include "../Headers/MainApp.h"

MainApp::MainApp(const std::string &inputFileName) : fmObject(inputFileName), additionalThreads(0)
{
}

void MainApp::init()
{
    if (NO_ERR == fmObject.readFromFile())
    {
        int additionalThreads;
        fmObject.readConfig(additionalThreads);                         // read config to get amount of threads
        this->taskStringVector = fmObject.getlinesVector();             // saves every line from file in string vector
        this->allDataNeededToRunTask = fmObject.getSingleTasksVector(); //this vector holds all the data needed by task
    }
    else
    {
        std::cout << "Couldn't open the file!" << std::endl;
    }
}