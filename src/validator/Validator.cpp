#include "Validator.hpp"
#include "Client.hpp"
#include "Dotenv.hpp"
#include "InviteRequest.hpp"
#include "JoinRequest.hpp"
#include "KickRequest.hpp"
#include "ModeRequest.hpp"
#include "NickRequest.hpp"
#include "NotRegisteredDto.hpp"
#include "PartRequest.hpp"
#include "PassRequest.hpp"
#include "PingRequest.hpp"
#include "PrivmsgRequest.hpp"
#include "QuitRequest.hpp"
#include "TopicRequest.hpp"
#include "UserRequest.hpp"
#include <memory>

bool Validator::Visit(InviteRequest *inviteRequest) const
{
    std::shared_ptr< Client > client = inviteRequest->GetClient();
    if (!client->HasRegistered())
    {
        NotRegisteredDto notRegisteredDto = NotRegisteredDtoBuilder()
                                                .SetRecipient(client)
                                                .SetRequestType("INVITE")
                                                .SetNickname(client->GetNickname())
                                                .Build();

        mResponseDispatcher.DispatchNotRegisteredMsg(notRegisteredDto);
        return false;
    }

    std::shared_ptr< Channel > channel = mChannelRepository->FindByName(inviteRequest->GetChannelname());
    if (!channel)
    {
        NoSuchChannelDto noSuchChannelDto = NoSuchChannelDtoBuilder()
                                                .SetRecipient(client)
                                                .SetNickname(client->GetNickname())
                                                .SetChannelname(inviteRequest->GetChannelname())
                                                .Build();

        mResponseDispatcher.DispatchNoSuchChannelMsg(noSuchChannelDto);
        return false;
    }

    std::shared_ptr< Client > targetClient = mClientRepository->FindByName(inviteRequest->GetNickname());
    if (!targetClient)
    {
        NoSuchNickDto noSuchNickDto = NoSuchNickDtoBuilder()
                                          .SetRecipient(client)
                                          .SetNickname(client->GetNickname())
                                          .SetTargetNickname(inviteRequest->GetNickname())
                                          .Build();

        mResponseDispatcher.DispatchNoSuchNickMsg(noSuchNickDto);
        return false;
    }

    if (!channel->IsClientExist(client))
    {
        NotOnChannelDto notOnChannelDto = NotOnChannelDtoBuilder()
                                              .SetRecipient(client)
                                              .SetNickname(client->GetNickname())
                                              .SetChannelname(inviteRequest->GetChannelname())
                                              .Build();

        mResponseDispatcher.DispatchNotOnChannelMsg(notOnChannelDto);
        return false;
    }

    if (channel->IsClientExist(targetClient))
    {
        UserOnChannelDto userOnChannelDto = UserOnChannelDtoBuilder()
                                                .SetRecipient(client)
                                                .SetNickname(client->GetNickname())
                                                .SetTargetNickname(inviteRequest->GetNickname())
                                                .SetChannelname(inviteRequest->GetChannelname())
                                                .Build();

        mResponseDispatcher.DispatchUserOnChannelMsg(userOnChannelDto);
        return false;
    }

    if (!channel->IsClientAdmin(client))
    {
        NotChannelOperatorDto notChannelOperatorDto = NotChannelOperatorDtoBuilder()
                                                          .SetRecipient(client)
                                                          .SetNickname(client->GetNickname())
                                                          .SetChannelName(inviteRequest->GetChannelname())
                                                          .Build();

        mResponseDispatcher.DispatchNotChannelOperatorMsg(notChannelOperatorDto);
        return false;
    }

    return true;
}

bool Validator::Visit(JoinRequest *joinRequest) const
{
    return true;
}

bool Validator::Visit(KickRequest *kickRequest) const
{
    return true;
}

bool Validator::Visit(ModeRequest *modeRequest) const
{
    return true;
}

bool Validator::Visit(NickRequest *nickRequest) const
{
    return true;
}

bool Validator::Visit(PartRequest *partRequest) const
{
    return true;
}

bool Validator::Visit(PassRequest *passRequest) const
{
    return true;
}

bool Validator::Visit(PingRequest *pingRequest) const
{
    return true;
}

bool Validator::Visit(PrivmsgRequest *privmsgRequest) const
{
    return true;
}

bool Validator::Visit(QuitRequest *quitRequest) const
{
    return true;
}

bool Validator::Visit(TopicRequest *topicRequest) const
{
    return true;
}

bool Validator::Visit(UserRequest *userRequest) const
{
    return true;
}
