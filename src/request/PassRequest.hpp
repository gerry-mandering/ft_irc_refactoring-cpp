#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>

class PassRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetPassword() const;

    friend class PassRequestBuilder;

  private:
    PassRequest(Socket socket, const std::string &password);

  private:
    std::string mPassword;
};

class PassRequestBuilder : public RequestBuilder
{
  public:
    PassRequestBuilder &SetPassword(const std::string &password);

    Request *Build() override;

  private:
    std::string mPassword{};
};