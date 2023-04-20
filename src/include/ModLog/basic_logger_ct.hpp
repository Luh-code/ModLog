#ifndef __MODLOG_BASIC_LOGGER_CT__
#define __MODLOG_BASIC_LOGGER_CT__

#include <string>
#include <sstream>
#include <cstdarg>
#include <stdint.h>

namespace ModLog
{
  class BasicCTLogger
  {
  public:
    static inline void variadicUnpack(std::string& buf) {}

    template<typename T, typename... Args>
    static inline void variadicUnpack(std::string& buf, const T arg, const Args... args)
    {
      std::ostringstream oss;
      oss << arg;
      buf.append(oss.str());
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::string& buf, void* arg, const Args... args)
    {
      std::ostringstream oss;
      oss << arg;
      buf.append(oss.str());
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::string& buf, char* arg, const Args... args)
    {
      buf.append(arg);
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::string& buf, const char* arg, const Args... args)
    {
      buf.append(arg);
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::string& buf, int32_t arg, const Args... args)
    {
      buf.append(std::to_string(arg));
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::string& buf, uint32_t arg, const Args... args)
    {
      buf.append(std::to_string(arg));
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::string& buf, int64_t arg, const Args... args)
    {
      buf.append(std::to_string(arg));
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::string& buf, uint64_t arg, const Args... args)
    {
      buf.append(std::to_string(arg));
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::string& buf, float arg, const Args... args)
    {
      buf.append(std::to_string(arg));
      variadicUnpack(buf, args...);
    }
    template<typename... Args>
    static inline void variadicUnpack(std::string& buf, double arg, const Args... args)
    {
      buf.append(std::to_string(arg));
      variadicUnpack(buf, args...);
    }

    template<typename... Args>
    static inline void log(std::string level, const Args&... args)
    {
      std::ostringstream oss {};
      oss << "[" << level << "] ";
      std::string buf;
      variadicUnpack(buf, args...);
      oss << buf;

      printf("%s\n", oss.str().c_str());
    }

    template<typename... Args>
    static inline void crit(const Args&... args)
    {
      log("CRIT ", args...);
    }
    template<typename... Args>
    static inline void error(const Args&... args)
    {
      log("ERROR", args...);
    }
    template<typename... Args>
    static inline void warn(const Args&... args)
    {
      log("WARN ", args...);
    }
    template<typename... Args>
    static inline void info(const Args&... args)
    {
      log("INFO ", args...);
    }
    template<typename... Args>
    static inline void debug(const Args&... args)
    {
      log("DEBUG", args...);
    }
  };

  struct BasicCTConfig
  {
  public:
    template<typename... Args>
    static inline void crit(const Args&... args)
    {
      BasicCTLogger::crit(args...);
    }
    template<typename... Args>
    static inline void error(const Args&... args)
    {
      BasicCTLogger::error(args...);
    }
    template<typename... Args>
    static inline void warn(const Args&... args)
    {
      BasicCTLogger::warn(args...);
    }
    template<typename... Args>
    static inline void info(const Args&... args)
    {
      BasicCTLogger::info(args...);
    }
    template<typename... Args>
    static inline void debug(const Args&... args)
    {
      BasicCTLogger::debug(args...);
    }
  };


}

#endif /* end of include guard: __MODLOG_BASIC_LOGGER_CT__ */
