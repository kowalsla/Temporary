#include "../Headers/FileManager.h"
FileManager::~FileManager() {}

FileManager::FileManager(const std::string &inputFilePath, const std::string &outputFilePath) : inputFile(inputFilePath), outputFile(outputFilePath), configFile("")
{
}
FileManager::FileManager(const std::string &configFilePath) : inputFile(""), outputFile(""), configFile(configFilePath)
{
}

errorCode_t FileManager::readConfig()
{

}
errorCode_t FileManager::readFromFile()
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

errorCode_t FileManager::saveToFile(const std::string &lineToSave)
{
    errorCode_t retFlag = NO_ERR;
    bool wasFileOpenedFlag = false;
    std::ofstream newFile;
    newFile.open(outputFile, std::ios_base::app);
    if (newFile.is_open())
    {
        wasFileOpenedFlag = true;
        newFile << lineToSave << "\n";
    }
    newFile.close();
    if (false == wasFileOpenedFlag)
    {
        retFlag = FILE_SAVE_ERR;
    }
    return retFlag;
}

std::vector<std::string> FileManager::getTasksVector()
{
    return tasksVector;
}
