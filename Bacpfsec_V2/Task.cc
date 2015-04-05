/**
 * @file   Task.cc
 * @Author Bacpfsec Rick
 * @date   20150405
 * @brief  Implementation for Task Class
 *
 * Task Class for actual recording of one task
 */
#include "Task.h"

Task::Task() :
  taskName("Empty Task"), status(0) {}

Task::Task(std::string tn, const std::vector<State>& st, int s) :
  taskName(tn), states(st), status(s) {}

Task::Task(const Task& t) :
  taskName(t.taskName), states(t.states), status(t.status) {}

Task::~Task() {
  states.clear();
}

void Task::setStates(const std::vector<State>& sts) {
  states = sts;
}

std::vector<State>& Task::getStates() {
  return states;
}

void Task::setTaskName(std::string s) {
  taskName = s;
}

std::string Task::getTaskName() {
  return taskName;
}

void Task::setStatus(int f) {
  status = f;
}

int Task::getStatus() {
  return status;
}
