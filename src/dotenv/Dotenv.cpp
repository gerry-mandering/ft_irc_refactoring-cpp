#include "Dotenv.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

void Dotenv::LoadEnvFromFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value))
        {
            envVariables[key] = value;
        }
    }
}

std::string Dotenv::Get(const std::string &key)
{
    auto it = envVariables.find(key);

    if (it != envVariables.end())
    {
        return it->second;
    }
    else
    {
        return {};
    }
}