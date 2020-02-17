#define _CRT_SECURE_NO_WARNINGS 1
#include "Sysutil.h"

void DirectoryList(const string& path, vector<string>& subfile, vector<string>& subdir)
{
	string _path = path;
	_path += "\\*.*";
	struct _finddata_t file;
	long handle = _findfirst(_path.c_str(), &file);
	//long _findfirst(char *filespec, struct _finddata_t *fileinfo)
	//filespec：标明文件的字符串，可支持通配符。比如：*.c，则表示当前文件夹下的所有后缀为C的文件。 
	//fileinfo ：这里就是用来存放文件信息的结构体的指针。这个结构体必须在调用此函数前声明，不过不用初始化，
	//只要分配了内存空间就可以了。 函数成功后，函数会把找到的文件的信息放入这个结构体中
	//查找成功返回一个用于查找的唯一句柄，失败返回-1
	if (handle == -1)
	{
		perror("_findfirst");
		return;
	}
	do
	{
		if (file.name[0] == '.')
			continue;
		if (file.attrib&_A_SUBDIR)//_A_SUBDIR  判断是否为文件夹
			subdir.push_back(file.name);
		else
			subfile.push_back(file.name);
	} while (_findnext(handle, &file) == 0);
	//int _findnext( long handle, struct _finddata_t *fileinfo ); 
	//返回值： 若成功返回0，否则返回-1。 
	//参数： handle：即由_findfirst函数返回回来的句柄。 
	//	   fileinfo：文件信息结构体的指针。找到文件后，函数将该文件信息放入此结构体中
	for (auto e : subfile)
		cout << e << endl;
	for (auto e : subdir)
	{
		cout << e << endl;
		vector<string> _subfile;
		vector<string> _subdir;
		string tmp_path = path;
		tmp_path += "\\";
		tmp_path += e;//e为文件夹名
		DirectoryList(tmp_path, _subfile, _subdir);
	}
	_findclose(handle);
}
