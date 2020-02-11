#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

void main()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc = sqlite3_open("test.db", &db);
	char *sql_1 = "insert into tb_doc values(null, 'java.pdf', 'd:\\');";
	char *sql_2 = "insert into tb_doc values(null, 'kotlin.pdf', 'e:\\');";
	rc = sqlite3_exec(db, sql_1, 0, 0, zErrMsg);
	rc = sqlite3_exec(db, sql_2, 0, 0, zErrMsg);

	sqlite3_close(db);
}

//void main()
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc = sqlite3_open("test.db", &db);
//	char *sql_1 = "create table tb_doc(id integer primary key autoincrement, doc_name, doc_path)";
//	char *sql_2 = "insert into tb_doc values(null, 'c++.pdf', 'c:\\')";
//	rc = sqlite3_exec(db, sql_1, 0, 0, zErrMsg);//
//	rc = sqlite3_exec(db, sql_2, 0, 0, zErrMsg);
//
//	//if (rc != SQLITE_OK)
//	//{
//	//	printf("打开test.db失败\n");
//	//	return;
//	//}
//	sqlite3_close(db);
//}

//int main()
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//
//	rc = sqlite3_open("test.db",&db);
//	if(rc)
//	{
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	}
//	else
//	{
//		fprintf(stderr, "Opened database successfully\n");
//	}
//	return 0;
//}
