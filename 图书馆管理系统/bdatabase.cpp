#include "stdafx.cpp"
#include "bdatabase.h"
using namespace std;
BDatabase::BDatabase() {//构造函数初始化，读文件
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
void BDatabase::clear() { top = -1; }//全部删除
Book* BDatabase::query(int bookid) {//查找图书
	for (int i = 0; i <= top; i++)
		if (book[i].getnumber() == bookid && book[i].getnote() == 0)
			return &book[i];
	return NULL;
}
int BDatabase::addbook(int n, char* na) {//添加图书
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
void BDatabase::list() {//输出图书信息
	for (int i = 0; i <= top; i++)
		book[i].list();
}
BDatabase::~BDatabase() {//析构函数，写文件
	fstream file;
	file.open("book.dat", ios::in | ios::binary);
	for (int i = 0; i <= top; i++)
		if (book[i].getnote() == 0)
			file.read((char*)&book[i], sizeof(book[i])); 
	file.close();
	int kk = 0;
	for (int i = 3; i <= top; i++) {
		kk++;
		cout << "现有图书编号:" <<book[i].getnumber()<< endl;
		cout << "现有图书名称:" << book[i].getname() << endl;
	}
	cout << "共有图书：" << kk << "本" << endl;
}
void BDatabase::bookdata() {//图书库维护
	int choice = 1;
	char bookname[20];
	int bookid;
	Book* b;
	while (choice != 0) {
		cout << "图书维护：" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出" << endl;
		cin >> choice;
		cout << "------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "输入图书编号：";
			cin >> bookid;
			cout << "输入图书名：";
			cin >> bookname;
			addbook(bookid, bookname); break;
		case 2:cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "该图书不存在！" << endl;
				break;
			}
			cout << "输入新的图书名：";
			cin >> bookname;
			b->setname(bookname); break;
		case 3:cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "该图书不存在！" << endl;
				break;
			}
		case 4:cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL) {
				cout << "该图书不存在！" << endl;
				break;
			}
			b->list(); break;
		case 5:list(); break;
		case 6:break;
		}//end switch
	}//end while
}