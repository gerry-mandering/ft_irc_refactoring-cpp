#pragma once

#include <memory>
#include <string>
#include <vector>

// FIXME
typedef int Socket;

class Channel;

class Client : public std::enable_shared_from_this< Client >
{
  public:
    Client(Socket socket);

    Client() = delete;
    ~Client() = default;

    Socket GetSocket() const;
    void AddResponse(const std::string &response);

    void JoinChannel(std::shared_ptr< Channel > channel);
    void LeaveChannel(std::shared_ptr< Channel > channel);

    const std::string &GetNickname() const;
    const std::string &GetUsername() const;
    const std::string &GetHostname() const;
    const std::string &GetServername() const;
    const std::string &GetRealname() const;

    void SetNickname(const std::string &nickname);
    void SetUsername(const std::string &username);
    void SetHostname(const std::string &hostname);
    void SetServername(const std::string &servername);
    void SetRealname(const std::string &realname);

    bool HasRegistered() const;
    bool HasEnteredPassword() const;
    bool HasEnteredNickname() const;
    bool HasEnteredUserInfo() const;

    void MarkAsRegistered();
    void MarkAsPasswordEntered();
    void MarkAsNicknameEntered();
    void MarkAsUserInfoEntered();

  private:
    Socket mSocket;
    std::string mResponseBuffer{};

    std::vector< std::weak_ptr< Channel > > mChannels;

    std::string mNickname{};
    std::string mUsername{};
    std::string mHostname{};
    std::string mServername{};
    std::string mRealname{};

    int mRegistrationFlags{};

    static constexpr int REGISTERED = 1 << 0;
    static constexpr int PASSWORD_ENTERED = 1 << 1;
    static constexpr int NICKNAME_ENTERED = 1 << 2;
    static constexpr int USER_INFO_ENTERED = 1 << 3;
};