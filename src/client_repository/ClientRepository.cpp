#include "ClientRepository.hpp"

shared_ptr< Client > ClientRepository::CreateClient(Socket socket)
{
    shared_ptr< Client > client = make_shared< Client >(socket);
    mSocketToClientMap[socket] = client;

    return client;
}

void ClientRepository::AddClientToNicknameMap(shared_ptr< Client > client)
{
    mNicknameToClientMap[client->GetNickname()] = client;
}

shared_ptr< Client > ClientRepository::FindBySocket(Socket socket)
{
    auto it = mSocketToClientMap.find(socket);
    if (it != mSocketToClientMap.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

shared_ptr< Client > ClientRepository::FindByName(const string &name)
{
    auto it = mNicknameToClientMap.find(name);
    if (it != mNicknameToClientMap.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

int ClientRepository::GetNumberOfClients() const
{
    return mSocketToClientMap.size();
}

void ClientRepository::RemoveClient(shared_ptr< Client > client)
{
    RemoveClientFromNicknameMap(client);

    auto it = mSocketToClientMap.find(client->GetSocket());
    if (it != mSocketToClientMap.end())
    {
        mSocketToClientMap.erase(it);
    }
}

void ClientRepository::RemoveClientFromNicknameMap(shared_ptr< Client > client)
{
    auto it = mNicknameToClientMap.find(client->GetNickname());
    if (it != mNicknameToClientMap.end())
    {
        mNicknameToClientMap.erase(it);
    }
}
