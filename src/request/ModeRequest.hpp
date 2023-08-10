#pragma once

#include "Request.hpp"
#include "VisitorPattern.hpp"
#include <string>

class ModeRequest : public Request, public visitor_pattern::Acceptor
{
  public:
    bool Accept(visitor_pattern::Visitor *visitor) override;

    const std::string &GetChannelname() const;
    const std::string &GetSign() const;
    const std::string &GetModeChar() const;
    const std::string &GetModeArgument() const;

    friend class ModeRequestBuilder;

  private:
    ModeRequest(Socket socket, const std::string &channelname, const std::string &sign, const std::string &modeChar,
                const std::string &modeArgument);

  private:
    std::string mChannelname;
    std::string mSign;
    std::string mModeChar;
    std::string mModeArgument;
};

class ModeRequestBuilder : public RequestBuilder
{
  public:
    ModeRequestBuilder &SetChannelname(const std::string &channelname);
    ModeRequestBuilder &SetSign(const std::string &sign);
    ModeRequestBuilder &SetModeChar(const std::string &modeChar);
    ModeRequestBuilder &SetModeArgument(const std::string &modeArgument);

    Request *Build() override;

  private:
    std::string mChannelname;
    std::string mSign;
    std::string mModeChar;
    std::string mModeArgument;
};