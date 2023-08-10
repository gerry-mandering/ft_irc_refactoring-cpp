#include "UserRequest.hpp"

bool UserRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &UserRequest::GetUsername() const
{
    return mUsername;
}

const std::string &UserRequest::GetHostname() const
{
    return mHostname;
}

const std::string &UserRequest::GetServername() const
{
    return mServername;
}

const std::string &UserRequest::GetRealname() const
{
    return mRealname;
}

UserRequest::UserRequest(Socket socket, const std::string &username, const std::string &hostname,
                         const std::string &servername, const std::string &realname)
    : Request(socket)
{
}

UserRequestBuilder &UserRequestBuilder::SetUsername(const std::string &username)
{
    mUsername = username;
    return *this;
}

UserRequestBuilder &UserRequestBuilder::SetHostname(const std::string &hostname)
{
    mHostname = hostname;
    return *this;
}

UserRequestBuilder &UserRequestBuilder::SetServername(const std::string &servername)
{
    mServername = servername;
    return *this;
}

UserRequestBuilder &UserRequestBuilder::SetRealname(const std::string &realname)
{
    mRealname = realname;
    return *this;
}

Request *UserRequestBuilder::Build()
{
    return new UserRequest(mSocket, mUsername, mHostname, mServername, mRealname);
}
