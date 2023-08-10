#include "ModeRequest.hpp"

bool ModeRequest::Accept(visitor_pattern::Visitor *visitor)
{
    return visitor->Visit(this);
}

const std::string &ModeRequest::GetChannelname() const
{
    return mChannelname;
}

const std::string &ModeRequest::GetSign() const
{
    return mSign;
}

const std::string &ModeRequest::GetModeChar() const
{
    return mModeChar;
}

const std::string &ModeRequest::GetModeArgument() const
{
    return mModeArgument;
}

ModeRequest::ModeRequest(Socket socket, const std::string &channelname, const std::string &sign,
                         const std::string &modeChar, const std::string &modeArgument)
    : Request(socket)
{
}

ModeRequestBuilder &ModeRequestBuilder::SetSocket(Socket socket)
{
    mSocket = socket;
    return *this;
}

ModeRequestBuilder &ModeRequestBuilder::SetChannelname(const std::string &channelname)
{
    mChannelname = channelname;
    return *this;
}

ModeRequestBuilder &ModeRequestBuilder::SetSign(const std::string &sign)
{
    mSign = sign;
    return *this;
}

ModeRequestBuilder &ModeRequestBuilder::SetModeChar(const std::string &modeChar)
{
    mModeChar = modeChar;
    return *this;
}

ModeRequestBuilder &ModeRequestBuilder::SetModeArgument(const std::string &modeArgument)
{
    mModeArgument = modeArgument;
    return *this;
}

Request *ModeRequestBuilder::Build()
{
    return new ModeRequest(mSocket, mChannelname, mSign, mModeChar, mModeArgument);
}
