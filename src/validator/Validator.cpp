#include "Validator.hpp"
#include "Client.hpp"
#include "InviteRequest.hpp"
#include "JoinRequest.hpp"
#include "KickRequest.hpp"
#include "ModeRequest.hpp"
#include "NickRequest.hpp"
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
    std::shared_ptr< Client > client = kickRequest->GetClient();
    if (!client->HasRegistered())
    {
        NotRegisteredDto notRegisteredDto = NotRegisteredDtoBuilder()
                                                .SetRecipient(client)
                                                .SetRequestType("KICK")
                                                .SetNickname(client->GetNickname())
                                                .Build();

        mResponseDispatcher.DispatchNotRegisteredMsg(notRegisteredDto);
        return false;
    }

    std::shared_ptr< Channel > channel = mChannelRepository->FindByName(kickRequest->GetChannelname());
    if (!channel)
    {
        NoSuchChannelDto noSuchChannelDto = NoSuchChannelDtoBuilder()
                                                .SetRecipient(client)
                                                .SetNickname(client->GetNickname())
                                                .SetChannelname(kickRequest->GetChannelname())
                                                .Build();

        mResponseDispatcher.DispatchNoSuchChannelMsg(noSuchChannelDto);
        return false;
    }

    std::vector< std::string > targets = kickRequest->GetTargets();
    std::vector< std::string > validatedTargets;

    for (auto target : targets)
    {
        std::shared_ptr< Client > targetClient = mClientRepository->FindByName(target);
        if (!targetClient)
        {
            NoSuchNickDto noSuchNickDto = NoSuchNickDtoBuilder()
                                              .SetRecipient(client)
                                              .SetNickname(client->GetNickname())
                                              .SetTargetNickname(target)
                                              .Build();

            mResponseDispatcher.DispatchNoSuchNickMsg(noSuchNickDto);
            continue;
        }

        if (!channel->IsClientExist(client))
        {
            NotOnChannelDto notOnChannelDto = NotOnChannelDtoBuilder()
                                                  .SetRecipient(client)
                                                  .SetNickname(client->GetNickname())
                                                  .SetChannelname(kickRequest->GetChannelname())
                                                  .Build();

            mResponseDispatcher.DispatchNotOnChannelMsg(notOnChannelDto);
            return false; // TODO 검증
        }

        if (!channel->IsClientExist(targetClient))
        {
            UserNotInChannelDto userNotInChannelDto = UserNotInChannelDtoBuilder();

            mResponseDispatcher.DispatchUserNotInChannelMsg(userNotInChannelDto);
            continue;
        }

        if (!channel->IsClientAdmin(client))
        {
            NotChannelOperatorDto notChannelOperatorDto = NotChannelOperatorDtoBuilder()
                                                              .SetRecipient(client)
                                                              .SetNickname(client->GetNickname())
                                                              .SetChannelName(kickRequest->GetChannelname())
                                                              .Build();

            mResponseDispatcher.DispatchNotChannelOperatorMsg(notChannelOperatorDto);
            return false; // TODO 검증
        }

        validatedTargets.push_back(target);
    }

    if (validatedTargets.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
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
