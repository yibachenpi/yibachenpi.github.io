#pragma once
#include "stdafx.cpp"
#include "reader.h"
using namespace std;
char* Reader::getname() {//获得姓名
	return name;
}
int Reader::getnote() {//获得删除标记
	return note;
}
int Reader::getnumber() {//获得读者编号
	return number;
}
void Reader::setname(char na[]) {//设置姓名，需要姓名形参
	strcpy_s(name, na);
}
void Reader::addreader(int n, char* na) {//添加读者，需要编号和姓名形参，他所借书名都为0
	note = 0;
	number = n;
	strcpy_s(name, na);
	for (int i = 0; i < Maxbor; i++) {
		borbook[i] = 0;
	}
}
void Reader::delbook() {
	note = 1;
}
void Reader::borrowbook(int bookid) {//添加书名
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] == 0) { borbook[i] = bookid; return; }
	}
}
int Reader::retbook(int bookid) {//还对书返回1，还错书返回0
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] == bookid) { borbook[i] = 0; return 1; }
	}
	return 0;
}
void Reader::list() {
	cout << setw(5) << number << setw(10) << name << "借书编号：[";
	for (int i = 0; i < Maxbor; i++)
		if (borbook[i] != 0)cout << borbook[i] << " ";
	cout << "]" << endl;

}