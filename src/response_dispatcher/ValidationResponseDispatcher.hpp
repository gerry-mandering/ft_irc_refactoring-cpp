#pragma once

#include "NoSuchChannelDto.hpp"
#include "NoSuchNickDto.hpp"
#include "NotChannelOperatorDto.hpp"
#include "NotOnChannelDto.hpp"
#include "NotRegisteredDto.hpp"
#include "ResponseDispatcher.hpp"
#include "UserOnChannelDto.hpp"

class ValidationResponseDispatcher : public ResponseDispatcher
{
  public:
    void DispatchNotRegisteredMsg(const NotRegisteredDto &dto) const;
    void DispatchNoSuchChannelMsg(const NoSuchChannelDto &dto) const;
    void DispatchNoSuchNickMsg(const NoSuchNickDto &dto) const;
    void DispatchNotOnChannelMsg(const NotOnChannelDto &dto) const;
    void DispatchUserOnChannelMsg(const UserOnChannelDto &dto) const;
    void DispatchNotChannelOperatorMsg(const NotChannelOperatorDto &dto) const;
};