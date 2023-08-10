#include "NickRequest.hpp"

bool NickRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &NickRequest::GetNickname() const
{
    return mNickname;
}

NickRequest::NickRequest(Socket socket, const std::string &nickname) : Request(socket) {}

NickRequestBuilder &NickRequestBuilder::SetSocket(Socket socket)
{
    mSocket = socket;
    return *this;
}

NickRequestBuilder &NickRequestBuilder::SetNickname(const std::string &nickname)
{
    mNickname = nickname;
    return *this;
}

Request *NickRequestBuilder::Build()
{
    return new NickRequest(mSocket, mNickname);
}
