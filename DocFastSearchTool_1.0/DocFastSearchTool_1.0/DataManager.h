#pragma once
#include "Common.h"
#include "sqlite\sqlite3.h"

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

private:
	SqliteManager m_dbmgr;
};