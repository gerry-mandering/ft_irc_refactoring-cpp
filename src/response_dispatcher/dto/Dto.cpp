#include "Dto.hpp"

std::shared_ptr< Client > Dto::GetRecipient() const
{
    return mRecipient;
}

std::shared_ptr< Channel > Dto::GetReceivingChannel() const
{
    return mReceivingChannel;
}

Dto::Dto(std::shared_ptr< Client > &recipient, std::shared_ptr< Channel > &receivingChannel)
    : mRecipient(recipient), mReceivingChannel(receivingChannel)
{
}
