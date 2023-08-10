#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>

class PingRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetToken() const;

    friend class PingRequestBuilder;

  private:
    PingRequest(Socket socket, const std::string &token);

  private:
    std::string mToken;
};

class PingRequestBuilder : public RequestBuilder
{
  public:
    PingRequestBuilder &SetToken(const std::string &token);

    Request *Build() override;

  private:
    std::string mToken{};
};