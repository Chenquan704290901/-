
//��ҳ�˵���
// 1.�����ļ�->����15��
// 2.��ʾϵͳ������棺18->91
// 3.��ʾ����Աҳ�棺50��
// 4.��ʾ�û����棺76��
// 5.�ж��ǹ���Ա�����û���36
// 6.�ж������Ƿ���ȷ��43
// 7.�������Ա������62
// 8.�����û�������87
#include <iostream>
#include <iomanip>
#include"ͷ�ļ�1.h" 
#include <string>
using namespace std;
int main()
{
	int h, z;
	int password = 123456, put_word = 0;//����Ա���룺123456
	data_message_p d;//��������Ķ���
	d.input();//�����ļ�->����

	while (1) //��ʾϵͳ�������
	{
		system("color F0");
		cout << endl << endl;
		cout << "\t\t\t***********************************************" << endl;
		cout << "\t\t\t**                                           **" << endl;
		cout << "\t\t\t**        �¹��������ݹ���ϵͳ               **" << endl;
		cout << "\t\t\t**                                           **" << endl;
		cout << "\t\t\t**            1.  ����Ա                     **" << endl;
		cout << "\t\t\t**            2.  �û�                       **" << endl;
		cout << "\t\t\t**                                           **" << endl;
		cout << "\t\t\t***********************************************" << endl;
		cout << "\t\t\t�������������ţ�"; cin >> z;

		//�ж��ǹ���Ա�����û�
		switch (z)
		{
		case 1:
		{   
			system("color F0");
			cout << "\t\t\t\t���������Ա���룺"; cin >> put_word;//��������
			int D = 0;

			while (D != 1)
			{
				if (password != put_word)//�ж������Ƿ���ȷ
				{
					cout << "\n\t\t\t\t����������������룺"; cin >> put_word;//���벻��ȷ
				}
				else  D = 1;//������ȷ

			}
			system("cls");//����

			while (1)
			{
				d.showMenu1();//��ʾ�û�����
				cout << "\t\t\t\t�������������ţ�";
				cin >> h;
				cout << endl;

				switch (h)//�������Ա����
				{
				case 1:system("cls"); d.add(); break;//�������
				case 2:system("cls"); d.showAll_p(); break;//��ʾ����������
				case 3:system("cls"); d.showAll_n(); break;//��ʾȫ������
				case 4:system("cls"); d.revise(); break;//�޸�����
				case 5:system("cls"); d.search_o(); break;//����ĳʡ����
				case 6:system("cls"); d.g_d(); break;//�ҹյ�
				case 7:system("cls"); d.c_p(); break;//��ĳ��ʱ���ƽ������
				case 8:system("cls"); d.exitt(); break;//�˳�
				default: system("cls"); cout << "\n\t\t\t\t�������" << endl;
					break;
				}
			}
		}
		case 2:
		{
			system("cls");//����

			while (1)
			{
				d.showMenu2();//��ʾ�û�����
				cout << "\t\t\t\t�������������ţ�";
				cin >> h;
				cout << endl;

				switch (h)//�����û�����
				{
				case 1:system("cls"); d.showAll_p(); break;//��ʾ����������
				case 2:system("cls"); d.showAll_n(); break;//��ʾȫ������
				case 3:system("cls"); d.search_o(); break;//����ĳʡ����
				case 4:system("cls"); d.g_d(); break;//�ҹյ�
				case 5:system("cls"); d.c_p(); break;//��ĳ��ʱ���ƽ������
				case 6:system("cls"); d.exitt(); break;//�˳�
				default: cout << "\n\t\t\t\t�������" << endl;
					break;
				}
			}
		}
		default:system("cls"); cout << "\n\t\t\t\t�������" << endl;
		}
	}


}