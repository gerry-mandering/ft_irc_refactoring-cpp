#include "PassRequest.hpp"

bool PassRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &PassRequest::GetPassword() const
{
    return mPassword;
}

PassRequest::PassRequest(Socket socket, const std::string &password) : Request(socket) {}

PassRequestBuilder &PassRequestBuilder::SetPassword(const std::string &password)
{
    mPassword = password;
    return *this;
}

Request *PassRequestBuilder::Build()
{
    return new PassRequest(mSocket, mPassword);
}
