#include "Request.hpp"

Request::Request(Socket socket)
{
    mSocket = socket;
}

std::shared_ptr< Client > Request::GetClient() const
{
    if (auto clientPtr = mClient.lock())
    {
        return clientPtr;
    }
    else
    {
        return nullptr;
    }
}

RequestBuilder &RequestBuilder::SetSocket(Socket socket)
{
    mSocket = socket;
    return *this;
}