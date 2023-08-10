#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>
#include <vector>

class PartRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::vector< std::string > &GetChannels() const;
    const std::string &GetReason() const;

    void SetChannels(const std::vector< std::string > &channels);

    friend class PartRequestBuilder;

  private:
    PartRequest(Socket socket, const std::vector< std::string > &channels, const std::string &reason);

  private:
    std::vector< std::string > mChannels;
    std::string mReason;
};

class PartRequestBuilder : public RequestBuilder
{
  public:
    PartRequestBuilder &SetChannels(const std::vector< std::string > &channels);
    PartRequestBuilder &SetReason(const std::string &reason);

    Request *Build() override;

  private:
    std::vector< std::string > mChannels{};
    std::string mReason{};
};