#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

//饿汉模式
class Test
{
public:
	static Test* GetInstance(){ return &m_instance; }
private:
	//构造函数私有
	Test(){}

	//C++98 防拷贝
	//Test(Test const&);
	//Test& operator=(Test const&);

	//or
	//C++11
	Test(Test const&) = delete;
	Test& operator=(Test const&) = delete;

	static Test m_instance;
};

Test Test::m_instance;//在程序入口之前就完成了单例对象的初始化

//////////////////////////////////////////////////////////

//懒汉模式
class Singleton
{
public:
	static Singleton* GetInstance() 
	{
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == m_pInstance) 
		{
			m_mtx.lock();
			if (nullptr == m_pInstance) 
				m_pInstance = new Singleton();
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// 实现一个内嵌垃圾回收类
	class CGarbo 
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	Singleton(){};
	// 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance; // 单例对象指针
	static mutex m_mtx; //互斥锁
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n){cout << Singleton::GetInstance() << endl;}

// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}
