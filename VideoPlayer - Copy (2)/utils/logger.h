#ifndef LOGGER_H
#define LOGGER_H
#include <string>

class Logger {
public:
    void log(const std::string& message);
    void error(const std::string& message);
};

#endif