#pragma once

#include <memory>
#include <string>
#include <vector>

class Client;

class Channel : public std::enable_shared_from_this< Channel >
{
  public:
    Channel(const std::string &name);

    Channel() = delete;
    ~Channel() = default;

    int GetNumberOfClients() const;
    bool IsClientInvited(std::shared_ptr< Client > client) const;

    void AddClient(std::shared_ptr< Client > newClient);
    void AddAdmin(std::shared_ptr< Client > newAdmin);
    void AddInvitedClient(std::shared_ptr< Client > newInvitedClient);

    void RemoveClient(std::shared_ptr< Client > client);
    void RemoveAdmin(std::shared_ptr< Client > admin);
    void RemoveInvitedClient(std::shared_ptr< Client > invitedClient);

    const std::string &GetName() const;
    const std::string &GetTopic() const;
    const std::string &GetPassword() const;
    int GetMaxClients() const;

    void SetName(const std::string &name);
    void SetTopic(const std::string &topic);
    void SetPassword(const std::string &password);
    void SetMaxClients(int maxClients);

  private:
    std::vector< std::shared_ptr< Client > > mClients;
    std::vector< std::shared_ptr< Client > > mAdmins;
    std::vector< std::weak_ptr< Client > > mInvitedClients;

    std::string mName{};
    std::string mTopic{};
    std::string mPassword{};
    int mMaxClients{};

    int mModeFlags{};

    static constexpr int EMPTY = 0;
    static constexpr int INVITE_ONLY = 1 << 0;
    static constexpr int PROTECTED_TOPIC = 1 << 1;
    static constexpr int PASSWORD = 1 << 2;
    static constexpr int CLIENT_LIMIT = 1 << 3;
};