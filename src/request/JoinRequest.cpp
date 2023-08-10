#include "JoinRequest.hpp"

bool JoinRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &JoinRequest::GetChannelname() const
{
    return mChannelname;
}

const std::string &JoinRequest::GetPassword() const
{
    return mPassword;
}

JoinRequest::JoinRequest(Socket socket, const std::string &channelname, const std::string &password) : Request(socket)
{
}

JoinRequestBuilder &JoinRequestBuilder::SetChannelname(const std::string &channelname)
{
    mChannelname = channelname;
    return *this;
}

JoinRequestBuilder &JoinRequestBuilder::SetPassword(const std::string &password)
{
    mPassword = password;
    return *this;
}

Request *JoinRequestBuilder::Build()
{
    return new JoinRequest(mSocket, mChannelname, mPassword);
}
