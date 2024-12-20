#include "Config.h"
#include <fstream>
#include <iostream>
#include <string>

bool ReadConfig(Config& config)
{
    std::ifstream configFile("config.cfg");
    if (!configFile.is_open())
    {
        std::cerr << "Failed to open config.cfg" << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(configFile, line))
    {
        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        if (key == "KmboxIP") config.kmboxIP = value;
        else if (key == "KmboxPort") config.kmboxPort = std::stoi(value);
        else if (key == "KmboxUUID") config.kmboxUUID = value;
        else if (key == "KmboxComPort") config.KmboxComPort = std::stoi(value);
        else if (key == "screenWidth") config.screenWidth = std::stoi(value);
        else if (key == "screenHeight") config.screenHeight = std::stoi(value);
        else if (key == "KmboxType") config.kmboxType = value;
        else if (key == "kmboxBaud") config.kmboxBaud = std::stoi(value);
    }

    return true;
}

bool SaveConfig(const Config& config)
{
    std::ofstream configFile("config.cfg");
    if (!configFile.is_open())
    {
        std::cerr << "Failed to open config.cfg for writing" << std::endl;
        return false;
    }

    configFile << "KmboxIP=" << config.kmboxIP << std::endl;
    configFile << "KmboxPort=" << config.kmboxPort << std::endl;
    configFile << "KmboxUUID=" << config.kmboxUUID << std::endl;
    configFile << "KmboxComPort=" << config.KmboxComPort << std::endl;
    configFile << "screenWidth=" << config.screenWidth << std::endl;
    configFile << "screenHeight=" << config.screenHeight << std::endl;
    configFile << "KmboxType=" << config.kmboxType << std::endl;
    configFile << "kmboxBaud=" << config.kmboxBaud << std::endl;

    return true;
}
