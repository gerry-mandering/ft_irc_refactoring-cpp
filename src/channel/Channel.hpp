#pragma once

#include <memory>
#include <string>
#include <vector>

using namespace std;

class Client;

class Channel : public enable_shared_from_this< Channel >
{
  public:
    Channel(const string &name);

    Channel() = delete;
    ~Channel() = default;

    int GetNumberOfClients() const;
    bool IsClientInvited(shared_ptr< Client > client) const;

    void AddClient(shared_ptr< Client > newClient);
    void AddAdmin(shared_ptr< Client > newAdmin);
    void AddInvitedClient(shared_ptr< Client > newInvitedClient);

    void RemoveClient(shared_ptr< Client > client);
    void RemoveAdmin(shared_ptr< Client > admin);
    void RemoveInvitedClient(shared_ptr< Client > invitedClient);

    const string &GetName() const;
    const string &GetTopic() const;
    const string &GetPassword() const;
    int GetMaxClients() const;

    void SetName(const string &name);
    void SetTopic(const string &topic);
    void SetPassword(const string &password);
    void SetMaxClients(int maxClients);

  private:
    vector< shared_ptr< Client > > mClients;
    vector< shared_ptr< Client > > mAdmins;
    vector< weak_ptr< Client > > mInvitedClients;

    string mName{};
    string mTopic{};
    string mPassword{};
    int mMaxClients{};

    int mModeFlags{};

    static constexpr int EMPTY = 0;
    static constexpr int INVITE_ONLY = 1 << 0;
    static constexpr int PROTECTED_TOPIC = 1 << 1;
    static constexpr int PASSWORD = 1 << 2;
    static constexpr int CLIENT_LIMIT = 1 << 3;
};