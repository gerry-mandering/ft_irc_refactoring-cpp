#include "Client.hpp"
#include "Channel.hpp"

Client::Client(Socket socket) : mSocket(socket) {}

int Client::GetSocket() const
{
    return mSocket;
}

void Client::JoinChannel(shared_ptr< Channel > channel)
{
    mChannels.push_back(channel);
    channel->AddClient(shared_from_this());
}

void Client::LeaveChannel(shared_ptr< Channel > channel)
{
    for (auto it = mChannels.begin(); it != mChannels.end(); ++it)
    {
        auto locked = it->lock();
        if (!locked)
        {
            continue;
        }

        if (locked == channel)
        {
            mChannels.erase(it);
            break;
        }
    }

    channel->RemoveClient(shared_from_this());
}

const string &Client::GetNickname() const
{
    return mNickname;
}

const string &Client::GetUsername() const
{
    return mUsername;
}

const string &Client::GetHostname() const
{
    return mHostname;
}

const string &Client::GetServername() const
{
    return mServername;
}

const string &Client::GetRealname() const
{
    return mRealname;
}

void Client::SetNickname(const string &nickname)
{
    mNickname = nickname;
}

void Client::SetUsername(const string &username)
{
    mUsername = username;
}

void Client::SetHostname(const string &hostname)
{
    mHostname = hostname;
}

void Client::SetServername(const string &servername)
{
    mServername = servername;
}

void Client::SetRealname(const string &realname)
{
    mRealname = realname;
}
