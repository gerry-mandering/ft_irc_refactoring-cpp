#include "ValidationResponseDispatcher.hpp"
#include "Client.hpp"

void ValidationResponseDispatcher::DispatchNotRegisteredMsg(const NotRegisteredDto &dto) const
{
    std::string message = buildMessage(
        {getServerName(), dto.GetErrorCode(), dto.GetNickname(), dto.GetRequestType(), dto.GetDescription()});

    dto.GetRecipient()->AddResponse(message);
}
