#pragma once
#include "Common.h"
#include "Sysutil.h"
#include "./sqlite/sqlite3.h"

//对数据库sqlite进行封装
class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	void Open(const string &path);//打开数据库
	void Close();//关闭数据库
	void ExecuteSql(const string &sql);//执行SQL语句
	void GetTable(const string &sql, int &row, int &col, char** &ppRet);//获取表结果
public:
	SqliteManager(const SqliteManager&) = delete;//不允许数据库对象进行拷贝构造
	SqliteManager& operator=(const SqliteManager&) = delete;//不允许数据库对象进行赋值
public:
	sqlite3 *m_db;//数据库对象
};

#define DOC_DB "doc.db"
#define DOC_TABLIE "doc.tb"

//数据库管理模块
class DataManager
{
public:
	DataManager();
	~DataManager();
public:
	void InitSqlite();//初始化数据库
public:
	void GetDocs(const string &path, set<string> &docs);//从数据库获取数据
	void InserDoc(const string &path, string doc);//向数据库插入文档
	void DeleteDoc(const string &path, string doc);//向数据库删除文档
public:
	void Search(const string &key, vector<pair<string, string>> &doc_path);
private:
	SqliteManager m_dbmgr;
};