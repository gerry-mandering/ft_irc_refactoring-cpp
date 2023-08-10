#include "Channel.hpp"
#include "Client.hpp"

Channel::Channel(const std::string &name) : mName(name) {}

int Channel::GetNumberOfClients() const
{
    return mClients.size();
}

bool Channel::IsClientExist(std::shared_ptr< Client > client) const
{
    auto it = std::find(mClients.begin(), mClients.end(), client);
    if (it != mClients.end())
    {
        return true;
    }

    return false;
}

bool Channel::IsClientAdmin(std::shared_ptr< Client > client) const
{
    auto it = std::find(mAdmins.begin(), mAdmins.end(), client);
    if (it != mAdmins.end())
    {
        return true;
    }

    return false;
}

bool Channel::IsClientInvited(std::shared_ptr< Client > client) const
{
    for (const auto &invitedClient : mInvitedClients)
    {
        auto locked = invitedClient.lock();
        if (!locked)
        {
            continue;
        }

        if (locked == client)
        {
            return true;
        }
    }

    return false;
}

void Channel::AddClient(std::shared_ptr< Client > newClient)
{
    mClients.push_back(newClient);
}

void Channel::AddAdmin(std::shared_ptr< Client > newAdmin)
{
    mAdmins.push_back(newAdmin);
}

void Channel::AddInvitedClient(std::shared_ptr< Client > newInvitedClient)
{
    mInvitedClients.push_back(newInvitedClient);
}

void Channel::RemoveClient(std::shared_ptr< Client > client)
{
    RemoveAdmin(client);

    auto it = std::find(mClients.begin(), mClients.end(), client);
    if (it != mClients.end())
    {
        mClients.erase(it);
    }
}

void Channel::RemoveAdmin(std::shared_ptr< Client > admin)
{
    auto it = std::find(mAdmins.begin(), mAdmins.end(), admin);
    if (it != mAdmins.end())
    {
        mAdmins.erase(it);
    }
}

void Channel::RemoveInvitedClient(std::shared_ptr< Client > invitedClient)
{
    for (auto it = mInvitedClients.begin(); it != mInvitedClients.end(); it++)
    {
        auto locked = it->lock();
        if (!locked)
        {
            continue;
        }

        if (locked == invitedClient)
        {
            mInvitedClients.erase(it);
        }
    }
}

const std::string &Channel::GetName() const
{
    return mName;
}

const std::string &Channel::GetTopic() const
{
    return mTopic;
}

const std::string &Channel::GetPassword() const
{
    return mPassword;
}

int Channel::GetMaxClients() const
{
    return mMaxClients;
}

void Channel::SetName(const std::string &name)
{
    Channel::mName = name;
}

void Channel::SetTopic(const std::string &topic)
{
    Channel::mTopic = topic;
}

void Channel::SetPassword(const std::string &password)
{
    Channel::mPassword = password;
}

void Channel::SetMaxClients(int maxClients)
{
    Channel::mMaxClients = maxClients;
}
