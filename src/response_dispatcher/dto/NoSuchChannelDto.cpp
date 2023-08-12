#include "NoSuchChannelDto.hpp"

const std::string &NoSuchChannelDto::GetErrorCode() const
{
    return mErrorCode;
}

const std::string &NoSuchChannelDto::GetNickname() const
{
    return mNickname;
}

const std::string &NoSuchChannelDto::GetChannelname() const
{
    return mChannelName;
}

const std::string &NoSuchChannelDto::GetDescription() const
{
    return mDescription;
}

NoSuchChannelDto::NoSuchChannelDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                                   const std::string &nickname, const std::string &channelname)
    : Dto(recipient, receivingChannel)
{
}

NoSuchChannelDtoBuilder &NoSuchChannelDtoBuilder::SetRecipient(std::shared_ptr< Client > &recipient)
{
    mRecipient = recipient;
    return *this;
}

NoSuchChannelDtoBuilder &NoSuchChannelDtoBuilder::SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel)
{
    mReceivingChannel = receivingChannel;
    return *this;
}

NoSuchChannelDtoBuilder &NoSuchChannelDtoBuilder::SetNickname(const std::string &nickname)
{
    mNickname = nickname;
    return *this;
}

NoSuchChannelDtoBuilder &NoSuchChannelDtoBuilder::SetChannelname(const std::string &channelname)
{
    mChannelname = channelname;
    return *this;
}

NoSuchChannelDto NoSuchChannelDtoBuilder::Build()
{
    return NoSuchChannelDto(mRecipient, mReceivingChannel, mNickname, mChannelname);
}
