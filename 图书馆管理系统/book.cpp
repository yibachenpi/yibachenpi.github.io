#pragma once
#include "stdafx.cpp"
#include "book.h"
using namespace std;
char* Book::getname() {//�������
	return name;
}
int Book::getnote() {//���ɾ�����
	return note;
}
int Book::getnumber() {//���ͼ����
	return number;
}
void Book::setname(char na[]) {//������������Ҫ�������β�
	strcpy_s(name, na);
}
void Book::addbook(int n, char* na) {//���ͼ�飬ͼ���ź�������Ҫ�β�����
	note = 0;
	number = n;
	strcpy_s(name, na);
	onshelf = 1;

}
void Book::delbook() {//ɾ��ͼ��
	note = 1;
}
int Book::borrowbook() {//�ò��������Ϊ1�����Ϊoneself=0
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
