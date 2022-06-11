//
// Created by hero on 2022/6/11.
//
#include <string>
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <functional>
#define PRINT_NAME_VALUE(x) std::cout << #x << "=" << x << std::endl

void func1()
{
    std::cout << __FUNCTION__  << std::endl;
    std::cout << "T1 Thread Id:" << std::this_thread::get_id() <<std::endl;
}

void func2(int i, double d, std::string s)
{
    std::cout << "t2 thread" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    PRINT_NAME_VALUE(i);
    PRINT_NAME_VALUE(d);
    PRINT_NAME_VALUE(s);
}

void func3(int a, double b)
{
    PRINT_NAME_VALUE(a);
    PRINT_NAME_VALUE(b);
}

int main()
{
    int value = 1;
    //1.创建线程
    std::thread t1(func1);
    //2.调用join函数等待线程结束
    //获取当前线程Id
    std::cout << "T1 Thread Id:" << t1.get_id() << std::endl;
    t1.join();

    int i = 1;
    double d = 1.25;
    std::string s = "hello";
    std::thread t2(func2, 1, 1.25, "hello");
    t2.detach();

    //3.使用std::bind
    std::thread t3(std::bind(func3, i, d));
    t3.join();

    //4.使用lambda表达式
    std::thread t4(
            [](int a, double b) {
                PRINT_NAME_VALUE(a);
                PRINT_NAME_VALUE(b);
                },
        1, 2.05);
    t4.join();

    //获取cpu核心数
    std::cout << "cpu core:" << std::thread::hardware_concurrency() << std::endl;
    return 0;
}