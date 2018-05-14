#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Common.h"

class FileManager
{
private:
  FileManager() = delete;                               //define constructor as private to disable creating object without arguments
  FileManager(const FileManager &) = delete;            //disable default copy constructor
  FileManager &operator=(const FileManager &) = delete; //disable default assignment operator
  FileManager(FileManager &&) = delete;                 //disable default move copy operator
  FileManager &operator=(FileManager &&) = delete;      //disable default move assignment operator

  std::string inputFile;
  std::vector<std::string> tasksVector; // this vector is used to keep lines from file, which are later processed by TaskManager

public:
  FileManager(const std::string file);
  std::vector<std::string> getTasksVector();
  errorCode_t readFile();
  errorCode_t saveToFile();
  ~FileManager();
};

#endif //FILEMANAGER_H