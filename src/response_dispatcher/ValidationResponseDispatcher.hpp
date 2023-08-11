#pragma once

#include "NotRegisteredDto.hpp"
#include "ResponseDispatcher.hpp"

class ValidationResponseDispatcher : public ResponseDispatcher
{
  public:
    void DispatchNotRegisteredMsg(const NotRegisteredDto &dto) const;
};