#include "InviteRequest.hpp"

bool InviteRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &InviteRequest::GetNickname() const
{
    return mNickname;
}

const std::string &InviteRequest::GetChannelname() const
{
    return mChannelname;
}

InviteRequest::InviteRequest(Socket socket, const std::string &nickname, const std::string &channelname)
    : Request(socket)
{
}

//////////////////////////////////////////////////////////////////////////////////////////

InviteRequestBuilder &InviteRequestBuilder::SetNickname(const std::string &nickname)
{
    mNickname = nickname;
    return *this;
}

InviteRequestBuilder &InviteRequestBuilder::SetChannelname(const std::string &channelname)
{
    mChannelname = channelname;
    return *this;
}

Request *InviteRequestBuilder::Build()
{
    return new InviteRequest(mSocket, mNickname, mChannelname);
}
