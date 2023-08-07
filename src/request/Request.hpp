#pragma once

#include "Client.hpp"
#include "VisitorPattern.hpp"
#include <memory>

class Request : public visitor_pattern::Acceptor
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