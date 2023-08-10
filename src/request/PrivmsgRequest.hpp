#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>
#include <vector>

class PrivmsgRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::vector< std::string > &GetTargets() const;
    const std::string &GetMessage() const;

    void SetTargets(const std::vector< std::string > &targets);

    friend class PrivmsgRequestBuilder;

  private:
    PrivmsgRequest(Socket socket, const std::vector< std::string > &targets, const std::string &message);

  private:
    std::vector< std::string > mTargets;
    std::string mMessage;
};

class PrivmsgRequestBuilder : public RequestBuilder
{
  public:
    PrivmsgRequestBuilder &SetSocket(Socket socket) override;
    PrivmsgRequestBuilder &SetTargets(const std::vector< std::string > &targets);
    PrivmsgRequestBuilder &SetMessage(const std::string &message);

    Request *Build() override;

  private:
    Socket mSocket{};
    std::vector< std::string > mTargets{};
    std::string mMessage{};
};