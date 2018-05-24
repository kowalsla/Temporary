#include "../Headers/FileManager.h"
FileManager::~FileManager() {}

FileManager::FileManager(const std::string &inputFilePath) : threadAmount(0), inputFile(inputFilePath), configFile(CONFIG_FILE_PATH)
{
}

errorCode_t FileManager::readConfig()
{
    errorCode_t retError = NO_ERR;
    bool wasFileOpenedFlag = false; //flag used to check if file opened correctly
    std::string line;
    std::ifstream newFile(configFile);
    int temp; //temporary value to store amount of threads extracted from file
    if (newFile.is_open())
    {
        wasFileOpenedFlag = true;
        for (int i = 1; i <= 4; ++i)
        {
            getline(newFile, line);
        }
        std::stringstream stream(line);
        while (1)
        {
            stream >> temp;
            if (!stream)
            {
                break;
            }
        }
        newFile.close();
    }
    if (false == wasFileOpenedFlag)
    {
        retError = CONFIG_FILE_READ_ERR;
    }
    else
    {
        threadAmount = temp;
    }
    return retError;
}

errorCode_t FileManager::readFromFile()
{
    errorCode_t retError = NO_ERR;
    bool wasFileOpenedFlag = false; // flag used to check if file opened correctly
    std::string line;
    std::ifstream newFile(inputFile);
    if (newFile.is_open())
    {
        wasFileOpenedFlag = true;
        while (getline(newFile, line))
        {
            linesVector.push_back(line);
            this->saveToStruct(line);
        }
        newFile.close();
    }
    if (false == wasFileOpenedFlag)
    {
        retError = FILE_READ_ERR;
    }

    return retError;
}

void FileManager::saveToStruct(const std::string &line)
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
    this->tasksDataVector.push_back(singleTaskStructObject);
}

std::vector<std::string> FileManager::getlinesVector()
{
    return linesVector;
}

singleTask FileManager::getSingleTaskStruct()
{
    return singleTaskStructObject;
}

std::vector<singleTask> FileManager::getTasksDataVector()
{
    return tasksDataVector;
}

FileManager::FileManager(const FileManager &orig) : threadAmount(orig.threadAmount), linesVector(orig.linesVector), tasksDataVector(orig.tasksDataVector)
{
}

int FileManager::getThreadAmount()
{
    return threadAmount;
}