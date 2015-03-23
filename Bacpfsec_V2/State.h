/**
 * @file   State.h
 * @Author Rick
 * @date   March, 2015
 * @brief  State class is used within task class
 *
 * State stands for a single snapshot during a task
 */
#ifndef STATE_H
#define STATE_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class State {
public:
  State();
  State(string c, int d);

private:
  string content;
  int date;
};
#endif
