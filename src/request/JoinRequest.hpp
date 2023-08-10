#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>

class JoinRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetChannelname() const;
    const std::string &GetPassword() const;

    friend class JoinRequestBuilder;

  private:
    JoinRequest(Socket socket, const std::string &channelname, const std::string &password);

  private:
    std::string mChannelname;
    std::string mPassword;
};

class JoinRequestBuilder : public RequestBuilder
{
  public:
    JoinRequestBuilder &SetChannelname(const std::string &channelname);
    JoinRequestBuilder &SetPassword(const std::string &password);

    Request *Build() override;

  private:
    std::string mChannelname{};
    std::string mPassword{};
};