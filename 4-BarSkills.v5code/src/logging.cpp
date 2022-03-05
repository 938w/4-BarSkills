
#include "vex.h"
#include "robot-config.h"

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "logging.h"

// get ofstrem
std::ofstream ofs;

void Logger::log(std::string msg) {
  Brain.Screen.print(msg.c_str());

  // later to save to SD card
}