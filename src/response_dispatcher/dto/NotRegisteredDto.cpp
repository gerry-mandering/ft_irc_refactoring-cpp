#include "NotRegisteredDto.hpp"

const std::string &NotRegisteredDto::GetErrorCode() const
{
    return mErrorCode;
}

const std::string &NotRegisteredDto::GetNickname() const
{
    return mNickname;
}

const std::string &NotRegisteredDto::GetRequestType() const
{
    return mRequestType;
}

const std::string &NotRegisteredDto::GetDescription() const
{
    return mDescription;
}

NotRegisteredDto::NotRegisteredDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                                   const std::string &nickname, const std::string &requestType)
    : Dto(recipient, receivingChannel)
{
}

NotRegisteredDtoBuilder &NotRegisteredDtoBuilder::SetRecipient(std::shared_ptr< Client > &recipient)
{
    mRecipient = recipient;
    return *this;
}

NotRegisteredDtoBuilder &NotRegisteredDtoBuilder::SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel)
{
    mReceivingChannel = receivingChannel;
    return *this;
}

NotRegisteredDtoBuilder &NotRegisteredDtoBuilder::SetNickname(const std::string &nickname)
{
    if (nickname.empty())
    {
        mNickname = "*";
    }
    else
    {
        mNickname = nickname;
    }
    return *this;
}

NotRegisteredDtoBuilder &NotRegisteredDtoBuilder::SetRequestType(const std::string &requestType)
{
    mRequestType = requestType;
    return *this;
}

NotRegisteredDto NotRegisteredDtoBuilder::Build()
{
    return NotRegisteredDto(mRecipient, mReceivingChannel, mNickname, mRequestType);
}
