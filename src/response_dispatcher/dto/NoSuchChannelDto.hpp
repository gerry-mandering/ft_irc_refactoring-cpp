#pragma once

#include "Dto.hpp"
#include <string>

class NotSuchChannelDto : public Dto
{
  public:
    const std::string &GetNickname() const;
    const std::string &GetChannelname() const;

    friend class NotSuchChannelDtoBuilder;

  private:
    NotRegisteredDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                     const std::string &requestType, const std::string &nickname);

  private:
    std::string mRequestType;
    std::string mNickname;
};

class NotSuchChannelDtoBuilder : public DtoBuilder
{
  public:
    NotRegisteredDtoBuilder &SetRecipient(std::shared_ptr< Client > &recipient) override;
    NotRegisteredDtoBuilder &SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel) override;

    NotRegisteredDtoBuilder &SetNickname(const std::string &nickname);
    NotRegisteredDtoBuilder &SetChannelname(const std::string &channelname);

    NotRegisteredDto Build();

  private:
    std::shared_ptr< Client > mRecipient{};
    std::shared_ptr< Channel > mReceivingChannel{};

    std::string mRequestType{};
    std::string mNickname{};
};