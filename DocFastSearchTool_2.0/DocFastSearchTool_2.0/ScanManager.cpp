#define _CRT_SECURE_NO_WARNINGS 1
#include "ScanManager.h"

void ScanManager::ScanDirectory(const string &path)
{
	//1 ɨ�豾���ļ� �����д洢
	vector<string> local_files;
	vector<string> local_dirs;
	DirectoryList(path, local_files, local_dirs);
	set<string> local_set;
	local_set.insert(local_files.begin(), local_files.end());
	local_set.insert(local_dirs.begin(), local_dirs.end());

	//2 ɨ�����ݿ��ļ� �����д洢
	set<string> db_set;
	m_db.GetDocs(path, db_set);

	//3 �����ļ��Ա�
	auto local_it = local_set.begin();
	auto db_it = db_set.begin();
	while (local_it != local_set.end() && db_it != db_set.end())
	{
		if (*local_it < *db_it)
		{
			//�����ļ����ڣ����ݿ��ļ������ڣ������ݿ������ļ�
			//�����ļ�
			m_db.InsertDoc(path, *local_it);
			local_it++;
		}
		else if (*local_it > *db_it)
		{
			//�����ļ������ڣ����ݿ��ļ����ڣ������ݿ�ɾ���ļ�
			//ɾ���ļ�
			m_db.DeleteDoc(path, *db_it);
			db_it++;
		}
		else
		{
			//�����ļ����ڣ����ݿ��ļ�Ҳ���ڣ������ݿⲻ��
			local_it++;
			db_it++;
		}
	}
	while (local_it != local_set.end())
	{
		m_db.InsertDoc(path, *local_it);
		local_it++;
	}
	while (db_it != db_set.end())
	{
		m_db.DeleteDoc(path, *db_it);
		db_it++;
	}
	//�ݹ������Ŀ¼
	for (auto &dir : local_dirs)
	{
		string dir_path = path;
		dir_path += "\\";
		dir_path += dir;
		ScanDirectory(dir_path);
	}
}