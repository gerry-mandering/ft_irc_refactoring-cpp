#pragma once

#include "ChannelRepository.hpp"
#include "ClientRepository.hpp"
#include "ResponseDispatcher.hpp"
#include "Singleton.hpp"
#include "ValidationResponseDispatcher.hpp"
#include "VisitorPattern.hpp"

class Validator : public Singleton< Validator >, public visitor_pattern::Visitor
{
  public:
    ~Validator() override;

    bool Visit(InviteRequest *inviteRequest) const override;
    bool Visit(JoinRequest *joinRequest) const override;
    bool Visit(KickRequest *kickRequest) const override;
    bool Visit(ModeRequest *modeRequest) const override;
    bool Visit(NickRequest *nickRequest) const override;
    bool Visit(PartRequest *partRequest) const override;
    bool Visit(PassRequest *passRequest) const override;
    bool Visit(PingRequest *pingRequest) const override;
    bool Visit(PrivmsgRequest *privmsgRequest) const override;
    bool Visit(QuitRequest *quitRequest) const override;
    bool Visit(TopicRequest *topicRequest) const override;
    bool Visit(UserRequest *userRequest) const override;

  private:
    ClientRepository *mClientRepository{ClientRepository::GetInstance()};
    ChannelRepository *mChannelRepository{ChannelRepository::GetInstance()};
    ValidationResponseDispatcher mResponseDispatcher;
};