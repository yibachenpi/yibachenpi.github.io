#pragma once
#ifndef _rdatabase_h_
#define _rdatabase_h_
#include "reader.h"
#include "stdafx.h"
const int Maxr = 100;//��������
class RDatabase {//���߿���
private:
	int top;//���߼�¼ָ��
	Reader read[Maxr];//���߼�¼
public:
	RDatabase();//���캯����ʼ�������ļ�
	void clear();//ɾ�����ж�����Ϣ
	int addreader(int n, char* na);//��Ӷ��߼�¼ʱ����ȷ�����Ƿ��Ѵ���
	Reader* query(int readerid);//����Ų���
	void list();//������ж�����Ϣ
	void readerdata();//���߿�ά��
	~RDatabase();//����������д�ļ�
};
#endif