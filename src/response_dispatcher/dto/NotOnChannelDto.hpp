#pragma once

#include "Dto.hpp"
#include <string>

class NotOnChannelDto : public Dto
{
  public:
    const std::string &GetErrorCode() const;
    const std::string &GetNickname() const;
    const std::string &GetChannelname() const;
    const std::string &GetDescription() const;

    friend class NotOnChannelDtoBuilder;

  private:
    NotOnChannelDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                    const std::string &nickname, const std::string &channelname);

  private:
    std::string mErrorCode{"442"};
    std::string mNickname;
    std::string mChannelname;
    std::string mDescription{":You're not on that channel."};
};

class NotOnChannelDtoBuilder : public DtoBuilder
{
  public:
    NotOnChannelDtoBuilder &SetRecipient(std::shared_ptr< Client > &recipient) override;
    NotOnChannelDtoBuilder &SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel) override;

    NotOnChannelDtoBuilder &SetNickname(const std::string &nickname);
    NotOnChannelDtoBuilder &SetChannelname(const std::string &channelname);

    NotOnChannelDto Build();

  private:
    std::shared_ptr< Client > mRecipient{};
    std::shared_ptr< Channel > mReceivingChannel{};

    std::string mNickname{};
    std::string mChannnelname{};
};