#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>
#include <vector>

class PartRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::vector< std::string > &GetChannelnames() const;
    const std::string &GetReason() const;

    void SetChannelnames(const std::vector< std::string > &channelnames);

    friend class PartRequestBuilder;

  private:
    PartRequest(Socket socket, const std::vector< std::string > &channelnames, const std::string &reason);

  private:
    std::vector< std::string > mChannelnames;
    std::string mReason;
};

class PartRequestBuilder : public RequestBuilder
{
  public:
    PartRequestBuilder &SetChannelnames(const std::vector< std::string > &channelnames);
    PartRequestBuilder &SetReason(const std::string &reason);

    Request *Build() override;

  private:
    std::vector< std::string > mChannelnames{};
    std::string mReason{};
};