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
    bool IsClientInvited(shared_ptr< Client >) const;

    void AddClient(shared_ptr< Client >);
    void AddOperator(shared_ptr< Client >);
    void AddInvitedClient(shared_ptr< Client >);

    void RemoveClient(shared_ptr< Client >);
    void RemoveOperator(shared_ptr< Client >);
    void RemoveInvitedClient(shared_ptr< Client >);

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
    vector< shared_ptr< Client > > mOperators;
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