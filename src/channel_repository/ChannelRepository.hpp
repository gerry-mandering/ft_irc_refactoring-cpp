#pragma once

#include "Channel.hpp"
#include "Singleton.hpp"
#include <map>
#include <memory>

using namespace std;

class ChannelRepository : public Singleton< ChannelRepository >
{
  public:
    shared_ptr< Channel > CreateChannel(const string &name);
    shared_ptr< Channel > FindByName(const string &name);

    int GetNumberOfChannels() const;

    void RemoveChannel(shared_ptr< Channel > channel);

  private:
    map< string, shared_ptr< Channel > > mChannels;
};