#ifndef __MODLOG_BASIC_LOGGER_CT__
#define __MODLOG_BASIC_LOGGER_CT__

#include <string>
#include <sstream>
#include <cstdarg>
#include <stdint.h>
#include "config.hpp"

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

  struct BasicCTConfig : public ModLoggerConfig
  {
  public:
    inline BasicCTConfig()
    {
      *this | MODLOG_FLAGS::ADD_FORMAT | MODLOG_FLAGS::ADD_DATE;

      *this
        + ColorInfo
        {
          level: WARN_LEVEL::CRIT,
          mode: COLOR_MODE::BOLD,
          #ifdef MODLOG_TRUE_COLOR
          foreground: RGBColor {217, 217, 217},
          background: RGBColor {128, 0, 0}
          #else
          #ifdef MODLOG_HIGH_COLOR_RANGE
          foreground: static_cast<uint8_t>(252),
          background: static_cast<uint8_t>(124)
          #else
          foreground: FOREGROUND_COLOR::WHITE,
          background: BACKGROUND_COLOR::RED
          #endif // MODLOG_HIGH_COLOR_RANGE
          #endif // MODLOG_TRUE_COLOR
        }
        + ColorInfo
        {
          level: WARN_LEVEL::ERROR,
          mode: COLOR_MODE::BOLD,
          #ifdef MODLOG_TRUE_COLOR
          foreground: RGBColor {128, 0, 0},
          background: RGBColor {0, 0, 0}
          #else
          #ifdef MODLOG_HIGH_COLOR_RANGE
          foreground: static_cast<uint8_t>(124),
          background: static_cast<uint8_t>(0)
          #else
          foreground: FOREGROUND_COLOR::RED,
          background: BACKGROUND_COLOR::DEFAULT
          #endif // MODLOG_HIGH_COLOR_RANGE
          #endif // MODLOG_TRUE_COLOR
        }
        + ColorInfo
        {
          level: WARN_LEVEL::WARN,
          mode: COLOR_MODE::NORMAL,
          #ifdef MODLOG_TRUE_COLOR
          foreground: RGBColor {255, 102, 0},
          background: RGBColor {0, 0, 0}
          #else
          #ifdef MODLOG_HIGH_COLOR_RANGE
          foreground: static_cast<uint8_t>(208),
          background: static_cast<uint8_t>(0)
          #else
          foreground: FOREGROUND_COLOR::YELLOW,
          background: BACKGROUND_COLOR::DEFAULT
          #endif // MODLOG_HIGH_COLOR_RANGE
          #endif // MODLOG_TRUE_COLOR
        }
        + ColorInfo
        {
          level: WARN_LEVEL::INFO,
          mode: COLOR_MODE::NORMAL,
          #ifdef MODLOG_TRUE_COLOR
          foreground: RGBColor {217, 217, 217},
          background: RGBColor {0, 0, 0}
          #else
          #ifdef MODLOG_HIGH_COLOR_RANGE
          foreground: static_cast<uint8_t>(252),
          background: static_cast<uint8_t>(0)
          #else
          foreground: FOREGROUND_COLOR::DEFAULT,
          background: BACKGROUND_COLOR::DEFAULT
          #endif // MODLOG_HIGH_COLOR_RANGE
          #endif // MODLOG_TRUE_COLOR
        }
        + ColorInfo
        {
          level: WARN_LEVEL::DEBUG,
          mode: COLOR_MODE::ITALIC,
          #ifdef MODLOG_TRUE_COLOR
          foreground: RGBColor {0, 191, 255},
          background: RGBColor {0, 0, 0}
          #else
          #ifdef MODLOG_HIGH_COLOR_RANGE
          foreground: static_cast<uint8_t>(75),
          background: static_cast<uint8_t>(0)
          #else
          foreground: FOREGROUND_COLOR::BRIGHT_CYAN,
          background: BACKGROUND_COLOR::DEFAULT
          #endif // MODLOG_HIGH_COLOR_RANGE
          #endif // MODLOG_TRUE_COLOR
        }
        + ColorInfo
        {
          level: WARN_LEVEL::TIME,
          mode: COLOR_MODE::ITALIC,
          #ifdef MODLOG_TRUE_COLOR
          foreground: RGBColor {115, 115, 115},
          background: RGBColor {0, 0, 0}
          #else
          #ifdef MODLOG_HIGH_COLOR_RANGE
          foreground: static_cast<uint8_t>(246),
          background: static_cast<uint8_t>(0)
          #else
          foreground: FOREGROUND_COLOR::BRIGHT_BLACK,
          background: BACKGROUND_COLOR::DEFAULT
          #endif // MODLOG_HIGH_COLOR_RANGE
          #endif // MODLOG_TRUE_COLOR
        };
    }

    template<typename... Args>
    inline void crit(Args&&... args)
    {
      this->processCrit(
        [](auto&&... args) { BasicCTLogger::crit(args...); },
        args...
      );
    }
    template<typename... Args>
    inline void error(Args&&... args)
    {
      this->processError(
        [](auto&&... args) { BasicCTLogger::error(args...); },
        args...
      );
    }
    template<typename... Args>
    inline void warn(Args&&... args)
    {
      this->processWarn(
        [](auto&&... args) { BasicCTLogger::warn(args...); },
        args...
      );
    }
    template<typename... Args>
    inline void info(Args&&... args)
    {
      this->processInfo(
        [](auto&&... args) { BasicCTLogger::info(args...); },
        args...
      );
    }
    template<typename... Args>
    inline void debug(Args&&... args)
    {
      this->processDebug(
        [](auto&&... args) { BasicCTLogger::debug(args...); },
        args...
      );
    }
  };


}

#endif /* end of include guard: __MODLOG_BASIC_LOGGER_CT__ */
