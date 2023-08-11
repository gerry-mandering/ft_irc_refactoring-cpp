#pragma once

#include "Dto.hpp"
#include <string>

class NotRegisteredDto : public Dto
{
  public:
    const std::string &GetErrorCode() const;
    const std::string &GetNickname() const;
    const std::string &GetRequestType() const;
    const std::string &GetDescription() const;

    friend class NotRegisteredDtoBuilder;

  private:
    NotRegisteredDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                     const std::string &nickname, const std::string &requestType);

  private:
    std::string mErrorCode{"451"};
    std::string mNickname;
    std::string mRequestType;
    std::string mDescription{":You have not registered."};
};

class NotRegisteredDtoBuilder : public DtoBuilder
{
  public:
    NotRegisteredDtoBuilder &SetRecipient(std::shared_ptr< Client > &recipient) override;
    NotRegisteredDtoBuilder &SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel) override;

    NotRegisteredDtoBuilder &SetNickname(const std::string &nickname);
    NotRegisteredDtoBuilder &SetRequestType(const std::string &requestType);

    NotRegisteredDto Build();

  private:
    std::shared_ptr< Client > mRecipient{};
    std::shared_ptr< Channel > mReceivingChannel{};

    std::string mNickname{};
    std::string mRequestType{};
};