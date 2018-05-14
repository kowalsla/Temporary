#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Common.h"

class FileManager
{
public:
  FileManager(const std::string file);
  std::vector<std::string> getTasksVector();
  errorCode_t readFile();
  errorCode_t saveToFile();
  ~FileManager();

private:
  DISABLE_DEFAULT_CONSTUCTORS(FileManager);
  std::string inputFile;
  std::vector<std::string> tasksVector; // this vector is used to keep lines from file, which are later processed by TaskManager
};

#endif //FILEMANAGER_H