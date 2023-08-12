#pragma once

#include "Dto.hpp"
#include <string>

class NotChannelOperatorDto : public Dto
{
  public:
    const std::string &GetErrorCode() const;
    const std::string &GetNickname() const;
    const std::string &GetChannelname() const;
    const std::string &GetDescription() const;

    friend class NotChannelOperatorDtoBuilder;

  private:
    NotChannelOperatorDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                          const std::string &nickname, const std::string &channelname);

  private:
    std::string mErrorCode{"482"};
    std::string mNickname;
    std::string mChannelname;
    std::string mDescription{":You must be a channel operator."};
};

class NotChannelOperatorDtoBuilder : public DtoBuilder
{
  public:
    NotChannelOperatorDtoBuilder &SetRecipient(std::shared_ptr< Client > &recipient) override;
    NotChannelOperatorDtoBuilder &SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel) override;

    NotChannelOperatorDtoBuilder &SetNickname(const std::string &nickname);
    NotChannelOperatorDtoBuilder &SetChannelName(const std::string &channelname);

    NotChannelOperatorDto Build();

  private:
    std::shared_ptr< Client > mRecipient{};
    std::shared_ptr< Channel > mReceivingChannel{};

    std::string mNickname{};
    std::string mChannelname{};
};