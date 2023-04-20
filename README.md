# ModLog
A modular logging abstraction with support for domains.
It provides a layer of abstraction between the Logger and the application. 
This helps with longjevity of the project, as the logger can be swapped to something new and improved without much hassle.
ModLog also provides logging to files (in the case the logger it's abstracting doesn't already have that), aswell as adding futher data to a log,
like the date or coloring.
ModLog can also inject the log with name of the current domain.

# INDEV
ModLog isn't fully tested nor feature complete nor implemented at this point.
Right now ModLog can only abstract Loggers that use C++ Parameter Packs and doesn't have support for loggers working with variadic lists yet.
Documentation will follow, when the project is in a more usable state.
