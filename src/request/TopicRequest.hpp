#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>

class TopicRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetChannelname() const;
    const std::string &GetTopic() const;

    friend class TopicRequestBuilder;

  private:
    TopicRequest(Socket socket, const std::string &channelname, const std::string &topic);

  private:
    std::string mChannelname;
    std::string mTopic;
};

class TopicRequestBuilder : public RequestBuilder
{
  public:
    TopicRequestBuilder &SetSocket(Socket socket) override;
    TopicRequestBuilder &SetChannelname(const std::string &channelname);
    TopicRequestBuilder &SetTopic(const std::string &topic);

    Request *Build() override;

  private:
    Socket mSocket{};
    std::string mChannelname{};
    std::string mTopic{};
};