#include "QuitRequest.hpp"

bool QuitRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &QuitRequest::GetReason() const
{
    return mReason;
}

QuitRequest::QuitRequest(Socket socket, const std::string &reason) : Request(socket) {}

QuitRequestBuilder &QuitRequestBuilder::SetReason(const std::string &reason)
{
    mReason = reason;
    return *this;
}

Request *QuitRequestBuilder::Build()
{
    return new QuitRequest(mSocket, mReason);
}
