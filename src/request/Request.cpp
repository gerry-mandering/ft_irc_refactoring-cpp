#include "Request.hpp"
#include "ClientRepository.hpp"

Request::Request(Socket socket) : mSocket(socket)
{
    mClient = ClientRepository::GetInstance()->FindBySocket(socket);
    if (!mClient)
    {
        mClient = ClientRepository::GetInstance()->CreateClient(socket);
    }
}

std::shared_ptr< Client > Request::GetClient() const
{
    return mClient;
}