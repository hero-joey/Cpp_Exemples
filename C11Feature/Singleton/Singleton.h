//
// Created by hero on 2022/6/11.
//

#ifndef C11FEATURE_SINGLETON_H
#define C11FEATURE_SINGLETON_H
#include <stdexcept>

template<typename T>
class Singleton
{
private:
    static T* m_pInstance;

public:
    template<typename ...Args>
    static T* Instance(Args&&... args)
    {
        if (m_pInstance == nullptr)
        {
            m_pInstance = new T(std::forward<Args>(args)...);
        }

        return m_pInstance;
    }

    static T* GetInstance()
    {
        if (m_pInstance == nullptr)
        {
            throw std::logic_error("the instance is not init, please initialize the instance first");
        }
        return m_pInstance;
    }

    static void DestroyInstance()
    {
        if (m_pInstance != nullptr)
        {
            delete m_pInstance;
            m_pInstance = nullptr;
        }
    }
};

template<typename T> T* Singleton<T>::m_pInstance = nullptr;

#endif //C11FEATURE_SINGLETON_H
