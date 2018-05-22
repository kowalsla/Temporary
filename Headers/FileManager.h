#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Common.h"

class FileManager
{
public:
  explicit FileManager(const std::string &inputFilePath);
  std::vector<std::string> getTasksVector();
  errorCode_t readFromFile();
  //errorCode_t saveToFile(const std::string &lineToSave);
  errorCode_t readConfig(int &retThreadAmount);
  ~FileManager();

private:
  DISABLE_DEFAULT_CONSTUCTORS(FileManager);
  std::string inputFile;
  std::string configFile;
  std::vector<std::string> tasksVector; // this vector is used to store lines from file, which are later processed by TaskManager
};

#endif //FILEMANAGER_H