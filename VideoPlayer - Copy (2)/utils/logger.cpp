#include "logger.h"
#include <iostream>
#include <ctime>
#include <iomanip>

void Logger::log(const std::string& message) {
    std::time_t now = std::time(nullptr);
    std::cout << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S") << " - " << message << std::endl;
}

void Logger::error(const std::string& message) {
    std::time_t now = std::time(nullptr);
    std::cout << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S") << " [ERROR] - " << message << std::endl;
}