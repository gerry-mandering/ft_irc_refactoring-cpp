#pragma once

#include "Client.hpp"
#include "Singleton.hpp"
#include <map>
#include <memory>

using namespace std;

class ClientRepository : public Singleton< ClientRepository >
{
  public:
    shared_ptr< Client > CreateClient(Socket socket);
    void AddClientToNicknameMap(shared_ptr< Client > client);

    shared_ptr< Client > FindBySocket(Socket socket);
    shared_ptr< Client > FindByName(const string &name);

    int GetNumberOfClients() const;

    void RemoveClient(shared_ptr< Client > client);
    void RemoveClientFromNicknameMap(shared_ptr< Client > client);

  private:
    map< Socket, shared_ptr< Client > > mSocketToClientMap;
    map< string, shared_ptr< Client > > mNicknameToClientMap;
};