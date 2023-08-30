#include "stdafx.cpp"
#include "rdatabase.h"
using namespace std;
RDatabase::RDatabase() {//���캯����ʼ�������ļ�
	Reader s;
	top = -1;
	ifstream file;
	file.open("reader.dat", ios::in | ios::binary);
	while (1) {
		file.read((char*)&s, sizeof(s));
		if (!file)break;
		top++;
		read[top] = s;
	}
	file.close();
}
void RDatabase::clear() {//ɾ�����ж�����Ϣ
	top = -1;
}
Reader* RDatabase::query(int readerid) {//����Ų���
	for (int i = 0; i <= top; i++) {
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
			return &read[i];
	}
	return NULL;
}
int RDatabase::addreader(int n, char* na) {//��Ӷ��߼�¼ʱ����ȷ�����Ƿ��Ѿ�����
	Reader* p = query(n);
	if (p == NULL) {
		top++;
		read[top].addreader(n, na);
		fstream file;
		file.open("reader.dat", ios::in | ios::binary);
		file.write((char*)&read[top], sizeof(read[top]));
		return 1;
	}
	return 0;
}
void RDatabase::list() {//������ж�����Ϣ
	for (int i = 0; i <= top; i++)
		read[i].list();
}
RDatabase::~RDatabase() {//����������д�ļ�
	fstream file;
	file.open("reader.dat", ios::in | ios::binary);
	for (int i = 0; i <= top; i++)
		if (read[i].getnote() == 0)
			file.read((char*)&read[i], sizeof(read[i]));
	file.close();
	for (int i = 3; i <= top; i++) {
		cout << "���ж��߱��:" << read[i].getnumber() << endl;
		cout << "���ж�������:" << read[i].getname() << endl;
	} 
}
void RDatabase::readerdata() {//���߿�ά��
	int choice = 1;
	char readername[20];
	int readerid;
	Reader* r;
	while (choice != 0) {
		cout << "����ά����" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�" << endl;
		cin >> choice;
		cout << "------------------------------------------------------" << endl;
		switch (choice) {
		case 1:cout << "������߱�ţ�";
			cin >> readerid;
			cout << "�������������";
			cin >> readername;
			addreader(readerid, readername); break;
		case 2:cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			cout << "�����µ����֣�";
			cin >> readername;
			r->setname(readername); break;
		case 3:cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
		case 4:cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			r->list(); break;
		case 5:list(); break;
		case 6:clear(); break;
		}//end switch
	}//end while
}