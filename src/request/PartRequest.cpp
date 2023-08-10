#include "PartRequest.hpp"

bool PartRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::vector< std::string > &PartRequest::GetChannels() const
{
    return mChannels;
}

const std::string &PartRequest::GetReason() const
{
    return mReason;
}

void PartRequest::SetChannels(const std::vector< std::string > &channels)
{
    mChannels = channels;
}

PartRequest::PartRequest(Socket socket, const std::vector< std::string > &channels, const std::string &reason)
    : Request(socket)
{
}

PartRequestBuilder &PartRequestBuilder::SetChannels(const std::vector< std::string > &channels)
{
    mChannels = channels;
    return *this;
}

PartRequestBuilder &PartRequestBuilder::SetReason(const std::string &reason)
{
    mReason = reason;
    return *this;
}

Request *PartRequestBuilder::Build()
{
    return new PartRequest(mSocket, mChannels, mReason);
}
