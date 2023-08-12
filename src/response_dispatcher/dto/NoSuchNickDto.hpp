#pragma once

#include "Dto.hpp"
#include <string>

class NoSuchNickDto : public Dto
{
  public:
    const std::string &GetErrorCode() const;
    const std::string &GetNickname() const;
    const std::string &GetTargetNickname() const;
    const std::string &GetDescription() const;

    friend class NoSuchNickDtoBuilder;

  private:
    NoSuchNickDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                  const std::string &nickname, const std::string &targetNickname);

  private:
    std::string mErrorCode{"401"};
    std::string mNickname;
    std::string mTargetNickname;
    std::string mDescription{":No such nick."};
};

class NoSuchNickDtoBuilder : public DtoBuilder
{
  public:
    NoSuchNickDtoBuilder &SetRecipient(std::shared_ptr< Client > &recipient) override;
    NoSuchNickDtoBuilder &SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel) override;

    NoSuchNickDtoBuilder &SetNickname(const std::string &nickname);
    NoSuchNickDtoBuilder &SetTargetNickname(const std::string &targetNickname);

    NoSuchNickDto Build();

  private:
    std::shared_ptr< Client > mRecipient{};
    std::shared_ptr< Channel > mReceivingChannel{};

    std::string mNickname{};
    std::string mTargetNickname{};
};