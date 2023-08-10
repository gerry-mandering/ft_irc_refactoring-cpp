#pragma once

#include "Client.hpp"
#include <memory>

// FIXME
typedef int Socket;

class Request
{
  public:
    Request(Socket socket);

    Request() = delete;
    virtual ~Request() = default;

    std::shared_ptr< Client > GetClient() const;

  private:
    Socket mSocket;
    std::weak_ptr< Client > mClient;
};

class RequestBuilder
{
  public:
    virtual ~RequestBuilder() = default;
    virtual Request *Build() = 0;

    RequestBuilder &SetSocket(Socket socket);

  public:
    Socket mSocket;
};