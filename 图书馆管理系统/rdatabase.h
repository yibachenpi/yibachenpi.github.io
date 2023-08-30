#pragma once
#ifndef _rdatabase_h_
#define _rdatabase_h_
#include "reader.h"
#include "stdafx.h"
const int Maxr = 100;//最大读者量
class RDatabase {//读者库类
private:
	int top;//读者记录指针
	Reader read[Maxr];//读者记录
public:
	RDatabase();//构造函数初始化：读文件
	void clear();//删除所有读者信息
	int addreader(int n, char* na);//添加读者记录时，先确定他是否已存在
	Reader* query(int readerid);//按编号查找
	void list();//输出所有读者信息
	void readerdata();//读者库维护
	~RDatabase();//析构函数：写文件
};
#endif