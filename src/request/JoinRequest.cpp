#include "JoinRequest.hpp"

bool JoinRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::vector< std::string > &JoinRequest::GetChannelnames() const
{
    return mChannelnames;
}

const std::vector< std::string > &JoinRequest::GetPasswords() const
{
    return mPasswords;
}

void JoinRequest::SetChannelnames(const std::vector< std::string > &channelnames)
{
    mChannelnames = channelnames;
}

JoinRequest::JoinRequest(Socket socket, const std::vector< std::string > &channelnames,
                         const std::vector< std::string > &passwords)
    : Request(socket)
{
}

JoinRequestBuilder &JoinRequestBuilder::SetSocket(Socket socket)
{
    mSocket = socket;
    return *this;
}

JoinRequestBuilder &JoinRequestBuilder::SetChannelnames(const std::string &channelnames)
{
    mChannelnames = channelnames;
    return *this;
}

JoinRequestBuilder &JoinRequestBuilder::SetPasswords(const std::string &passwords)
{
    mPasswords = passwords;
    return *this;
}

Request *JoinRequestBuilder::Build()
{
    return new JoinRequest(mSocket, mChannelnames, mPasswords);
}
