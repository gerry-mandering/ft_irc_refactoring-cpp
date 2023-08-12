#pragma once

#include "Dto.hpp"
#include <string>

class NoSuchChannelDto : public Dto
{
  public:
    const std::string &GetErrorCode() const;
    const std::string &GetNickname() const;
    const std::string &GetChannelname() const;
    const std::string &GetDescription() const;

    friend class NoSuchChannelDtoBuilder;

  private:
    NoSuchChannelDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                     const std::string &nickname, const std::string &channelname);

  private:
    std::string mErrorCode{"403"};
    std::string mNickname;
    std::string mChannelName;
    std::string mDescription{":No such channel."};
};

class NoSuchChannelDtoBuilder : public DtoBuilder
{
  public:
    NoSuchChannelDtoBuilder &SetRecipient(std::shared_ptr< Client > &recipient) override;
    NoSuchChannelDtoBuilder &SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel) override;

    NoSuchChannelDtoBuilder &SetNickname(const std::string &nickname);
    NoSuchChannelDtoBuilder &SetChannelname(const std::string &channelname);

    NoSuchChannelDto Build();

  private:
    std::shared_ptr< Client > mRecipient{};
    std::shared_ptr< Channel > mReceivingChannel{};

    std::string mNickname{};
    std::string mChannelname{};
};