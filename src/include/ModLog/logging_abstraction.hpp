#ifndef __MODLOG_LOGGING_ABSTRACTION_HPP__
#define __MODLOG_LOGGING_ABSTRACTION_HPP__

#include <string>
#include <sstream>
#include "basic_logger_ct.hpp"

namespace ModLog
{
  // using loggingFunction = void(*)(...);

  template<typename T>
  class ModLoggerCT
  {
  public:
    template<typename... Args>
    inline void crit(const Args&... args)
    {
      T::crit(args...);
    }
    template<typename... Args>
    inline void error(const Args&... args)
    {
      T::error(args...);
    }
    template<typename... Args>
    inline void warn(const Args&... args)
    {
      T::warn(args...);
    }
    template<typename... Args>
    inline void info(const Args&... args)
    {
      T::info(args...);
    }
    template<typename... Args>
    inline void debug(const Args&... args)
    {
      T::debug(args...);
    }
  };

  static ModLoggerCT<BasicCTConfig> logger {};
}

#endif /* end of include guard: __MODLOG_LOGGING_ABSTRACTION_HPP__ */
