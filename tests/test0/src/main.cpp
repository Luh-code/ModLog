#include "ModLog/logging_abstraction.hpp"

int main()
{
  ModLog::logger.crit("Hello World through ModLog!");
  ModLog::logger.error("Hello World through ModLog!");
  ModLog::logger.warn("Hello World through ModLog!");
  ModLog::logger.info("Hello World through ModLog!");
  ModLog::logger.debug("Hello World through ModLog!");
}
