#include "stdafx.cpp"
#include "bdatabase.h"
using namespace std;
BDatabase::BDatabase() {//���캯����ʼ�������ļ�
	Book s;
	top = -1;
	fstream file;
	file.open("book.dat", ios::in | ios::binary);
	while (1) {
		file.read((char*)&s, sizeof(s));
		if (!file)break;
		top++;
		book[top] = s;
	}
	file.close();
}
void BDatabase::clear() { top = -1; }//ȫ��ɾ��
Book* BDatabase::query(int bookid) {//����ͼ��
	for (int i = 0; i <= top; i++)
		if (book[i].getnumber() == bookid && book[i].getnote() == 0)
			return &book[i];
	return NULL;
}
int BDatabase::addbook(int n, char* na) {//���ͼ��
	Book* p = query(n);
	if (p == NULL) {
		top++;
		book[top].addbook(n, na);
		fstream file;
		file.open("book.dat", ios::in | ios::binary);
		file.write((char*)&book[top], sizeof(book[top]));
		return 1;
		file.close();
	}
	return 0;
}
void BDatabase::list() {//���ͼ����Ϣ
	for (int i = 0; i <= top; i++)
		book[i].list();
}
BDatabase::~BDatabase() {//����������д�ļ�
	fstream file;
	file.open("book.dat", ios::in | ios::binary);
	for (int i = 0; i <= top; i++)
		if (book[i].getnote() == 0)
			file.read((char*)&book[i], sizeof(book[i])); 
	file.close();
	int kk = 0;
	for (int i = 3; i <= top; i++) {
		kk++;
		cout << "����ͼ����:" <<book[i].getnumber()<< endl;
		cout << "����ͼ������:" << book[i].getname() << endl;
	}
	cout << "����ͼ�飺" << kk << "��" << endl;
}
void BDatabase::bookdata() {//ͼ���ά��
	int choice = 1;
	char bookname[20];
	int bookid;
	Book* b;
	while (choice != 0) {
		cout << "ͼ��ά����" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�" << endl;
		cin >> choice;
		cout << "------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "����ͼ���ţ�";
			cin >> bookid;
			cout << "����ͼ������";
			cin >> bookname;
			addbook(bookid, bookname); break;
		case 2:cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			cout << "�����µ�ͼ������";
			cin >> bookname;
			b->setname(bookname); break;
		case 3:cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
		case 4:cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			b->list(); break;
		case 5:list(); break;
		case 6:break;
		}//end switch
	}//end while
}