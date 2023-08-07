#pragma once

#include <memory>
#include <string>
#include <vector>

using namespace std;

class Channel;

class Client : public enable_shared_from_this< Client >
{
  public:
    Client(Socket socket);

    Client() = delete;
    ~Client() = default;

    void JoinChannel(shared_ptr< Channel > channel);
    void LeaveChannel(shared_ptr< Channel > channel);

    const string &GetNickname() const;
    const string &GetUsername() const;
    const string &GetHostname() const;
    const string &GetServername() const;
    const string &GetRealname() const;

    void SetNickname(const string &nickname);
    void SetUsername(const string &username);
    void SetHostname(const string &hostname);
    void SetServername(const string &servername);
    void SetRealname(const string &realname);

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

    vector< weak_ptr< Channel > > mChannels;

    string mNickname{};
    string mUsername{};
    string mHostname{};
    string mServername{};
    string mRealname{};

    int mRegistrationFlags{};

    static constexpr int REGISTERED = 1 << 0;
    static constexpr int PASSWORD_ENTERED = 1 << 1;
    static constexpr int NICKNAME_ENTERED = 1 << 2;
    static constexpr int USER_INFO_ENTERED = 1 << 3;
};