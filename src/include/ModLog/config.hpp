#ifndef __MODLOG_CONFIG_HPP__
#define __MODLOG_CONFIG_HPP__

#include <stdint.h>
#include <string>
#include <string.h>
#include <sstream>
#include <functional>
#include <chrono>
#include <ctime>

namespace ModLog
{
  typedef enum class MODLOG_FLAGS : int32_t
  {
    ADD_FILE_LOGGING = 0x01,
    FILE_LOGGING_WITH_FORMATTING = 0x02,
    ADD_DATE = 0x04,
    DATE_INJECT = 0x08,
    ADD_LEVEL = 0x10,
    LEVEL_INJECT = 0x20,
    ADD_FORMAT = 0x40,
    FORMAT_INJECT = 0x80,
  } MODLOG_FLAGS;
  inline MODLOG_FLAGS operator|(const MODLOG_FLAGS& a, const MODLOG_FLAGS& b)
  {
    return static_cast<MODLOG_FLAGS>(static_cast<int32_t>(a)|static_cast<int32_t>(b));
  }
  inline void operator|=(MODLOG_FLAGS& a, const MODLOG_FLAGS& b)
  {
    a = a | b;
  }
  inline MODLOG_FLAGS operator&(const MODLOG_FLAGS& a, const MODLOG_FLAGS& b)
  {
    return static_cast<MODLOG_FLAGS>(static_cast<int32_t>(a)&static_cast<int32_t>(b));
  }
  inline void operator&=(MODLOG_FLAGS& a, const MODLOG_FLAGS& b)
  {
    a = a | b;
  }

  typedef enum class WARN_LEVEL : int32_t
  {
    DEFAULT = 0x01,
    CRIT = 0x02,
    ERROR = 0x04,
    WARN = 0x08,
    INFO = 0x10,
    DEBUG = 0x20,
    TIME = 0x40,
  } WARN_LEVEL;
  inline WARN_LEVEL operator|(const WARN_LEVEL& a, const WARN_LEVEL& b)
  {
    return static_cast<WARN_LEVEL>(static_cast<int32_t>(a)|static_cast<int32_t>(b));
  }
  inline void operator|=(WARN_LEVEL& a, const WARN_LEVEL& b)
  {
    a = a | b;
  }
  inline WARN_LEVEL operator&(const WARN_LEVEL& a, const WARN_LEVEL& b)
  {
    return static_cast<WARN_LEVEL>(static_cast<int32_t>(a)&static_cast<int32_t>(b));
  }
  inline void operator&=(WARN_LEVEL& a, const WARN_LEVEL& b)
  {
    a = a | b;
  }

  typedef enum class COLOR_MODE : int32_t
  {
    NORMAL = 0x01,
    BOLD = 0x02,
    DIM = 0x04,
    ITALIC = 0x08,
    UNDERLINE = 0x10,
    BLINKING = 0x20,
    INVERSE = 0x40,
    HIDDEN = 0x80,
    STRIKETHROUGH = 0x100,
  } COLOR_MODE;
  inline COLOR_MODE operator|(const COLOR_MODE& a, const COLOR_MODE& b)
  {
    return static_cast<COLOR_MODE>(static_cast<int32_t>(a)|static_cast<int32_t>(b));
  }
  inline void operator|=(COLOR_MODE& a, const COLOR_MODE& b)
  {
    a = a | b;
  }
  inline COLOR_MODE operator&(const COLOR_MODE& a, const COLOR_MODE& b)
  {
    return static_cast<COLOR_MODE>(static_cast<int32_t>(a)&static_cast<int32_t>(b));
  }
  inline void operator&=(COLOR_MODE& a, const COLOR_MODE& b)
  {
    a = a | b;
  }

#ifdef MODLOG_TRUE_COLOR
  typedef struct
  {
  public:
    uint8_t r;
    uint8_t g;
    uint8_t b;
  } RGBColor;
#endif // MODLOG_TRUE_COLOR

#ifdef MODLOG_TRUE_COLOR
  typedef RGBColor FOREGROUND_COLOR;
#else
#ifdef MODLOG_HIGH_COLOR_RANGE
  typedef uint8_t FOREGROUND_COLOR;
#else
  typedef enum class FOREGROUND_COLOR : int32_t
  {
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37,
    DEFAULT = 39,
#ifdef MODLOG_AIXTERM_COMPLIANT
    BRIGHT_BLACK = 90,
    BRIGHT_RED = 91,
    BRIGHT_GREEN = 92,
    BRIGHT_YELLOW = 93,
    BRIGHT_BLUE = 94,
    BRIGHT_MAGENTA = 95,
    BRIGHT_CYAN = 96,
    BRIGHT_WHITE = 97,
#else
    BRIGHT_BLACK = 30,
    BRIGHT_RED = 31,
    BRIGHT_GREEN = 32,
    BRIGHT_YELLOW = 33,
    BRIGHT_BLUE = 34,
    BRIGHT_MAGENTA = 35,
    BRIGHT_CYAN = 36,
    BRIGHT_WHITE = 37,
#endif // AIXTERM_COMPLIANT
  } FOREGROUND_COLOR;
#endif // MODLOG_HIGH_COLOR_RANGE
#endif // MODLOG_TRUE_COLOR

#ifdef MODLOG_TRUE_COLOR
  typedef RGBColor BACKGROUND_COLOR;
#else
#ifdef MODLOG_HIGH_COLOR_RANGE
  typedef uint8_t BACKGROUND_COLOR;
#else
  typedef enum class BACKGROUND_COLOR : int32_t
  {
    BLACK = 40,
    RED = 41,
    GREEN = 42,
    YELLOW = 43,
    BLUE = 44,
    MAGENTA = 45,
    CYAN = 46,
    WHITE = 47,
    DEFAULT = 49,
#ifdef MODLOG_AIXTERM_COMPLIANT
    BRIGHT_BLACK = 100,
    BRIGHT_RED = 101,
    BRIGHT_GREEN = 102,
    BRIGHT_YELLOW = 103,
    BRIGHT_BLUE = 104,
    BRIGHT_MAGENTA = 105,
    BRIGHT_CYAN = 106,
    BRIGHT_WHITE = 107,
#else
    BRIGHT_BLACK = 40,
    BRIGHT_RED = 41,
    BRIGHT_GREEN = 42,
    BRIGHT_YELLOW = 43,
    BRIGHT_BLUE = 44,
    BRIGHT_MAGENTA = 45,
    BRIGHT_CYAN = 46,
    BRIGHT_WHITE = 47,
#endif // MODLOG_AIXTERM_COMPLIANT
  } BACKGROUND_COLOR;
#endif // MODLOG_HIGH_COLOR_RANGE
#endif // MODLOG_TRUE_COLOR

