#include "ResponseDispatcher.hpp"
#include "Dotenv.hpp"

ResponseDispatcher::ResponseDispatcher()
{
    std::string servername = Dotenv::GetInstance()->Get("SERVER_NAME");
    mServerName = leftPad(servername, ':');
}

const std::string &ResponseDispatcher::getServerName() const
{
    return mServerName;
}

const std::string &ResponseDispatcher::buildMessage(const std::vector< std::string > &fields) const
{
    std::string message;

    for (const auto &field : fields)
    {
        if (field == fields.front())
        {
            message.append(field);
        }
        else
        {
            message.append(leftPad(field));
        }
    }

    return message;
}

const std::string &ResponseDispatcher::leftPad(const std::string &str, char ch, int len) const
{
    std::string padding(len, ch);

    return padding + str;
}
