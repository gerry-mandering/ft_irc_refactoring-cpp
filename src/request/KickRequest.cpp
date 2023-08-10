#include "KickRequest.hpp"

bool KickRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &KickRequest::GetChannelname() const
{
    return mChannelname;
}

const std::vector< std::string > &KickRequest::GetTargets() const
{
    return mTargets;
}

const std::string &KickRequest::GetMessage() const
{
    return mMessage;
}

void KickRequest::SetTargets(const std::vector< std::string > &targets)
{
    mTargets = targets;
}

KickRequest::KickRequest(Socket socket, const std::string &channelname, const std::vector< std::string > &targets,
                         const std::string &message)
    : Request(socket)
{
}

KickRequestBuilder &KickRequestBuilder::SetChannelname(const std::string &channelname)
{
    mChannelname = channelname;
    return *this;
}

KickRequestBuilder &KickRequestBuilder::SetTargets(const std::vector< std::string > &targets)
{
    mTargets = targets;
    return *this;
}

KickRequestBuilder &KickRequestBuilder::SetMessage(const std::string &message)
{
    mMessage = message;
    return *this;
}

Request *KickRequestBuilder::Build()
{
    return new KickRequest(mSocket, mChannelname, mTargets, mMessage);
}
