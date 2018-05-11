#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "Common.h"
class TaskManager
{
  private:
    TaskManager() = delete;                               //define constructor as private to disable creating object without arguments
    TaskManager(const TaskManager &) = delete;            //disable default copy constructor
    TaskManager &operator=(const TaskManager &) = delete; //disable default assignment operator
    TaskManager(TaskManager &&) = delete;                 //disable default move operator
    TaskManager &operator=(TaskManager &&) = delete;      //disable default move operators

  public:
    TaskManager(operations_t newTask, std::vector<int> parameters);
};

#endif //TASK_MANAGER_H