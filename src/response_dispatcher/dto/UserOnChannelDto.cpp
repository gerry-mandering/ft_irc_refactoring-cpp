#include "UserOnChannelDto.hpp"

const std::string &UserOnChannelDto::GetErrorCode() const
{
    return mErrorCode;
}

const std::string &UserOnChannelDto::GetNickname() const
{
    return mNickname;
}

const std::string &UserOnChannelDto::GetTargetNickname() const
{
    return mTargetNickname;
}

const std::string &UserOnChannelDto::GetChannelname() const
{
    return mChannelname;
}

const std::string &UserOnChannelDto::GetDescription() const
{
    return mDescription;
}

UserOnChannelDto::UserOnChannelDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                                   const std::string &nickname, const std::string &targetNickname,
                                   const std::string &channelname)
    : Dto(recipient, receivingChannel)
{
}

UserOnChannelDtoBuilder &UserOnChannelDtoBuilder::SetRecipient(std::shared_ptr< Client > &recipient)
{
    mRecipient = recipient;
    return *this;
}

UserOnChannelDtoBuilder &UserOnChannelDtoBuilder::SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel)
{
    mReceivingChannel = receivingChannel;
    return *this;
}

UserOnChannelDtoBuilder &UserOnChannelDtoBuilder::SetNickname(const std::string &nickname)
{
    mNickname = nickname;
    return *this;
}

UserOnChannelDtoBuilder &UserOnChannelDtoBuilder::SetTargetNickname(const std::string &targetNickname)
{
    mTargetNickname = targetNickname;
    return *this;
}

UserOnChannelDtoBuilder &UserOnChannelDtoBuilder::SetChannelname(const std::string &channelname)
{
    mChannelname = channelname;
    return *this;
}

UserOnChannelDto UserOnChannelDtoBuilder::Build()
{
    return UserOnChannelDto(mRecipient, mReceivingChannel, mNickname, mTargetNickname, mChannelname);
}
