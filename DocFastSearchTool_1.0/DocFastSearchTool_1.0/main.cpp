#define _CRT_SECURE_NO_WARNINGS 1
#include "Common.h"
#include "Sysutil.h"

void Test_DirectoryList()
{
	string path = "E:\\比特\\课件\\C语言";//因为\为转义字符
	vector<string> subfile;//文件名
	vector<string> subdir;//目录名
	
	DirectoryList(path, subfile, subdir);

}

void main()
{
	Test_DirectoryList();
}