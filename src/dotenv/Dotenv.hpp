#pragma once

#include "Singleton.hpp"
#include <map>
#include <string>

class Dotenv : public Singleton< Dotenv >
{
  public:
    Dotenv() = delete;

    void LoadEnvFromFile(const std::string &filename);
    std::string Get(const std::string &key);

  private:
    std::map< std::string, std::string > envVariables;
};