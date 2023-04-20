#include "ModLog/logging_abstraction.hpp"

int main()
{
  ModLog::BasicCTLogger::info("Hello World from CTLogger directly!");
  ModLog::logger.info("Hello World through ModLog!");
}
