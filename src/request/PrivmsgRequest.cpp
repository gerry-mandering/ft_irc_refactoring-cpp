#include "PrivmsgRequest.hpp"

bool PrivmsgRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::vector< std::string > &PrivmsgRequest::GetTargets() const
{
    return mTargets;
}

const std::string &PrivmsgRequest::GetMessage() const
{
    return mMessage;
}

void PrivmsgRequest::SetTargets(const std::vector< std::string > &targets)
{
    mTargets = targets;
}

PrivmsgRequest::PrivmsgRequest(Socket socket, const std::vector< std::string > &targets, const std::string &message)
    : Request(socket)
{
}

PrivmsgRequestBuilder &PrivmsgRequestBuilder::SetSocket(Socket socket)
{
    mSocket = socket;
    return *this;
}

PrivmsgRequestBuilder &PrivmsgRequestBuilder::SetTargets(const std::vector< std::string > &targets)
{
    mTargets = targets;
    return *this;
}

PrivmsgRequestBuilder &PrivmsgRequestBuilder::SetMessage(const std::string &message)
{
    mMessage = message;
    return *this;
}

Request *PrivmsgRequestBuilder::Build()
{
    return new PrivmsgRequest(mSocket, mTargets, mMessage);
}
