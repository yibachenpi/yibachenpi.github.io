#pragma once
#ifndef _book_h_
#define _book_h_
#include "stdafx.h"
class Book {
private:
	int note;//���ͼ��Ϊ0��ɾ��ͼ��Ϊ1
	int number;//ͼ����
	char name[10];//����
	int onshelf;//�ϼܱ�־�����飬����Ϊ1
public:
	Book() {};
	char* getname();//�������
	int getnote();//���ɾ�����
	int getnumber();//���ͼ����
	void setname(char na[]);//��������
	void delbook();//ɾ��ͼ��
	void addbook(int n, char* na);//���ͼ��
	int borrowbook();//�������
	void retbook();//�������
	void list();//���ͼ��
};
#endif