#include "stdafx.cpp"
#include "rdatabase.h"
using namespace std;
RDatabase::RDatabase() {//构造函数初始化：读文件
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
void RDatabase::clear() {//删除所有读者信息
	top = -1;
}
Reader* RDatabase::query(int readerid) {//按编号查找
	for (int i = 0; i <= top; i++) {
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
			return &read[i];
	}
	return NULL;
}
int RDatabase::addreader(int n, char* na) {//添加读者记录时，先确定他是否已经存在
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
void RDatabase::list() {//输出所有读者信息
	for (int i = 0; i <= top; i++)
		read[i].list();
}
RDatabase::~RDatabase() {//析构函数：写文件
	fstream file;
	file.open("reader.dat", ios::in | ios::binary);
	for (int i = 0; i <= top; i++)
		if (read[i].getnote() == 0)
			file.read((char*)&read[i], sizeof(read[i]));
	file.close();
	for (int i = 3; i <= top; i++) {
		cout << "现有读者编号:" << read[i].getnumber() << endl;
		cout << "现有读者名称:" << read[i].getname() << endl;
	} 
}
void RDatabase::readerdata() {//读者库维护
	int choice = 1;
	char readername[20];
	int readerid;
	Reader* r;
	while (choice != 0) {
		cout << "读者维护：" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出" << endl;
		cin >> choice;
		cout << "------------------------------------------------------" << endl;
		switch (choice) {
		case 1:cout << "输入读者编号：";
			cin >> readerid;
			cout << "输入读者姓名：";
			cin >> readername;
			addreader(readerid, readername); break;
		case 2:cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "该读者不存在！" << endl;
				break;
			}
			cout << "输入新的名字：";
			cin >> readername;
			r->setname(readername); break;
		case 3:cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "该读者不存在！" << endl;
				break;
			}
		case 4:cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL) {
				cout << "该读者不存在！" << endl;
				break;
			}
			r->list(); break;
		case 5:list(); break;
		case 6:clear(); break;
		}//end switch
	}//end while
}