#include "Channel.hpp"
#include "Client.hpp"

Channel::Channel(const string &name) : mName(name) {}

int Channel::GetNumberOfClients() const
{
    return mClients.size();
}

bool Channel::IsClientInvited(shared_ptr< Client > client) const
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

void Channel::AddClient(shared_ptr< Client > newClient)
{
    mClients.push_back(newClient);
}

void Channel::AddAdmin(shared_ptr< Client > newAdmin)
{
    mAdmins.push_back(newAdmin);
}

void Channel::AddInvitedClient(shared_ptr< Client > newInvitedClient)
{
    mInvitedClients.push_back(newInvitedClient);
}

void Channel::RemoveClient(shared_ptr< Client > client)
{
    RemoveAdmin(client);

    auto it = find(mClients.begin(), mClients.end(), client);
    if (it != mClients.end())
    {
        mClients.erase(it);
    }
}

void Channel::RemoveAdmin(shared_ptr< Client > admin)
{
    auto it = find(mAdmins.begin(), mAdmins.end(), admin);
    if (it != mAdmins.end())
    {
        mAdmins.erase(it);
    }
}

void Channel::RemoveInvitedClient(shared_ptr< Client > invitedClient)
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

const string &Channel::GetName() const
{
    return mName;
}

const string &Channel::GetTopic() const
{
    return mTopic;
}

const string &Channel::GetPassword() const
{
    return mPassword;
}

int Channel::GetMaxClients() const
{
    return mMaxClients;
}

void Channel::SetName(const string &name)
{
    Channel::mName = name;
}

void Channel::SetTopic(const string &topic)
{
    Channel::mTopic = topic;
}

void Channel::SetPassword(const string &password)
{
    Channel::mPassword = password;
}

void Channel::SetMaxClients(int maxClients)
{
    Channel::mMaxClients = maxClients;
}
