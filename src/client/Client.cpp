#include "Client.hpp"
#include "Channel.hpp"

Client::Client(Socket socket) : mSocket(socket) {}

int Client::GetSocket() const
{
    return mSocket;
}

void Client::JoinChannel(std::shared_ptr< Channel > channel)
{
    mChannels.push_back(channel);
    channel->AddClient(shared_from_this());
}

void Client::LeaveChannel(std::shared_ptr< Channel > channel)
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

const std::string &Client::GetNickname() const
{
    return mNickname;
}

const std::string &Client::GetUsername() const
{
    return mUsername;
}

const std::string &Client::GetHostname() const
{
    return mHostname;
}

const std::string &Client::GetServername() const
{
    return mServername;
}

const std::string &Client::GetRealname() const
{
    return mRealname;
}

void Client::SetNickname(const std::string &nickname)
{
    mNickname = nickname;
}

void Client::SetUsername(const std::string &username)
{
    mUsername = username;
}

void Client::SetHostname(const std::string &hostname)
{
    mHostname = hostname;
}

void Client::SetServername(const std::string &servername)
{
    mServername = servername;
}

void Client::SetRealname(const std::string &realname)
{
    mRealname = realname;
}
