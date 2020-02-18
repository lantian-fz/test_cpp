#pragma once
#include "Common.h"
#include "Sysutil.h"
#include "./sqlite/sqlite3.h"

//�����ݿ�sqlite���з�װ
class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	void Open(const string &path);//�����ݿ�
	void Close();//�ر����ݿ�
	void ExecuteSql(const string &sql);//ִ��SQL���
	void GetTable(const string &sql, int &row, int &col, char** &ppRet);//��ȡ����
public:
	SqliteManager(const SqliteManager&) = delete;//���������ݿ������п�������
	SqliteManager& operator=(const SqliteManager&) = delete;//���������ݿ������и�ֵ
public:
	sqlite3 *m_db;//���ݿ����
};

#define DOC_DB "doc.db"
#define DOC_TABLIE "doc.tb"

//���ݿ����ģ��
class DataManager
{
public:
	DataManager();
	~DataManager();
public:
	void InitSqlite();//��ʼ�����ݿ�
public:
	void GetDocs(const string &path, set<string> &docs);//�����ݿ��ȡ����
	void InserDoc(const string &path, string doc);//�����ݿ�����ĵ�
	void DeleteDoc(const string &path, string doc);//�����ݿ�ɾ���ĵ�
public:
	void Search(const string &key, vector<pair<string, string>> &doc_path);
private:
	SqliteManager m_dbmgr;
};