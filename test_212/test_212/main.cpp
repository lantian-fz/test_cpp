#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

//����ģʽ
class Test
{
public:
	static Test* GetInstance(){ return &m_instance; }
private:
	//���캯��˽��
	Test(){}

	//C++98 ������
	//Test(Test const&);
	//Test& operator=(Test const&);

	//or
	//C++11
	Test(Test const&) = delete;
	Test& operator=(Test const&) = delete;

	static Test m_instance;
};

Test Test::m_instance;//�ڳ������֮ǰ������˵�������ĳ�ʼ��

//////////////////////////////////////////////////////////

//����ģʽ
class Singleton
{
public:
	static Singleton* GetInstance() 
	{
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == m_pInstance) 
		{
			m_mtx.lock();
			if (nullptr == m_pInstance) 
				m_pInstance = new Singleton();
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// ʵ��һ����Ƕ����������
	class CGarbo 
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:
	// ���캯��˽��
	Singleton(){};
	// ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance; // ��������ָ��
	static mutex m_mtx; //������
};
Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n){cout << Singleton::GetInstance() << endl;}

// ���̻߳�������ʾ����GetInstance()�����Ͳ�����������
int main()
{
	thread t1(func, 10);
	thread t2(func, 10);
	t1.join();
	t2.join();
	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
}
