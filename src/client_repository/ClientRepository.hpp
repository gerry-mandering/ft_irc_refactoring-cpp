#pragma once

#include "Client.hpp"
#include "Singleton.hpp"
#include <map>
#include <memory>

// FIXME
typedef int Socket;

class ClientRepository : public Singleton< ClientRepository >
{
  public:
    std::shared_ptr< Client > CreateClient(Socket socket);
    void AddClientToNicknameMap(std::shared_ptr< Client > client);

    std::shared_ptr< Client > FindBySocket(Socket socket);
    std::shared_ptr< Client > FindByName(const std::string &name);

    int GetNumberOfClients() const;

    void RemoveClient(std::shared_ptr< Client > client);
    void RemoveClientFromNicknameMap(std::shared_ptr< Client > client);

  private:
    std::map< Socket, std::shared_ptr< Client > > mSocketToClientMap;
    std::map< std::string, std::shared_ptr< Client > > mNicknameToClientMap;
};