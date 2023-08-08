#include "ChannelRepository.hpp"

shared_ptr< Channel > ChannelRepository::CreateChannel(const string &name)
{
    shared_ptr< Channel > newChannel = make_shared< Channel >(name);
    mChannels[name] = newChannel;

    return newChannel;
}

shared_ptr< Channel > ChannelRepository::FindByName(const string &name)
{
    auto it = mChannels.find(name);
    if (it != mChannels.end())
        return it->second;

    return nullptr;
}

int ChannelRepository::GetNumberOfChannels() const
{
    return mChannels.size();
}

void ChannelRepository::RemoveChannel(shared_ptr< Channel > channel)
{
    auto it = mChannels.find(channel->GetName());
    if (it != mChannels.end())
        mChannels.erase(it);
}
