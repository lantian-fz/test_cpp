#define _CRT_SECURE_NO_WARNINGS 1
#include "Common.h"
#include "Sysutil.h"

void Test_DirectoryList()
{
	string path = "E:\\����\\�μ�\\C����";//��Ϊ\Ϊת���ַ�
	vector<string> subfile;//�ļ���
	vector<string> subdir;//Ŀ¼��
	
	DirectoryList(path, subfile, subdir);

}

void main()
{
	Test_DirectoryList();
}