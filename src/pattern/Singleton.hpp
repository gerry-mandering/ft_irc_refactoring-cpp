#pragma once

template < class T >
class Singleton
{

  public:
    static T &GetInstance()
    {
        if (mInstance == nullptr)
        {
            mInstance = new T;
        }
        return mInstance;
    }

    static void DeleteInstance()
    {
        if (mInstance != nullptr)
        {
            delete mInstance;
            mInstance = nullptr;
        }
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

  protected:
    Singleton() = default;
    ~Singleton() = default;

  private:
    static T *mInstance;
};

template < class T >
T *Singleton< T >::mInstance = nullptr;