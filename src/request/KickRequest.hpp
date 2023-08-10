#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>
#include <vector>

class KickRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetChannelname() const;
    const std::vector< std::string > &GetTargets() const;
    const std::string &GetMessage() const;

    void SetTargets(const std::vector< std::string > &targets);

    friend class KickRequestBuilder;

  private:
    KickRequest(Socket socket, const std::string &channelname, const std::vector< std::string > &targets,
                const std::string &message);

  private:
    std::string mChannelname;
    std::vector< std::string > mTargets;
    std::string mMessage;
};

class KickRequestBuilder : public RequestBuilder
{
  public:
    KickRequestBuilder &SetSocket(Socket socket) override;
    KickRequestBuilder &SetChannelname(const std::string &channelname);
    KickRequestBuilder &SetTargets(const std::vector< std::string > &targets);
    KickRequestBuilder &SetMessage(const std::string &message);

    Request *Build() override;

  private:
    Socket mSocket{};
    std::string mChannelname{};
    std::vector< std::string > mTargets{};
    std::string mMessage{};
};