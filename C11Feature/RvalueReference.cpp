//
// Created by hero on 2022/6/11.
//
#include <iostream>
using namespace std;

//接受左值
void func(int& lvalue)
{
    cout << "lvalue=" << lvalue << endl;
}

//接受右值
void func(int&& rvalue)
{
    cout << "rvalue=" << rvalue << endl;
}


//递归终止函数1
void print()
{
}

//展开函数
template<typename T,  typename ...Args>
void print(T t, Args... rest)
{
    cout << "ele:" << t << endl;
    print(rest...);
}

//万能引用就是实现了功能，所谓万能引用就是同时支持左值参数和右值参数
template<typename T>
void function(T &&param) {
    func(param);
}

//万能引用, 完美转发, 一个参数
template<typename T>
void functionPerfect(T &&param) {
    func(std::forward<T>(param));
}

//万能引用, 完美转发, 多个参数
template<typename... Args>
void functionPerfect(Args&&... param)
{
    print(std::forward<Args>(param)...);
}

int main() {
    int x = 10;
    cout << "Simple forward:" << endl;
    function(x);                    // 左值
    function(10);                // 右值
    function(std::move(x));   // std::move(x) == static_cast<int&&>(x) 将左值转发为右值

    cout << "Perfect forward:" << endl;
    functionPerfect(x);
    functionPerfect(10);
    functionPerfect(std::move(x));   // std::move(x) == static_cast<int&&>(x) 将左值转发为右值

    functionPerfect(10, 11, 12, 20);
    return 0;
}