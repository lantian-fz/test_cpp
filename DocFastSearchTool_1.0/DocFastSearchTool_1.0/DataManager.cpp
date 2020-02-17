#define _CRT_SECURE_NO_WARNINGS 1
#include "DataManager.h"
#pragma comment(lib,"sqlite\sqlite3.lib")

SqliteManager::SqliteManager(){}
SqliteManager::~SqliteManager(){}

void SqliteManager::Open(const string &path)
{
	char* zErrMsg = 0;
	int rc = sqlite3_open("doc.db", &m_db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
		exit(0);
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}
}