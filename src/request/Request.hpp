#pragma once

#include "Client.hpp"
#include <memory>

// FIXME
typedef int Socket;

class Request
{
  public:
    Request() = delete;
    virtual ~Request() = default;

    std::shared_ptr< Client > GetClient() const;

  protected:
    Request(Socket socket);

  private:
    Socket mSocket;
    std::shared_ptr< Client > mClient;
};

class RequestBuilder
{
  public:
    virtual ~RequestBuilder() = default;
    virtual RequestBuilder &SetSocket(Socket socket) = 0;
    virtual Request *Build() = 0;
};