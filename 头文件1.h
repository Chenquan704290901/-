
//��ҳ�˵���
//1.����һ����Ͷ���9->40��
//2.����һ������Ͷ���42->59��
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Data  //����һ����
{
	friend class data_message_p;//����һ������

private:
	string province;       //ʡ
	int sort;              //���
	int time;              //ʱ��
	int new_dia;           //����ȷ��
	int new_cur;           //��������
	int new_dea;           //��������
	int new_red_sus;       //����/���ٵ�����
	int new_red_sev;       //����/���ٵ���֢
	int cum_dia;           //�ۼ�ȷ��
	int cum_cur;           //�ۼ�����
	int cum_dea;           //�ۼ�����
	int exi_sus;           //�ִ�����
	int exi_sev;           //�ִ���֢
	string sus_cha;        //���Ʊ仯
	string ser_cha;        //��֢�仯
	Data* next;

public:
	Data(int, string, int, int, int, int, int);
	static void display_n(Data*);//����ȫ�����ݵĺ���
	static void display_p(Data*);//������������ݵĺ���
	static void display_o(Data*);//����ĳʡ�����ݵĺ���
	static void guai_dian(Data*);//����յ�ĺ���
	static void j_time(Data*);//����ĳ��ʱ���ȫ��ƽ�����ݵĺ���
	void swap();//����ʱ�õĽ�������
};

class data_message_p//��������
{
private:
	Data* first;//����һ��ָ������ָ��
	Data* last;//����һ��ָ������ָ��

public:
	data_message_p();//��ʼ��
	void revise();//�޸�����
	void search_o();//����ĳʡ����
	void add();//�������
	void showAll_p();//��ʾ����������
	void showAll_n();//��ʾȫ������
	void g_d();//��ʾ�յ�
	void c_p();//��ʾ��ѯĳ��ʱ���ȫ������
	void showMenu1();//����Ա�˵�
	void showMenu2();//�û��˵�
	void input();//�������ļ���ȡ���ݵ�����
	void exitt();//�˳�
};



