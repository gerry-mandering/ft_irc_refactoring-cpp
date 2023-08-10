#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>

class InviteRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetNickname() const;
    const std::string &GetChannelname() const;

    friend class InviteRequestBuilder;

  private:
    InviteRequest(Socket socket, const std::string &nickname, const std::string &channelname);

  private:
    std::string mNickname;
    std::string mChannelname;
};

class InviteRequestBuilder : public RequestBuilder
{
  public:
    InviteRequestBuilder &SetSocket(Socket socket) override;
    InviteRequestBuilder &SetNickname(const std::string &nickname);
    InviteRequestBuilder &SetChannelname(const std::string &channelname);

    Request *Build() override;

  private:
    Socket mSocket{};
    std::string mNickname{};
    std::string mChannelname{};
};