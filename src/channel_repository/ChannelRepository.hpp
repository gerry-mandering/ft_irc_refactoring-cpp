#pragma once

#include "Channel.hpp"
#include "Singleton.hpp"
#include <map>
#include <memory>
#include <string>

class ChannelRepository : public Singleton< ChannelRepository >
{
  public:
    std::shared_ptr< Channel > CreateChannel(const std::string &name);
    std::shared_ptr< Channel > FindByName(const std::string &name);

    int GetNumberOfChannels() const;

    void RemoveChannel(std::shared_ptr< Channel > channel);

  private:
    std::map< std::string, std::shared_ptr< Channel > > mChannels;
};