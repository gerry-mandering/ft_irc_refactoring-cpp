#include "NotChannelOperatorDto.hpp"

const std::string &NotChannelOperatorDto::GetErrorCode() const
{
    return mErrorCode;
}

const std::string &NotChannelOperatorDto::GetNickname() const
{
    return mNickname;
}

const std::string &NotChannelOperatorDto::GetChannelname() const
{
    return mChannelname;
}

const std::string &NotChannelOperatorDto::GetDescription() const
{
    return mDescription;
}

NotChannelOperatorDto::NotChannelOperatorDto(std::shared_ptr< Client > &recipient,
                                             std::shared_ptr< Channel > &receivingChannel, const std::string &nickname,
                                             const std::string &channelname)
    : Dto(recipient, receivingChannel)
{
}

NotChannelOperatorDtoBuilder &NotChannelOperatorDtoBuilder::SetRecipient(std::shared_ptr< Client > &recipient)
{
    mRecipient = recipient;
    return *this;
}

NotChannelOperatorDtoBuilder &NotChannelOperatorDtoBuilder::SetRecevingChannel(
    std::shared_ptr< Channel > &receivingChannel)
{
    mReceivingChannel = receivingChannel;
    return *this;
}

NotChannelOperatorDtoBuilder &NotChannelOperatorDtoBuilder::SetNickname(const std::string &nickname)
{
    mNickname = nickname;
    return *this;
}

NotChannelOperatorDtoBuilder &NotChannelOperatorDtoBuilder::SetChannelName(const std::string &channelname)
{
    mChannelname = channelname;
    return *this;
}

NotChannelOperatorDto NotChannelOperatorDtoBuilder::Build()
{
    return NotChannelOperatorDto(mRecipient, mReceivingChannel, mNickname, mChannelname);
}
