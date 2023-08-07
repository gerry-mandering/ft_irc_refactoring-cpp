#include "Request.hpp"

Request::Request(Socket socket)
{
    mSocket = socket;
}

shared_ptr< Client > Request::GetClient() const
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
