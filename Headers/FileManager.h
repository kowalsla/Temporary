#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Common.h"

class FileManager
{
public:
  FileManager(const std::string &inputFilePath, const std::string &outputFilePath);
  explicit FileManager(const std::string &configFilePath);
  std::vector<std::string> getTasksVector();
  errorCode_t readFromFile();
  errorCode_t saveToFile(const std::string &lineToSave);
  errorCode_t readConfig();
  ~FileManager();

private:
  DISABLE_DEFAULT_CONSTUCTORS(FileManager);
  std::string inputFile;
  std::string outputFile;
  std::string configFile;
  std::vector<std::string> tasksVector; // this vector is used to store lines from file, which are later processed by TaskManager
};

#endif //FILEMANAGER_H