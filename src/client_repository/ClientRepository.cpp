#include "ClientRepository.hpp"

std::shared_ptr< Client > ClientRepository::CreateClient(Socket socket)
{
    std::shared_ptr< Client > client = std::make_shared< Client >(socket);
    mSocketToClientMap[socket] = client;

    return client;
}

void ClientRepository::AddClientToNicknameMap(std::shared_ptr< Client > client)
{
    mNicknameToClientMap[client->GetNickname()] = client;
}

std::shared_ptr< Client > ClientRepository::FindBySocket(Socket socket)
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

std::shared_ptr< Client > ClientRepository::FindByName(const std::string &name)
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

void ClientRepository::RemoveClient(std::shared_ptr< Client > client)
{
    RemoveClientFromNicknameMap(client);

    auto it = mSocketToClientMap.find(client->GetSocket());
    if (it != mSocketToClientMap.end())
    {
        mSocketToClientMap.erase(it);
    }
}

void ClientRepository::RemoveClientFromNicknameMap(std::shared_ptr< Client > client)
{
    auto it = mNicknameToClientMap.find(client->GetNickname());
    if (it != mNicknameToClientMap.end())
    {
        mNicknameToClientMap.erase(it);
    }
}
