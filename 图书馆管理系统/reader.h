#ifndef _reader_h_
#define _reader_h_
const int Maxbor = 5;//��������
class Reader {
private:
	int note;//ɾ�����
	int number;//���߱��
	char name[10];//��������
	int borbook[Maxbor];//����ͼ��
public:
	Reader() {};
	char* getname();//�������
	int getnote();//���ɾ�����
	int getnumber();//��ö��߱��
	void setname(char na[]);//��������
	void delbook();//����ɾ�����
	void addreader(int n, char* na);//��Ӷ���
	void borrowbook(int bookid);//�������
	int retbook(int bookid);//�������
	void list();//���������Ϣ
};
#endif//�͵�һ�гɶԳ���