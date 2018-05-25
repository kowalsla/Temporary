#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Common.h"

class FileManager
{
public:
  explicit FileManager(const std::string &inputFilePath);
  FileManager(const FileManager &orig);
  std::vector<std::string> getlinesVector();
  std::vector<singleTask> getTasksDataVector();
  errorCode_t readFromFile();

  //errorCode_t saveToFile(const std::string &lineToSave);
  errorCode_t readConfig();
  singleTask getSingleTaskStruct();
  int getThreadAmount();
  ~FileManager();

  //errorCode_t saveToFile(const std::string &lineToSave);
private:
  DISABLE_DEFAULT_CONSTUCTORS(FileManager);

  int additionalThreads;
  std::string inputFile;
  std::string configFile;
  singleTask singleTaskStructObject;    // singleTask struct obj
  std::vector<std::string> linesVector; // this vector is used to store lines from filetasks
  std::vector<singleTask> tasksDataVector;
  void saveToStruct(const std::string &line);
};

#endif //FILEMANAGER_H