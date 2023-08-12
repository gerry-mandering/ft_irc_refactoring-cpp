#include "NotOnChannelDto.hpp"

const std::string &NotOnChannelDto::GetErrorCode() const
{
    return mErrorCode;
}

const std::string &NotOnChannelDto::GetNickname() const
{
    return mNickname;
}

const std::string &NotOnChannelDto::GetChannelname() const
{
    return mChannelname;
}

const std::string &NotOnChannelDto::GetDescription() const
{
    return mDescription;
}

NotOnChannelDto::NotOnChannelDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                                 const std::string &nickname, const std::string &channelname)
    : Dto(recipient, receivingChannel)
{
}

NotOnChannelDtoBuilder &NotOnChannelDtoBuilder::SetRecipient(std::shared_ptr< Client > &recipient)
{
    mRecipient = recipient;
    return *this;
}

NotOnChannelDtoBuilder &NotOnChannelDtoBuilder::SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel)
{
    mReceivingChannel = receivingChannel;
    return *this;
}

NotOnChannelDtoBuilder &NotOnChannelDtoBuilder::SetNickname(const std::string &nickname)
{
    mNickname = nickname;
    return *this;
}

NotOnChannelDtoBuilder &NotOnChannelDtoBuilder::SetChannelname(const std::string &channelname)
{
    mChannnelname = channelname;
    return *this;
}

NotOnChannelDto NotOnChannelDtoBuilder::Build()
{
    return NotOnChannelDto(mRecipient, mReceivingChannel, mNickname, mChannnelname);
}
