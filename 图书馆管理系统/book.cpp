#pragma once
#include "stdafx.cpp"
#include "book.h"
using namespace std;
char* Book::getname() {//获得书名
	return name;
}
int Book::getnote() {//获得删除标记
	return note;
}
int Book::getnumber() {//获得图书编号
	return number;
}
void Book::setname(char na[]) {//设置书名，需要名称作形参
	strcpy_s(name, na);
}
void Book::addbook(int n, char* na) {//添加图书，图书编号和名称需要形参输入
	note = 0;
	number = n;
	strcpy_s(name, na);
	onshelf = 1;

}
void Book::delbook() {//删除图书
	note = 1;
}
int Book::borrowbook() {//该操作后如果为1，需改为oneself=0
	if (onshelf == 1) {
		onshelf = 0;
		return 1;
	}
	else return 0;
}
void Book::retbook() {
	onshelf = 1;
}
void Book::list() {
	cout << setw(5) << number << setw(10) << name << setw(10) << onshelf << endl;
}
