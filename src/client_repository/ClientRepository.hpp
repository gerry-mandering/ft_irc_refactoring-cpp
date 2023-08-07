#pragma once

#include "Client.hpp"
#include "Singleton.hpp"
#include <map>
#include <memory>

using namespace std;

class ClientRepository : public Singleton< ClientRepository >
{
  public:
    shared_ptr< Channel > CreateClient(const string &name);
    void AddClientToNicknameMap(shared_ptr< Client > client);

    shared_ptr< Client > FindBySocket(Socket socket);
    shared_ptr< Channel > FindByName(const string &name);

    int GetNumberOfChannels() const;

    void RemoveChannel(shared_ptr< Channel > channel);

  private:
    map< Socket, shared_ptr< Client > > mSocketToClients;
    map< string, shared_ptr< Client > > mNicknameToClients;
};