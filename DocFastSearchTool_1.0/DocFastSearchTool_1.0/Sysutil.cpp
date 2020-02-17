#define _CRT_SECURE_NO_WARNINGS 1
#include "Sysutil.h"

void DirectoryList(const string& path, vector<string>& subfile, vector<string>& subdir)
{
	string _path = path;
	_path += "\\*.*";
	struct _finddata_t file;
	long handle = _findfirst(_path.c_str(), &file);
	//long _findfirst(char *filespec, struct _finddata_t *fileinfo)
	//filespec�������ļ����ַ�������֧��ͨ��������磺*.c�����ʾ��ǰ�ļ����µ����к�׺ΪC���ļ��� 
	//fileinfo �����������������ļ���Ϣ�Ľṹ���ָ�롣����ṹ������ڵ��ô˺���ǰ�������������ó�ʼ����
	//ֻҪ�������ڴ�ռ�Ϳ����ˡ� �����ɹ��󣬺�������ҵ����ļ�����Ϣ��������ṹ����
	//���ҳɹ�����һ�����ڲ��ҵ�Ψһ�����ʧ�ܷ���-1
	if (handle == -1)
	{
		perror("_findfirst");
		return;
	}
	do
	{
		if (file.name[0] == '.')
			continue;
		if (file.attrib&_A_SUBDIR)//_A_SUBDIR  �ж��Ƿ�Ϊ�ļ���
			subdir.push_back(file.name);
		else
			subfile.push_back(file.name);
	} while (_findnext(handle, &file) == 0);
	//int _findnext( long handle, struct _finddata_t *fileinfo ); 
	//����ֵ�� ���ɹ�����0�����򷵻�-1�� 
	//������ handle������_findfirst�������ػ����ľ���� 
	//	   fileinfo���ļ���Ϣ�ṹ���ָ�롣�ҵ��ļ��󣬺��������ļ���Ϣ����˽ṹ����
	for (auto e : subfile)
		cout << e << endl;
	for (auto e : subdir)
	{
		cout << e << endl;
		vector<string> _subfile;
		vector<string> _subdir;
		string tmp_path = path;
		tmp_path += "\\";
		tmp_path += e;//eΪ�ļ�����
		DirectoryList(tmp_path, _subfile, _subdir);
	}
	_findclose(handle);
}
