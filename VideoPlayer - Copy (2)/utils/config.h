#ifndef CONFIG_H
#define CONFIG_H
#include <string>

class Config {
public:
    Config();
    void load(const std::string& filename);
};

#endif