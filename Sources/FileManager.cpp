#include "../Headers/FileManager.h"
FileManager::~FileManager() {}

FileManager::FileManager(const std::string &inputFilePath) : inputFile(inputFilePath), configFile(CONFIG_FILE_PATH)
{
}

errorCode_t FileManager::readConfig(int &retThreadAmount)
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
        retThreadAmount = temp;
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
            tasksVector.push_back(line);
        }
        newFile.close();
    }
    if (false == wasFileOpenedFlag)
    {
        retError = FILE_READ_ERR;
    }
    return retError;
}

/*errorCode_t FileManager::saveToFile(const std::string &lineToSave)
{
    errorCode_t retError = NO_ERR;
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
        retError = FILE_SAVE_ERR;
    }
    return retError;
}
*/
std::vector<std::string> FileManager::getTasksVector()
{
    return tasksVector;
}
