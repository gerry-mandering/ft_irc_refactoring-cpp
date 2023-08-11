#pragma once

#include <memory>

class Client;
class Channel;

class Dto
{
  public:
    Dto() = delete;
    virtual ~Dto() = default;

    std::shared_ptr< Client > GetRecipient() const;
    std::shared_ptr< Channel > GetReceivingChannel() const;

  protected:
    Dto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel);

  private:
    std::shared_ptr< Client > mRecipient;
    std::shared_ptr< Channel > mReceivingChannel;
};

class DtoBuilder
{
  public:
    virtual ~DtoBuilder() = default;
    virtual DtoBuilder &SetRecipient(std::shared_ptr< Client > &recipient) = 0;
    virtual DtoBuilder &SetRecevingChannel(std::shared_ptr< Channel > &receivingChannel) = 0;
};