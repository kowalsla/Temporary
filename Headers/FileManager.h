#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Common.h"

struct singleTask // struct containing everything that is needed by task, and its result after computing
{
  operations_t taskID;
  std::vector<int> parameters;
  int paramCount;
  int result;
  double timeMS;
  bool errorFlag;
};

class FileManager
{
public:
  explicit FileManager(const std::string &inputFilePath);
  std::vector<std::string> getlinesVector();
  std::vector<singleTask> getSingleTasksVector();
  errorCode_t readFromFile();
  errorCode_t readConfig(int &retThreadAmount);
  void saveToStruct(const std::string &line);
  ~FileManager();

  //errorCode_t saveToFile(const std::string &lineToSave);

private:
  DISABLE_DEFAULT_CONSTUCTORS(FileManager);

  std::string inputFile;
  std::string configFile;
  singleTask singleTaskStructObject;    // singleTask struct obj
  std::vector<std::string> linesVector; // this vector is used to store lines from filetasks
  std::vector<singleTask> singleTasksVector;
};

#endif //FILEMANAGER_H