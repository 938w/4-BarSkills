
#include <fstream>
#include "vex.h"

class Logger {
private:
  std::string _loggerName;
  std::string _loggerFilename;
  std::ofstream ofs;
  timer _timer;

public:
  Logger(std::string loggerName);
  ~Logger();
  void log(std::string msg);
};