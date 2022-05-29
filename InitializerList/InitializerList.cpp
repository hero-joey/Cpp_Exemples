// InitializerList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include  <vector>
#include <set>
#include <initializer_list>

class Foo
{
public:
    Foo(std::initializer_list<int>)
    {
	    
    }

    Foo(int a)
    {
	    
    }
private:
    Foo(const Foo& foo)
    {
	    
    }
};

Foo func()
{
    //return Foo{123}; 会调用拷贝构造函数
    return { 123 };   //列表初始化直接使用在函数返回值上
}

struct A
{
    int x;
    struct B
    {
        int i;
        int j;
    }b;
}a{ 1, {2, 3} };  //pod类型

class FooVector
{
    std::vector<int> m_content;

public:
    FooVector(std::initializer_list<int> list)
    {
	    for (auto& it : list)
	    {
            m_content.push_back(it);
	    }
    }
};

void InitializerListFunc(std::initializer_list<int> list)
{
    std::cout  << "initializer list size: " << list.size() << std::endl;
    for (const auto& it : list)
    {
        std::cout << it << std::endl;
    }
}

class FooMap
{
    std::map<int, int> m_content;
    using pair_t = std::map<int, int>::value_type;

public:
    FooMap(std::initializer_list<pair_t> list)
    {
        for (auto& it : list)
        {
            m_content.insert(it);
        }
    }
};

std::initializer_list<int> GetInitializerList()
{
    int a = 1;
    int b = 2;
    return { a, b };  //a.b再返回时，并没有拷贝
}


int main()
{
    Foo a1(123);
    //Foo a2 = 123;       //error，调用拷贝构造函数
    Foo a3 = { 123 }; //列表初始化，不调用拷贝构造函数
    Foo a4{ 123 };

    int arr[3]{ 1, 2, 3 };  //普通数组
    int* a2 = new int { 123 };    //指针a2, 列表初始化
    double b = double {12.12 };   //匿名对象使用初始化列表
    int* pArr = new int[3] {1, 2, 3};  //堆元素初始化列表

    std::map<std::string, int> map1{ {"1", 1}, {"2", 2}, {"3", 3} };
    std::set<int> set1{1, 2, 3};
    std::vector<int> vec1 = {1, 2, 3, 4, 5};

    Foo a5 = {1, 2, 3, 4, 5};
    FooVector fooVec {1, 2, 3, 4, 5};
    FooMap fooMap {{1,2}, {3, 4}, {5 ,6}};

    InitializerListFunc({});
    InitializerListFunc({ 1, 2, 3 });  //遍历其中元素

    std::initializer_list<int> list = {1, 2, 3};
    std::cout << list.size() << std::endl;

    list = { 3, 1, 2, 4 };
    std::cout << list.size() << std::endl;

	//initializer_list内部并不保存初始化列表元素的拷贝, 仅仅存储了列表元素的引用而已
    //错误例程
    std::initializer_list<int> wrongAddr = GetInitializerList();
    std::cout << wrongAddr.size() << std::endl;
    return 0;
}

