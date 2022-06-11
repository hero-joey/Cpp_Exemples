// C11_Feature.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//可变参数模板函数
template<typename ...T>
void f(T... args)
{
    cout << sizeof...(args) << endl;
}

//递归终止函数1
//void print()
//{
//    cout << "Empty" << endl;
//}


template<typename T, typename T1, typename T2>
void print(T t, T1 t1, T2 t2)
{
    cout << "three param" << endl;
    cout << t << " " << t1 << " " << t2 << endl;
}

template<typename T, typename T1>
void print(T t, T1 t1)
{
    cout << "two param" << endl;
    cout << t << " " << t1 << endl;
}

//展开函数
template<typename T,  typename ...Args>
void print(T t, Args... rest)
{
    cout << "many param" << endl;
    cout << "Head: " << t << endl;
    print(rest...);
}


int main()
{
    f();
    f(1);
    f(1, 2, 3);

    print(1, 2, 3, 4, 5);
    print(1, 2);
    return 0;
}
