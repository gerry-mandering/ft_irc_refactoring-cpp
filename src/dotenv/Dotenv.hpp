#pragma once

#include <map>
#include <string>

class Dotenv
{
  public:
    Dotenv(const std::string &filename);
    void LoadEnvFromFile(const std::string &filename);
    std::string Get(const std::string &key);

  private:
    std::map< std::string, std::string > envVariables;
};