  typedef struct
  {
  public:
    WARN_LEVEL level;
    COLOR_MODE mode;
    FOREGROUND_COLOR foreground;
    BACKGROUND_COLOR background;
  } ColorInfo;

  struct ModLoggerConfig
  {
  public:
    std::string escapeChars = "\x1b[";
    MODLOG_FLAGS flags;
    std::string defFmt;
    std::string critFmt;
    std::string errorFmt;
    std::string warnFmt;
    std::string infoFmt;
    std::string debugFmt;
    std::string timeFmt;
  public:
    inline ModLoggerConfig()
    {
      this->defFmt = escapeChars + "0;39;49m";
      this->critFmt = defFmt;
      this->errorFmt = defFmt;
      this->warnFmt = defFmt;
      this->infoFmt = defFmt;
      this->debugFmt = defFmt;
      this->timeFmt = defFmt;
    }

    inline ModLoggerConfig& operator|(const MODLOG_FLAGS& a)
    {
      this->flags |= a;
      return *this;
    }
    inline void operator|=(const MODLOG_FLAGS& a)
    {
      *this = *this | a;
    }
    inline ModLoggerConfig& operator+(const ColorInfo& col)
    {
      std::ostringstream ansiCode;
      ansiCode << escapeChars;
      int32_t mode = int32_t(col.mode);
      const char* seperator = "";
      for(uint32_t i = 0; i < 9; ++i)
      {
        if ((mode & 0x01 << i) == 0x01 << i)
        {
          ansiCode << seperator;
          switch (i) {
            case 0:
              ansiCode << "0";
              break;
            case 1:
              ansiCode << "1";
              break;
            case 2:
              ansiCode << "2";
              break;
            case 3:
              ansiCode << "3";
              break;
            case 4:
              ansiCode << "4";
              break;
            case 6:
              ansiCode << "7";
              break;
            case 7:
              ansiCode << "8";
              break;
            case 8:
              ansiCode << "9";
              break;
            default:
              break;
          }
          seperator = ";";
        }
      }
#ifdef MODLOG_TRUE_COLOR
      ansiCode << "m";
      const RGBColor& fg = col.foreground;
      const RGBColor& bg = col.background;
      ansiCode << escapeChars + "38;2;";
      ansiCode << static_cast<int32_t>(fg.r) << ';' << static_cast<int32_t>(fg.g) << ';' << static_cast<int32_t>(fg.b);
      ansiCode << "m";
      ansiCode << escapeChars + "48;2;";
      ansiCode << static_cast<int32_t>(bg.r) << ';' << static_cast<int32_t>(bg.g) << ';' << static_cast<int32_t>(bg.b);
      ansiCode << "m";
#else
#ifdef MODLOG_HIGH_COLOR_RANGE
      ansiCode << "m";
      ansiCode << escapeChars + "38;5;";
      ansiCode << static_cast<int32_t>(col.foreground);
      ansiCode << "m";
      ansiCode << escapeChars + "48;5;";
      ansiCode << static_cast<int32_t>(col.background);
      ansiCode << "m";
#else
      ansiCode << ";";
      ansiCode << int32_t(col.foreground) << ';';
      ansiCode << int32_t(col.background);
      ansiCode << "m";
#endif // MODLOG_HIGH_COLOR_RANGE
#endif // MODLOG_TRUE_COLOR
      const char* seq = ansiCode.str().c_str();
      const WARN_LEVEL& level = col.level;
      if ((level & WARN_LEVEL::DEFAULT) == WARN_LEVEL::DEFAULT)
        this->defFmt = std::string(seq);
      if ((level & WARN_LEVEL::CRIT) == WARN_LEVEL::CRIT)
        this->critFmt = std::string(seq);
      if ((level & WARN_LEVEL::ERROR) == WARN_LEVEL::ERROR)
        this->errorFmt = std::string(seq);
      if ((level & WARN_LEVEL::WARN) == WARN_LEVEL::WARN)
        this->warnFmt = std::string(seq);
      if ((level & WARN_LEVEL::INFO) == WARN_LEVEL::INFO)
        this->infoFmt = std::string(seq);
      if ((level & WARN_LEVEL::DEBUG) == WARN_LEVEL::DEBUG)
        this->debugFmt = std::string(seq);
      if ((level & WARN_LEVEL::TIME) == WARN_LEVEL::TIME)
        this->timeFmt = std::string(seq);
      return *this;
    }
    inline void operator+=(const ColorInfo& col)
    {
      *this = *this + col;
    }

