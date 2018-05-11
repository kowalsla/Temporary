#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Common.h"

class FileManager
{
private:
  FileManager() = delete;                               // define constructor as private to disable creating object without arguments
  FileManager(const FileManager &) = delete;            //disable default copy constructor
  FileManager &operator=(const FileManager &) = delete; //disable default assignment operator
  FileManager(FileManager &&) = delete;                 //disable default move operator
  FileManager &operator=(FileManager &&) = delete;      //disable default move operators

  std::string inputFile;
  operations_t taskNo;         // number of task
  std::vector<int> parameters; // parameters

public:
  FileManager(std::string file);
  void readFile();
  ~FileManager();
};

#endif //FILEMANAGER_H