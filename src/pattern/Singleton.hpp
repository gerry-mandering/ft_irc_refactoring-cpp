#pragma once

template < class T >
class Singleton
{

  public:
    static T &GetInstance()
    {
        static T mInstance;
        return mInstance;
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

  protected:
    Singleton() = default;
    ~Singleton() = default;
};