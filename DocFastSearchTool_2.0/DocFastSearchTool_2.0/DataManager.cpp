#define _CRT_SECURE_NO_WARNINGS 1

#include "DataManager.h"
#pragma comment(lib,"./sqlite/sqlite3.lib")

SqliteManager::SqliteManager() :m_db(nullptr)
{}
SqliteManager::~SqliteManager()
{
	Close();
}

void SqliteManager::Open(const string &path)
{
	int rc = sqlite3_open(DOC_DB, &m_db);
	if (rc!=SQLITE_OK)
	{
		ERROR_LOG("Can't open database无法打开数据库");//无法打开数据库
		return;
	}
	else
	{
		TRACE_LOG("Opened database successfully打开数据库成功");//打开数据库成功
	}
}

void SqliteManager::Close()
{
	if (m_db)
	{
		int rc = sqlite3_close(m_db);//关闭数据库，返回一个句柄
		if (rc != SQLITE_OK)
		{
			ERROR_LOG("Close database failed关闭数据库失败");//关闭数据库失败
			return;
		}
		else
			TRACE_LOG("Close database successfully关闭数据库成功");//关闭数据库成功
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
		ERROR_LOG("GetTable error(sql: %s): %s\n", sql.c_str(), zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		TRACE_LOG("GetTable  successfully");
	}
}

AuToGetResTable::AuToGetResTable(SqliteManager *db, const string &sql, int &row, int &col, char** &ppRet)
:m_db(db), m_ppRet(nullptr)//自动获取表结果
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
	InitSqlite();//初始化数据库
}

DataManager::~DataManager(){}


void DataManager::InitSqlite()
{
	char sql[MAX_SQL_SIZE] = { 0 };
	//exists 存在量词  如果这个表不存在，则创建这个表
	sprintf(sql, "create table if not exists %s (id INTEGER PRIMARY KEY autoincrement, doc_path text, doc_name text)", DOC_TABLIE);
	m_dbmgr.ExecuteSql(sql);//执行SQL语句
}

//从数据库中获取数据
void DataManager::GetDocs(const string &path, set<string> &docs)
{
	char sql[MAX_SQL_SIZE] = { 0 };
	sprintf(sql, "select doc_name from %s where doc_path='%s'", DOC_TABLIE, path.c_str());

	int row = 0, col = 0;
	char** ppRet = 0;
	AuToGetResTable at(&m_dbmgr, sql, row, col, ppRet);//获取结果表

	for (int i = 1; i <= row; i++)
		docs.insert(ppRet[i]);
}

//向数据库插入文档
void DataManager::InsertDoc(const string &path, string doc)
{
	char sql[MAX_SQL_SIZE] = { 0 };
	sprintf(sql, "insert into %s values(NULL,'%s','%s')", DOC_TABLIE, path.c_str(), doc.c_str());
	m_dbmgr.ExecuteSql(sql);
}

//从数据库删除文档
void DataManager::DeleteDoc(const string &path, string doc)
{
	char sql[MAX_SQL_SIZE] = { 0 };
	sprintf(sql, "delete from %s where doc_path='%s' and doc_name='%s'", DOC_TABLIE, path.c_str(), doc.c_str());
	m_dbmgr.ExecuteSql(sql);

	//递归删除子目录
	string doc_path = path;
	doc_path += "\\";
	sprintf(sql, "delete from %s where doc_path like '%s%%'", DOC_TABLIE, doc_path.c_str());
	m_dbmgr.ExecuteSql(sql);
}

//从数据库查找
void DataManager::Search(const string &key, vector<pair<string, string>> &doc_path)
{
	char sql[MAX_SQL_SIZE] = { 0 };
	sprintf(sql, "select doc_name,doc_path from %s where doc_name like '%%%s%%'", DOC_TABLIE, key.c_str());

	int row = 0, col = 0;
	char** ppRet = 0;
	AuToGetResTable at(&m_dbmgr, sql, row, col, ppRet);

	for (int i = 1; i <= row; i++)
		doc_path.push_back(make_pair(ppRet[i*col + 0], ppRet[i*col + 1]));
}