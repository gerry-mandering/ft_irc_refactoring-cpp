#include "ValidationResponseDispatcher.hpp"
#include "Client.hpp"

void ValidationResponseDispatcher::DispatchNotRegisteredMsg(const NotRegisteredDto &dto) const
{
    std::string message = buildMessage(
        {getServerName(), dto.GetErrorCode(), dto.GetNickname(), dto.GetRequestType(), dto.GetDescription()});

    dto.GetRecipient()->AddResponse(message);
}

void ValidationResponseDispatcher::DispatchNoSuchChannelMsg(const NoSuchChannelDto &dto) const
{
    std::string message = buildMessage(
        {getServerName(), dto.GetErrorCode(), dto.GetNickname(), dto.GetChannelname(), dto.GetDescription()});

    dto.GetRecipient()->AddResponse(message);
}

void ValidationResponseDispatcher::DispatchNoSuchNickMsg(const NoSuchNickDto &dto) const
{
    std::string message = buildMessage(
        {getServerName(), dto.GetErrorCode(), dto.GetNickname(), dto.GetTargetNickname(), dto.GetDescription()});

    dto.GetRecipient()->AddResponse(message);
}

void ValidationResponseDispatcher::DispatchNotOnChannelMsg(const NotOnChannelDto &dto) const
{
    std::string message = buildMessage(
        {getServerName(), dto.GetErrorCode(), dto.GetNickname(), dto.GetChannelname(), dto.GetDescription()});

    dto.GetRecipient()->AddResponse(message);
}

void ValidationResponseDispatcher::DispatchUserOnChannelMsg(const UserOnChannelDto &dto) const
{
    std::string message = buildMessage({getServerName(), dto.GetErrorCode(), dto.GetNickname(), dto.GetTargetNickname(),
                                        dto.GetChannelname(), dto.GetDescription()});

    dto.GetRecipient()->AddResponse(message);
}

void ValidationResponseDispatcher::DispatchNotChannelOperatorMsg(const NotChannelOperatorDto &dto) const
{
    std::string message = buildMessage(
        {getServerName(), dto.GetErrorCode(), dto.GetNickname(), dto.GetChannelname(), dto.GetDescription()});

    dto.GetRecipient()->AddResponse(message);
}
