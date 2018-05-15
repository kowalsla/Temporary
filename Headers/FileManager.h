#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Common.h"

class FileManager
{
public:
  FileManager(const std::string &inputFilePath, const std::string &outputFilePath);
  std::vector<std::string> getTasksVector();
  errorCode_t readFromFile();
  errorCode_t saveToFile(const std::string &lineToSave);
  ~FileManager();

private:
  DISABLE_DEFAULT_CONSTUCTORS(FileManager);
  std::string inputFile;
  std::string outputFile;
  std::vector<std::string> tasksVector; // this vector is used to keep lines from file, which are later processed by TaskManager
};

#endif //FILEMANAGER_H