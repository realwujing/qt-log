
#pragma once

template<typename T>
class Singleton
{
public:
    static T* instance()
    {
        static T instance;
        return &instance;
    }

    Singleton(T&&) = delete;
    Singleton(const T&) = delete;
    void operator= (const T&) = delete;

protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};