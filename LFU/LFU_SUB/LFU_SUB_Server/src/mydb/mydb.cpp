/*
 * mydb.cpp
 *
 * Author: Xiaoteng Hu
 * Date: 2017-01-06
 * Copyright (C) 2017 NAOC-TJUCS
 */

#include "mydb.h"

MYSQL *connection = NULL;
MYSQL mysql;

void init_db() {
	mysql_init(&mysql);									//初始化mysql
}

int conn_db(const char *hostname, const char *username, const char *password, const char *dbname) {
	if(connection) {
		mysql_close(connection);
	}

	connection = mysql_real_connect(&mysql, hostname, username, password, dbname, 0, 0, 0);//连接到mysql

	if(connection == NULL) {
		printf("%s\n", mysql_error(&mysql));
		return -1;											//连接失败，返回-1
	}

	printf("success connect to mysql\n");
	return 0;
}

//断开数据库连接
void disconn_db() {
	if (connection) {
		mysql_close(connection);
		connection = NULL;
	}
}

//执行有返回数据集的SQL语句
int open_db(const char *SQL) {
	int state = mysql_query(connection, SQL);				//执行SQL语句
	if(state != 0) {
		printf("%s\n", mysql_error(connection));
		return -1;											//执行失败，返回-1
	}

	MYSQL_RES *result = mysql_store_result(connection);	//得到查询结果

	if(result == (MYSQL_RES *) NULL) {
		printf("%s\n", mysql_error(connection));
		return -1;											//执行失败，返回-1
	} else {
		MYSQL_FIELD *sqlField;
		int iFieldCount = 0;

		//循环遍历所有字段
		while (1) {
			sqlField = mysql_fetch_field(result);
			if(sqlField == NULL) {
				break;
			}
			printf("%s\t", sqlField->name);					//向屏幕打印字段名
			iFieldCount++;
		}
		printf("\n");										//每一行结尾打印一个\n字符

		MYSQL_ROW sqlRow;
		//循环到每一行
		while (1) {
			sqlRow = mysql_fetch_row(result);
			if(sqlRow == NULL) {
				break;
			}

			//循环得到每一行中的每个字段
			for(int i = 0; i < iFieldCount; i++) {
				if(sqlRow[i] == NULL) {
					printf("NULL\t");							//如果值为NULL，屏幕打印为"NULL"
				} else {
					printf("%s\t", (const char *)sqlRow[i]);	//屏幕打印为字段内容
				}
			}
			printf("\n");										//每一行结尾打印一个\n字符
		}
		printf("query is ok, %u rows affected\n", (unsigned int)mysql_affected_rows(connection));
		mysql_free_result(result);
	}
	return 0;
}

//执行没有返回数据集的SQL语句
int exec_db(const char *SQL) {
	int state = mysql_query(connection, SQL);					//执行SQL语句
	if (state != 0) {
		printf("%s\n", mysql_error(connection));
		return -1;
	}
	printf("query is ok, %u rows affected\n", (unsigned int)mysql_affected_rows(connection));
	return 0;
}


int getCount(const char *SQL) {
	int state = mysql_query(connection, SQL);				//执行SQL语句
	if(state != 0) {
		printf("%s\n", mysql_error(connection));
		return -1;											//执行失败，返回-1
	}

	MYSQL_RES *result = mysql_store_result(connection);	//得到查询结果

	if(result == (MYSQL_RES *) NULL) {
		printf("%s\n", mysql_error(connection));
		return -1;											//执行失败，返回-1
	} else {
		MYSQL_FIELD *sqlField;
		int iFieldCount = 0;

		//循环遍历所有字段
		while (1) {
			sqlField = mysql_fetch_field(result);
			if(sqlField == NULL) {
				break;
			}
			iFieldCount++;
		}

		MYSQL_ROW sqlRow;
		//循环到每一行
		while (1) {
			sqlRow = mysql_fetch_row(result);
			if(sqlRow == NULL) {
				break;
			}

			//循环得到每一行中的每个字段
			for(int i = 0; i < iFieldCount; i++) {
				if(sqlRow[i] == NULL) {
					return -1;
				} else {
					return atoi(sqlRow[i]);
				}
			}
		}
		mysql_free_result(result);
	}
	return -1;
}


string getValue(const char *SQL) {
	int state = mysql_query(connection, SQL);				//执行SQL语句
	if(state != 0) {
		printf("%s\n", mysql_error(connection));
		return "";											//执行失败，返回-1
	}

	MYSQL_RES *result = mysql_store_result(connection);	//得到查询结果

	if(result == (MYSQL_RES *) NULL) {
		printf("%s\n", mysql_error(connection));
		return "";											//执行失败，返回-1
	} else {
		MYSQL_FIELD *sqlField;
		int iFieldCount = 0;

		//循环遍历所有字段
		while (1) {
			sqlField = mysql_fetch_field(result);
			if(sqlField == NULL) {
				break;
			}
			iFieldCount++;
		}

		MYSQL_ROW sqlRow;
		//循环到每一行
		while (1) {
			sqlRow = mysql_fetch_row(result);
			if(sqlRow == NULL) {
				break;
			}

			//循环得到每一行中的每个字段
			for(int i = 0; i < iFieldCount; i++) {
				if(sqlRow[i] == NULL) {
					return "";
				} else {
					return sqlRow[i];
				}
			}
		}
		mysql_free_result(result);
	}
	return "";
}

int updateInfo(const char *SQL) {
	int state = mysql_query(connection, SQL);					//执行SQL语句
	if (state != 0) {
		printf("%s\n", mysql_error(connection));
		return -1;
	}
	return 0;
}
