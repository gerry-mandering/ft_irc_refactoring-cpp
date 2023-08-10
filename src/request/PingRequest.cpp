#include "PingRequest.hpp"

bool PingRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &PingRequest::GetToken() const
{
    return mToken;
}

PingRequest::PingRequest(Socket socket, const std::string &token) : Request(socket) {}

PingRequestBuilder &PingRequestBuilder::SetToken(const std::string &token)
{
    mToken = token;
    return *this;
}

Request *PingRequestBuilder::Build()
{
    return new PingRequest(mSocket, mToken);
}
