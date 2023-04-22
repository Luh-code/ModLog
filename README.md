# ModLog
A modular logging abstraction with support for domains.
It provides a layer of abstraction between the Logger and the application.
This helps with longevity of the project, as the logger can be swapped to something new and improved without much hassle.
ModLog also provides logging to files (in the case the logger it's abstracting doesn't already have that), aswell as adding further data to a log,
like the date or coloring.
ModLog can also inject the log with name of the current domain.

# Libraries
The main usage for ModLog is providing a unifying logging interface for libraries.
This is to get rid of the hassle that comes with trying to use libraries, that may rely on built-in logging systems or convoluted ways of retrieving logging information from the library and helps to unify them into one debug stream.

# INDEV
ModLog isn't fully tested nor feature complete nor implemented at this point.
Right now ModLog can only abstract Loggers that use C++ Parameter Packs and doesn't have support for loggers working with variadic lists yet.
Features:
 - Fully customizable generic abstraction for Loggers
 - Adding formatting to a log
  - Fully customizable formatting
  - Multiple modes for formatting: Standard ANSI color mode, aixterm mode, 256 color mode, True color mode
 - Adding a timestamp to a log
Features still to-be-implemented:
 - Domain-specific Logging
 - Injecting the logging level into the log
 - Logging to File
 - Default colors for High-color-range mode and True-color-mode

# Documentation
The documentation isn't yet written and will become available at a later date, when the library has gotten more feature-complete.
