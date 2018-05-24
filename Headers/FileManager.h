#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Common.h"

class FileManager
{
public:
  explicit FileManager(const std::string &inputFilePath);
  std::vector<std::string> getlinesVector();
  std::vector<singleTask> getSingleTasksVector();
  errorCode_t readFromFile();

  errorCode_t readConfig(int &retThreadAmount);
  singleTask getSingleTaskStruct();

  ~FileManager();
  //errorCode_t saveToFile(const std::string &lineToSave);
private:
  DISABLE_DEFAULT_CONSTUCTORS(FileManager);
  void saveToStruct(const std::string &line);
  std::string inputFile;
  std::string configFile;
  singleTask singleTaskStructObject;    // singleTask struct obj
  std::vector<std::string> linesVector; // this vector is used to store lines from filetasks
  std::vector<singleTask> singleTasksVector;
};

#endif //FILEMANAGER_H