#include "PartRequest.hpp"

bool PartRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::vector< std::string > &PartRequest::GetChannelnames() const
{
    return mChannelnames;
}

const std::string &PartRequest::GetReason() const
{
    return mReason;
}

void PartRequest::SetChannelnames(const std::vector< std::string > &channelnames)
{
    mChannelnames = channelnames;
}

PartRequest::PartRequest(Socket socket, const std::vector< std::string > &channelnames, const std::string &reason)
    : Request(socket)
{
}

PartRequestBuilder &PartRequestBuilder::SetChannelnames(const std::vector< std::string > &channelnames)
{
    mChannelnames = channelnames;
    return *this;
}

PartRequestBuilder &PartRequestBuilder::SetReason(const std::string &reason)
{
    mReason = reason;
    return *this;
}

Request *PartRequestBuilder::Build()
{
    return new PartRequest(mSocket, mChannelnames, mReason);
}