    template<typename F, typename... Args>
    inline void processLog(F f, Args&&... args)
    {
      f(args...);
    }

    template<typename F, typename... Args>
    inline void addFormat(F f, const char* time, const char* col, Args&&... args)
    {
      std::string timeFormatted = time;
      if((flags & MODLOG_FLAGS::ADD_FORMAT) == MODLOG_FLAGS::ADD_FORMAT)
      {
        if(strlen(time) > 0)
        {
          timeFormatted = timeFmt + timeFormatted;
        }
        if((flags & MODLOG_FLAGS::FORMAT_INJECT) == MODLOG_FLAGS::FORMAT_INJECT)
          processLog(f, timeFormatted.c_str(), col, args..., defFmt.c_str());
        else
        {
          printf("%s", col);
          processLog(f, timeFormatted.c_str(), args..., defFmt.c_str());
        }
      }
      else
        processLog(f, timeFormatted.c_str(), args...);
    }

    template<typename F, typename... Args>
    inline void addDate(F f, const char* col, Args&&... args)
    {
      if((flags & MODLOG_FLAGS::ADD_DATE) == MODLOG_FLAGS::ADD_DATE)
      {
        std::time_t time = std::chrono::system_clock::to_time_t(
          std::chrono::system_clock::now()
        );
        char* ctime = std::ctime(&time);
        ctime[strcspn(ctime, "\n")] = 0;
        if((flags & MODLOG_FLAGS::DATE_INJECT) == MODLOG_FLAGS::DATE_INJECT)
          addFormat(f, ctime, col, args...);
        else
        {
          std::string format = "";
          std::string def = "";
          if((flags & MODLOG_FLAGS::ADD_FORMAT) == MODLOG_FLAGS::ADD_FORMAT)
          {
              format = timeFmt;
              def = defFmt;
          }
          printf("%s%s%s ", format.c_str(), ctime, def.c_str());
          addFormat(f, "", col, args...);
        }
      }
      else addFormat(f, "", col, args...);
    }

    template<typename F, typename... Args>
    inline void processCrit(F f, Args&&... args)
    {
      addDate(f, critFmt.c_str(), args...);
    }
    template<typename F, typename... Args>
    inline void processError(F f, Args&&... args)
    {
      addDate(f, errorFmt.c_str(), args...);
    }
    template<typename F, typename... Args>
    inline void processWarn(F f, Args&&... args)
    {
      addDate(f, warnFmt.c_str(), args...);
    }
    template<typename F, typename... Args>
    inline void processInfo(F f, Args&&... args)
    {
      addDate(f, infoFmt.c_str(), args...);
    }
    template<typename F, typename... Args>
    inline void processDebug(F f, Args&&... args)
    {
      addDate(f, debugFmt.c_str(), args...);
    }
  };
}

#endif /* end of include guard: __MODLOG_CONFIG_HPP__ */
