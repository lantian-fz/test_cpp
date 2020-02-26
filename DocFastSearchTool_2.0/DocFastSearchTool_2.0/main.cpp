#define _CRT_SECURE_NO_WARNINGS 1
#include "Common.h"
#include "ScanManager.h"
#include "Sysutil.h"
#include "DataManager.h"

void Test_Search()
{
	string path = "E:\\比特\\课件\\C语言";//因为\为转义字符
	ScanManager sm; 
	sm.ScanDirectory(path);
	
	string key;
	vector<pair<string, string>> doc_path;//保存搜索结果

	DataManager dm;

	while (1)
	{
		cout << "请输入要搜索的关键字：";
		cin >> key;
		dm.Search(key, doc_path);
		printf("%-30s%-60s\n", "名称", "路径");
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
//	string path = "E:\\比特\\课件\\C语言";//因为\为转义字符
//	vector<string> subfile;//文件名
//	vector<string> subdir;//目录名
//	
//	DirectoryList(path, subfile, subdir);
//
//}
//
//void main()
//{
//	Test_DirectoryList();
//}