#pragma once
#include "stdafx.cpp"
#include "reader.h"
using namespace std;
char* Reader::getname() {//�������
	return name;
}
int Reader::getnote() {//���ɾ�����
	return note;
}
int Reader::getnumber() {//��ö��߱��
	return number;
}
void Reader::setname(char na[]) {//������������Ҫ�����β�
	strcpy_s(name, na);
}
void Reader::addreader(int n, char* na) {//��Ӷ��ߣ���Ҫ��ź������βΣ�������������Ϊ0
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
void Reader::borrowbook(int bookid) {//�������
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] == 0) { borbook[i] = bookid; return; }
	}
}
int Reader::retbook(int bookid) {//�����鷵��1�������鷵��0
	for (int i = 0; i < Maxbor; i++) {
		if (borbook[i] == bookid) { borbook[i] = 0; return 1; }
	}
	return 0;
}
void Reader::list() {
	cout << setw(5) << number << setw(10) << name << "�����ţ�[";
	for (int i = 0; i < Maxbor; i++)
		if (borbook[i] != 0)cout << borbook[i] << " ";
	cout << "]" << endl;

}