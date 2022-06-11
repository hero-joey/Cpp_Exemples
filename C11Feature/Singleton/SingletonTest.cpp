//
// Created by hero on 2022/6/11.
//
#include <iostream>
#include <ostream>
#include "Singleton.h"
class Manager : public Singleton<Manager>
{
private:
    std::string m_name;
    int m_version;
public:
    Manager(std::string name, int version) : m_name(std::move(name)), m_version(version)
    {

    }

    friend std::ostream &operator<<(std::ostream &os, const Manager &manager) {
        os  << " m_name: " << manager.m_name << " m_version: "
           << manager.m_version;
        return os;
    }

    void PrintInstance()
    {
        std::cout <<  this << std::endl;
    }
};

int main()
{
     Manager::Instance("VST", 1);

     Manager* managerA = Manager::GetInstance();
     managerA->PrintInstance();

     Manager* managerB = Manager::GetInstance();
     managerB->PrintInstance();

     Manager::DestroyInstance();
     return 0;
}
