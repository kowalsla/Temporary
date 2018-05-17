#include "../Headers/TaskManager.h"

TaskManager::TaskManager(FileManager &fileManagerObject) : fileManagerObject(fileManagerObject)
{
    fileManagerObject.readFromFile();
}

TaskManager::~TaskManager() {}

singleTask TaskManager::getSingleTaskStruct()
{
    return singleTaskStructObject;
}

errorCode_t TaskManager::saveToStruct(const std::string &line)
{
    singleTaskStructObject.parameters.clear();
    std::stringstream stream(line);
    int iter = 0;
    int n;
    while (1)
    {
        stream >> n;
        if (!stream)
        {
            break;
        }
        if (iter == 0) //if iter == 0 it means we are at start of a line, which should be operation ID
        {
            singleTaskStructObject.taskID = static_cast<operations_t>(n);
        }
        else
        {
            singleTaskStructObject.parameters.push_back(n);
        }
        ++iter;
    }
    singleTaskStructObject.paramCount = --iter;
    return NO_ERR;
}