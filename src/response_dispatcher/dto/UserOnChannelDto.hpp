#pragma once

#include "Dto.hpp"
#include <string>

class UserOnChannelDto : public Dto
{
  public:
    const std::string &GetErrorCode() const;
    const std::string &GetNickname() const;
    const std::string &GetTargetNickname() const;
    const std::string &GetChannelname() const;
    const std::string &GetDescription() const;

    friend class UserOnChannelDtoBuilder;

  private:
    UserOnChannelDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                     const std::string &nickname, const std::string &targetNickname, const std::string &channelname);

  private:
    std::string mErrorCode{"443"};
    std::string mNickname;
    std::string mTargetNickname;
    std::string mChannelname;
    std::string mDescription{":is already on channel."};
};

class UserOnChannelDtoBuilder : public DtoBuilder
{
  public:
    UserOnChannelDtoBuilder &SetRecipient(std::shared_ptr< Client > &recipient) override;
    UserOnChannelDtoBuilder &SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel) override;

    UserOnChannelDtoBuilder &SetNickname(const std::string &nickname);
    UserOnChannelDtoBuilder &SetTargetNickname(const std::string &targetNickname);
    UserOnChannelDtoBuilder &SetChannelname(const std::string &channelname);

    UserOnChannelDto Build();

  private:
    std::shared_ptr< Client > mRecipient{};
    std::shared_ptr< Channel > mReceivingChannel{};

    std::string mNickname{};
    std::string mTargetNickname{};
    std::string mChannelname{};
};