#include "TopicRequest.hpp"

bool TopicRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &TopicRequest::GetChannelname() const
{
    return mChannelname;
}

const std::string &TopicRequest::GetTopic() const
{
    return mTopic;
}

TopicRequest::TopicRequest(Socket socket, const std::string &channelname, const std::string &topic) : Request(socket) {}

TopicRequestBuilder &TopicRequestBuilder::SetSocket(Socket socket)
{
    mSocket = socket;
    return *this;
}

TopicRequestBuilder &TopicRequestBuilder::SetChannelname(const std::string &channelname)
{
    mChannelname = channelname;
    return *this;
}

TopicRequestBuilder &TopicRequestBuilder::SetTopic(const std::string &topic)
{
    mTopic = topic;
    return *this;
}

Request *TopicRequestBuilder::Build()
{
    return new TopicRequest(mSocket, mChannelname, mTopic);
}
