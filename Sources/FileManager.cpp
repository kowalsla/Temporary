#include "../Headers/FileManager.h"
FileManager::~FileManager() {}

FileManager::FileManager(std::string fileName)
{
    inputFile = fileName;
}

errorCode_t FileManager::readFile()
{
    errorCode_t retFlag = NO_ERR;
    bool wasFileOpenedFlag = false; // flag used to check if file opened correctly
    std::string line;
    std::ifstream newFile(inputFile);
    if (newFile.is_open())
    {
        wasFileOpenedFlag = true;
        while (getline(newFile, line))
        {
            tasksVector.push_back(line);
        }
        newFile.close();
    }
    if (false == wasFileOpenedFlag)
    {
        retFlag = FILE_READ_ERR;
    }
    return retFlag;
}

errorCode_t FileManager::saveToFile()
{
    return NO_ERR;
}

std::vector<std::string> FileManager::getTasksVector()
{
    return tasksVector;
}
