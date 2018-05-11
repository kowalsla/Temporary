#include "../Headers/FileManager.h"
FileManager::~FileManager() {}

FileManager::FileManager(std::string fileName)
{
    inputFile = fileName;
}

void FileManager::readFile()
{
    std::string line;
    std::ifstream newFile(inputFile);
    std::cout << inputFile << " <<\n";
    if (newFile.is_open())
    {
        while (getline(newFile, line))
        {
            std::cout << line << std::endl;
        }
        newFile.close();
    }
}