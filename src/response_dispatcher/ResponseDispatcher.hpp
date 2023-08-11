#pragma once

#include <string>
#include <vector>

class ResponseDispatcher
{
  public:
    ResponseDispatcher();
    virtual ~ResponseDispatcher() = default;

  protected:
    const std::string &getServerName() const;
    const std::string &leftPad(const std::string &str, char ch = ' ', int len = 1) const;
    const std::string &buildMessage(const std::vector< std::string > &fields) const;

  private:
    std::string mServerName;
};