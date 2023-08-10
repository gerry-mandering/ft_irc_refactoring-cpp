#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>
#include <vector>

class JoinRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::vector< std::string > &GetChannelnames() const;
    const std::vector< std::string > &GetPasswords() const;

    void SetChannelnames(const std::vector< std::string > &channelnames);

    friend class JoinRequestBuilder;

  private:
    JoinRequest(Socket socket, const std::vector< std::string > &channelnames,
                const std::vector< std::string > &passwords);

  private:
    std::vector< std::string > mChannelnames;
    std::vector< std::string > mPasswords;
};

class JoinRequestBuilder : public RequestBuilder
{
  public:
    JoinRequestBuilder &SetChannelnames(const std::string &channelnames);
    JoinRequestBuilder &SetPasswords(const std::string &passwords);

    Request *Build() override;

  private:
    std::vector< std::string > mChannelnames;
    std::vector< std::string > mPasswords;
};