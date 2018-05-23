#ifndef MAINAPP_H // target : move functionality from main.cpp to this class
#define MAINAPP_H

#include "Common.h"
#include "FileManager.h"
#include "AllTasks.h"

class MainApp
{
private:
  DISABLE_DEFAULT_CONSTUCTORS(MainApp);
  FileManager fmObject;
  int additionalThreads;
  std::vector<std::string> taskStringVector;
  std::vector<singleTask> allDataNeededToRunTask;

public:
  explicit MainApp(const std::string &inputFileName);

  ~MainApp();
};

#endif //MAINAPP_H