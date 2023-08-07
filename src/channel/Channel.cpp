#include "Channel.hpp"
#include "Client.hpp"

Channel::Channel(const string &name) : mName(name) {}

int Channel::GetNumberOfClients() const
{
    return 0;
}

bool Channel::IsClientInvited(shared_ptr< Client >) const
{
    return false;
}

void Channel::AddClient(shared_ptr< Client >) {}

void Channel::AddOperator(shared_ptr< Client >) {}

void Channel::AddInvitedClient(shared_ptr< Client >) {}

void Channel::RemoveClient(shared_ptr< Client >) {}

void Channel::RemoveOperator(shared_ptr< Client >) {}

void Channel::RemoveInvitedClient(shared_ptr< Client >) {}

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
