#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>

class QuitRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetReason() const;

    friend class QuitRequestBuilder;

  private:
    QuitRequest(Socket socket, const std::string &reason);

  private:
    std::string mReason;
};

class QuitRequestBuilder : public RequestBuilder
{
  public:
    QuitRequestBuilder &SetReason(const std::string &reason);

    Request *Build() override;

  private:
    std::string mReason{};
};
