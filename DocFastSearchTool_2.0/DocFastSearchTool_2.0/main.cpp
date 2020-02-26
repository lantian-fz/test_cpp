#define _CRT_SECURE_NO_WARNINGS 1
#include "Common.h"
#include "ScanManager.h"
#include "Sysutil.h"
#include "DataManager.h"

void Test_Search()
{
	string path = "E:\\����\\�μ�\\C����";//��Ϊ\Ϊת���ַ�
	ScanManager sm; 
	sm.ScanDirectory(path);
	
	string key;
	vector<pair<string, string>> doc_path;//�����������

	DataManager dm;

	while (1)
	{
		cout << "������Ҫ�����Ĺؼ��֣�";
		cin >> key;
		dm.Search(key, doc_path);
		printf("%-30s%-60s\n", "����", "·��");
		for (auto &e : doc_path)
		{
			string &name = e.first;
			string &path = e.second;
			printf("%-60s%-80s\n", name.c_str(), path.c_str());
		}
		doc_path.clear();
	}
}

void main()
{
	Test_Search();
}

//void Test_DirectoryList()
//{
//	string path = "E:\\����\\�μ�\\C����";//��Ϊ\Ϊת���ַ�
//	vector<string> subfile;//�ļ���
//	vector<string> subdir;//Ŀ¼��
//	
//	DirectoryList(path, subfile, subdir);
//
//}
//
//void main()
//{
//	Test_DirectoryList();
//}