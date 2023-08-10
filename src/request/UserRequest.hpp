#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>

class UserRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetUsername() const;
    const std::string &GetHostname() const;
    const std::string &GetServername() const;
    const std::string &GetRealname() const;

    friend class UserRequestBuilder;

  private:
    UserRequest(Socket socket, const std::string &username, const std::string &hostname, const std::string &servername,
                const std::string &realname);

  private:
    std::string mUsername;
    std::string mHostname;
    std::string mServername;
    std::string mRealname;
};

class UserRequestBuilder : public RequestBuilder
{
  public:
    UserRequestBuilder &SetSocket(Socket socket) override;
    UserRequestBuilder &SetUsername(const std::string &username);
    UserRequestBuilder &SetHostname(const std::string &hostname);
    UserRequestBuilder &SetServername(const std::string &servername);
    UserRequestBuilder &SetRealname(const std::string &realname);

    Request *Build() override;

  private:
    Socket mSocket{};
    std::string mUsername{};
    std::string mHostname{};
    std::string mServername{};
    std::string mRealname{};
};