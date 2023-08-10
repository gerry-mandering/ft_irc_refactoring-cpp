#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>

class NickRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetNickname() const;

    friend class NickRequestBuilder;

  private:
    NickRequest(Socket socket, const std::string &nickname);

  private:
    std::string mNickname;
};

class NickRequestBuilder : public RequestBuilder
{
  public:
    NickRequestBuilder &SetNickname(const std::string &nickname);

    Request *Build() override;

  private:
    std::string mNickname{};
};