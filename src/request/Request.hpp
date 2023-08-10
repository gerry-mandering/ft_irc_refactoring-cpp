#pragma once

#include "Client.hpp"
#include "VisitorPattern.hpp"
#include <memory>

// FIXME
typedef int Socket;

class Request
{
  public:
    Request(Socket socket);

    Request() = delete;
    virtual ~Request() = default;

    shared_ptr< Client > GetClient() const;

  private:
    Socket mSocket;
    std::weak_ptr< Client > mClient;
};