#include "NoSuchNickDto.hpp"

const std::string &NoSuchNickDto::GetErrorCode() const
{
    return mErrorCode;
}

const std::string &NoSuchNickDto::GetNickname() const
{
    return mNickname;
}

const std::string &NoSuchNickDto::GetTargetNickname() const
{
    return mTargetNickname;
}

const std::string &NoSuchNickDto::GetDescription() const
{
    return mDescription;
}

NoSuchNickDto::NoSuchNickDto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel,
                             const std::string &nickname, const std::string &targetNickname)
    : Dto(recipient, receivingChannel)
{
}

NoSuchNickDtoBuilder &NoSuchNickDtoBuilder::SetRecipient(std::shared_ptr< Client > &recipient)
{
    mRecipient = recipient;
}

NoSuchNickDtoBuilder &NoSuchNickDtoBuilder::SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel)
{
    mReceivingChannel = receivingChannel;
}

NoSuchNickDtoBuilder &NoSuchNickDtoBuilder::SetNickname(const std::string &nickname)
{
    mNickname = nickname;
}

NoSuchNickDtoBuilder &NoSuchNickDtoBuilder::SetTargetNickname(const std::string &targetNickname)
{
    mTargetNickname = targetNickname;
}

NoSuchNickDto NoSuchNickDtoBuilder::Build()
{
    return NoSuchNickDto(mRecipient, mReceivingChannel, mNickname, mTargetNickname);
}
