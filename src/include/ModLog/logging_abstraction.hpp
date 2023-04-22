#ifndef __MODLOG_LOGGING_ABSTRACTION_HPP__
#define __MODLOG_LOGGING_ABSTRACTION_HPP__

#include <string>
#include <sstream>
#include "basic_logger_ct.hpp"

namespace ModLog
{
  template<typename T>
  class ModLoggerCT
  {
  public:
    T config {};
  public:
    template<typename... Args>
    inline void crit(const Args&... args)
    {
      config.crit(args...);
    }
    template<typename... Args>
    inline void error(const Args&... args)
    {
      config.error(args...);
    }
    template<typename... Args>
    inline void warn(const Args&... args)
    {
      config.warn(args...);
    }
    template<typename... Args>
    inline void info(const Args&... args)
    {
      config.info(args...);
    }
    template<typename... Args>
    inline void debug(const Args&... args)
    {
      config.debug(args...);
    }
  };

#ifndef MODLOG_CUSTOM_LOGGER
  static ModLoggerCT<BasicCTConfig> logger {};
#else
  using logger = MODLOG_CUSTOM_LOGGER;
#endif // MODLOG_CUSTOM_LOGGER
}

#endif /* end of include guard: __MODLOG_LOGGING_ABSTRACTION_HPP__ */
