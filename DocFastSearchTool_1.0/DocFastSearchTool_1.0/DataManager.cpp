#define _CRT_SECURE_NO_WARNINGS 1
#include "DataManager.h"
#pragma comment(lib,"./sqlite/sqlite3.lib")

SqliteManager::SqliteManager(){}
SqliteManager::~SqliteManager(){}

void SqliteManager::Open(const string &path)
{
	char* zErrMsg = 0;
	int rc = sqlite3_open("doc.db", &m_db);
	if (rc)
	{
		ERROR_LOG("Can't open database");//�޷������ݿ�
		return;
	}
	else
	{
		TRACE_LOG("Opened database successfully");//�����ݿ�ɹ�
	}
}

void SqliteManager::Close()
{
	if (m_db)
	{
		int rc = sqlite3_close(m_db);//�ر����ݿ⣬����һ�����
		if (rc != SQLITE_OK)
		{
			ERROR_LOG("Close database failed");//�ر����ݿ�ʧ��
			return;
		}
		else
			TRACE_LOG("Close database successfully");//�ر����ݿ�ɹ�
		m_db = nullptr;
	}
}

void SqliteManager::ExecuteSql(const string &sql)
{
	char *zErrMsg = 0;
	int rc = sqlite3_exec(m_db, sql.c_str(), 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		ERROR_LOG("SQL error(sql: %s): %s\n", sql.c_str(), zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		TRACE_LOG("Exec Sql(sql:%s) successfully\n", sql.c_str());
	}
}

void SqliteManager::GetTable(const string &sql, int &row, int &col, char** &ppRet)
{
	char *zErrMsg = 0;
	int rc = sqlite3_get_table(m_db, sql.c_str(), &ppRet, &row, &col, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		ERROR_LOG("GetResTable error(sql: %s): %s\n", sql.c_str(), zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		TRACE_LOG("GetResTable  successfully");
	}
}

AuToGetResTable::AuToGetResTable(SqliteManager *db, const string &sql, int &row, int &col, char** &ppRet)
:m_db(db), m_ppRet(nullptr)//�Զ���ȡ����
{
	m_db->GetTable(sql, row, col, ppRet);
	m_ppRet = ppRet;
}

AuToGetResTable::~AuToGetResTable()
{
	if (m_ppRet)
		sqlite3_free_table(m_ppRet);
}

DataManager::DataManager()
{
	m_dbmgr.Open(DOC_DB);
	InitSqlite();//��ʼ�����ݿ�
}

void DataManager::InitSqlite()
{
	char sql[MAX_SQL_SIZE] = { 0 };
	//exists ��������  �����������ڣ��򴴽������
	sprintf(sql, "create table if not exists %s (id INTEGER PRIMARY KEY autoincrement, doc_path text, doc_name text)", DOC_TABLIE);
	m_dbmgr.ExecuteSql(sql);//ִ��SQL���
}

