
//��ҳ�Ĳ˵���
//1.�����ļ���-������:11��
//2.�޸�����ʱ�õĽ���������22
//3.������������ݣ�46
//4.����ȷ����������114
//5.����ĳʡ�����ݣ�157
//6.����յ�ĺ�����255
//7.//����ĳ��ʱ���ȫ��ƽ�����ݣ�317
//8.����ȫ�������ݣ�358
//9.��ʼ����436
//10.������ݣ�444
//11.���ô������ļ�-������484
//12.��������ĳʡ�����ݣ�530
//13.�����޸�ĳʡ���ݵĺ�����537
//14.��������ĳʡ�����ݣ�595

#include <iostream>
#include <iomanip>
#include <string>
#include"ͷ�ļ�1.h"
#include<stdlib.h>
using namespace std;

//�����ļ���-������
Data::Data(int Time, string Province, int New_dia
	, int New_cur, int New_dea, int New_red_sus, int New_red_sev)
{
	time = Time; province = Province; new_dia = New_dia;
	new_cur = New_cur; new_dea = New_dea;
	new_red_sus = New_red_sus; new_red_sev = New_red_sev;
	next = NULL;
}

//�޸�����ʱ�õĽ�������
void Data::swap()
{
	//��������
	int s_sort; string s_province, s_sus_cha, s_ser_cha;
	int s_cum_dia, s_new_dia, s_cum_cur, s_new_dea;
	int s_exi_sus, s_exi_sev, s_new_cur, s_cum_dea;

	//���ݽ���
	s_sort = sort; sort = next->sort; next->sort = s_sort;
	s_province = province; province = next->province; next->province = s_province;
	s_sus_cha = sus_cha; sus_cha = next->sus_cha; next->sus_cha = s_sus_cha;
	s_ser_cha = ser_cha; ser_cha = next->ser_cha; next->ser_cha = s_ser_cha;
	s_cum_dia = cum_dia; cum_dia = next->cum_dia; next->cum_dia = s_cum_dia;
	s_new_dia = new_dia; new_dia = next->new_dia; next->new_dia = s_new_dia;
	s_cum_cur = cum_cur; cum_cur = next->cum_cur; next->cum_cur = s_cum_cur;
	s_new_dea = new_dea; new_dea = next->new_dea; next->new_dea = s_new_dea;
	s_exi_sus = exi_sus; exi_sus = next->exi_sus; next->exi_sus = s_exi_sus;
	s_exi_sev = exi_sev; exi_sev = next->exi_sev; next->exi_sev = s_exi_sev;
	s_new_cur = new_cur; new_cur = next->new_cur; next->new_cur = s_new_cur;
	s_cum_dea = cum_dea; cum_dea = next->cum_dea; next->cum_dea = s_cum_dea;
}

//�������������
void Data::display_p(Data* first)
{
	//������Ҫ������
	int p_cum_dia = 0, p_new_dia = 0;
	int p_cum_cur = 0, p_new_cur = 0;
	int p_cum_dea = 0, p_new_dea = 0;
	int p_exi_sus = 0, p_exi_sev = 0;
	string p_sus_cha, p_ser_cha;
	int p_exi_sus_y = 0, p_exi_sev_y = 0;
	int p_exi_sus_n = 0, p_exi_sev_n = 0;

	Data* t = first;
	t = first;
	int max = 0;

	while (t)//�ҳ����µ�ʱ��
	{
		max = t->time;
		if (max < t->time)
		{
			max = t->time;
		}
		t = t->next;
	}

	Data* T = first;
	string t_province;

	//�����ۼƵ�����
	while (T)
	{
		t_province = T->province;
		t = first;
		p_cum_dia = 0;
		p_cum_cur = 0;
		p_cum_dea = 0;
		p_exi_sus = 0;
		p_exi_sev = 0;
		while (t)//�ۼ�����
		{
			if (t->province == t_province)
			{
				p_cum_dia += t->new_dia;
				p_cum_cur += t->new_cur;
				p_cum_dea += t->new_dea;
				p_exi_sus += t->new_red_sus;
				p_exi_sev += t->new_red_sev;
				if (t->time == max)
				{
					t->cum_dia = p_cum_dia;
					t->cum_cur = p_cum_cur;
					t->cum_dea = p_cum_dea;
					t->exi_sus = p_exi_sus;
					t->exi_sev = p_exi_sev;
					if (t->new_red_sus > 0) t->sus_cha = "����";
					else if (t->new_red_sus < 0) t->sus_cha = "����";
					else t->sus_cha = "����";
					if (t->new_red_sev > 0) t->ser_cha = "����";
					else if (t->new_red_sev < 0) t->ser_cha = "����";
					else t->ser_cha = "����";
				}
			}
			t = t->next;
		}
		T = T->next;
	}

	//����ȷ����������
	t = first;
	Data* p = t;
	while (p->next)
	{
		t = first;
		while (t->next)
		{
			if ((t->next->cum_dia >= t->cum_dia) && (t->time == max) && (t->next->time == max))
			{
				t->swap();
			}
			t = t->next;
		}
		p = p->next;
	}
	//��ʾ����������
	t = first;
	int i = 0;
	system("color F4");
	while (t)
	{
		if (t->time == max)
		{
			t->sort = i + 1;
			cout << setiosflags(ios::fixed) << resetiosflags(ios::right);
			cout << setw(3) << t->sort << "  " << setw(5) << t->province << "     ";
			cout << setw(5) << t->cum_dia << "     " << setw(5) << t->new_dia << "     ";
			cout << setw(5) << t->cum_cur << "     " << setw(5) << t->new_cur << "     ";
			cout << setw(5) << t->cum_dea << "     " << setw(5) << t->new_dea << "     ";
			cout << setw(5) << t->exi_sus << "     " << setw(5) << t->sus_cha << "     ";
			cout << setw(5) << t->exi_sev << "     " << setw(5) << t->ser_cha << "     " << endl;
			cout << "------------------------------------------------------------------------------------------------------------------  " << endl;
			i++;
		}
		t = t->next;
	}

	cout << "����ʱ�䣺2020-" << max / 100 << "-" << max % 100 << " ȫ������ͳ��";
	cout << "                                                       ע���������Թ�������ί" << endl;
}

//����ĳʡ������
void Data::display_o(Data* first)
{
	int p_cum_dia = 0, p_new_dia = 0;
	int p_cum_cur = 0, p_new_cur = 0;
	int p_cum_dea = 0, p_new_dea = 0;
	int p_exi_sus = 0, p_exi_sev = 0;
	string p_sus_cha, p_ser_cha;
	int p_exi_sus_y = 0, p_exi_sev_y = 0;
	int p_exi_sus_n = 0, p_exi_sev_n = 0;

	Data* t = first;
	t = first;
	int max = 0;

	while (t)//�ҳ�����ʱ��
	{
		max = t->time;
		if (max < t->time)
		{
			max = t->time;
		}
		t = t->next;
	}

	//����ĳʡ������
	Data* T = first;
	string t_province;
	while (T)
	{
		t_province = T->province;
		t = first;
		p_cum_dia = 0;
		p_cum_cur = 0;
		p_cum_dea = 0;
		p_exi_sus = 0;
		p_exi_sev = 0;
		while (t)
		{
			if (t->province == t_province)
			{
				p_cum_dia += t->new_dia;
				p_cum_cur += t->new_cur;
				p_cum_dea += t->new_dea;
				p_exi_sus += t->new_red_sus;
				p_exi_sev += t->new_red_sev;
				if (t->time == max)
				{
					t->cum_dia = p_cum_dia;
					t->cum_cur = p_cum_cur;
					t->cum_dea = p_cum_dea;
					t->exi_sus = p_exi_sus;
					t->exi_sev = p_exi_sev;
					if (t->new_red_sus > 0) t->sus_cha = "����";
					else if (t->new_red_sus < 0) t->sus_cha = "����";
					else t->sus_cha = "����";
					if (t->new_red_sev > 0) t->ser_cha = "����";
					else if (t->new_red_sev < 0) t->ser_cha = "����";
					else t->ser_cha = "����";
				}
			}
			t = t->next;
		}
		T = T->next;
	}

	//���ĳʡ������
	string s_province;
	cout << "\n�������ѯ�ĵ�������"; cin >> s_province;
	t = first;
	int i = 0;
	t = first;
	system("color F4");
	while (t)
	{
		if ((t->time == max) && (t->province == s_province))
		{
			t->sort = i + 1;
			cout << endl;
			cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<====����ĳʡ�������====>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
			cout << " ���  ȫ������ �ۼ�ȷ��  ����ȷ��  �ۼ�����  ��������  �ۼ�����  ��������  ��������  ���Ʊ仯  ������֢  ��֢�仯" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------  " << endl;
			cout << setiosflags(ios::fixed) << resetiosflags(ios::right);
			cout << setw(3) << t->sort << "  " << setw(5) << t->province << "     ";
			cout << setw(5) << t->cum_dia << "     " << setw(5) << t->new_dia << "     ";
			cout << setw(5) << t->cum_cur << "     " << setw(5) << t->new_cur << "     ";
			cout << setw(5) << t->cum_dea << "     " << setw(5) << t->new_dea << "     ";
			cout << setw(5) << t->exi_sus << "     " << setw(5) << t->sus_cha << "     ";
			cout << setw(5) << t->exi_sev << "     " << setw(5) << t->ser_cha << "     " << endl;
			cout << "------------------------------------------------------------------------------------------------------------------  " << endl;
			cout << "����ʱ�䣺2020-" << max / 100 << "-" << max % 100 << " ȫ������ͳ��";
			cout << "                                                       ע���������Թ�������ί" << endl;
			cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<========>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		}
		t = t->next;
	}
}

//����յ�ĺ���
void Data::guai_dian(Data* first)
{
	Data* t = first;
	Data* T = first;
	int a[100] = { 0 }, b[100] = { 0 };
	int* p = a, * q = b;
	int i = 0, d = 0;
	int g_new_dia = 0, Time = 0;

	while (T)
	{
		g_new_dia = 0, d = 0;
		for (i = 0; a[i] != '\0'; i++)
		{
			if (T->time == a[i])
			{
				d++;
			}
		}
		if (d > 0)
		{
			T = T->next;
			continue;
		}
		else
		{
			Time = T->time;
		}
		t = first;
		while (t)
		{
			if (t->time == Time)
			{
				g_new_dia += t->new_dia;
			}
			t = t->next;
		}
		*p = T->time;
		*q = g_new_dia;
		q++; p++;
		T = T->next;
	}
	p = a, q = b;
	for (p = a, i = 0; *p != '\0'; p++, i++);
	system("color F4");
	if (i >= 11)
	{
		for (i = 5; b[i + 5] != '\0'; i++)
		{
			if (b[i] > b[i - 1] && b[i] > b[i - 2] && b[i] > b[i - 3]
				&& b[i] > b[i - 4] && b[i] > b[i - 5] && b[i] > b[i + 1]
				&& b[i + 1] > b[i + 2] && b[i + 2] > b[i + 3]
				&& b[i + 3] > b[i + 4] && b[i + 4] > b[i + 5])
				cout << a[i] << "  ";
			else cout << "Ŀǰû�йյ�";
		}
	}
	else cout << "Ŀǰû�йյ�";
}

//����ĳ��ʱ���ȫ��ƽ������
void Data::j_time(Data* first)
{
	Data* t = first;
	int beg = 0, fin = 0;
	cout << "\n\n\t\t\tע:ʱ�������ʽ����3��2�գ�����302��3��15������315\n\t\t\t�������ѯ��ʼʱ�䣺"; cin >> beg;
	cout << "\t\t\tע:ʱ�������ʽ����3��2�գ�����302��3��15������315\n\t\t\t�������ѯ����ʱ�䣺"; cin >> fin;
	int day = 0;
	day = fin - beg;
	int  s_new_dia = 0;
	int  s_new_cur = 0;
	int  s_new_dea = 0;
	Data* p = first;
	while (p)
	{
		if (p->time >= beg && p->time <= fin)
		{
			while (t)
			{
				if (p->time == t->time)
				{
					s_new_dia += t->new_dia;
					s_new_cur += t->new_cur;
					s_new_dea += t->new_dea;
				}
				t = t->next;
			}
		}
		p = p->next;
	}
	if (s_new_dia > 0 || s_new_cur > 0 || s_new_dea > 0)
	{
		system("color F4");
		cout << "\n\t\t\t-----------------------";
		cout << "\t\t\t �ö�ʱ���ڣ�\n";
		cout << "\t\t\t ƽ��ÿ������ȷ�" << s_new_dia / day << endl;
		cout << "\t\t\t ƽ��ÿ������������" << s_new_cur / day << endl;
		cout << "\t\t\t ƽ��ÿ������������" << s_new_dea / day << endl;
		cout << "\t\t\t-----------------------";
	}
}

//����ȫ��������
void Data::display_n(Data* first)
{
	int n_cum_dia = 0, n_new_dia = 0;
	int n_cum_cur = 0, n_new_cur = 0;
	int n_cum_dea = 0, n_new_dea = 0;
	int n_exi_sus = 0, n_exi_sev = 0;
	string n_sus_cha, n_ser_cha;
	int n_exi_sus_n = 0, n_exi_sev_n = 0;
	Data* t = first;
	while (t)
	{
		n_cum_dia += t->new_dia;
		n_cum_cur += t->new_cur;
		n_cum_dea += t->new_dea;
		n_exi_sus += t->new_red_sus;
		n_exi_sev += t->new_red_sev;
		t = t->next;
	}
	t = first;
	int max;
	while (t)
	{
		max = t->time;
		if (max < t->time)
		{
			max = t->time;
		}
		t = t->next;
	}
	t = first;
	while (t)
	{
		if (t->time == max)
		{
			n_new_dia += t->new_dia;
			n_new_cur += t->new_cur;
			n_new_dea += t->new_dea;
			n_exi_sus_n += t->new_red_sus;
			n_exi_sev_n += t->new_red_sev;
		}
		t = t->next;
	}
	if (n_exi_sus_n > 0) n_sus_cha = "����";
	else if (n_exi_sus_n < 0) n_sus_cha = "����";
	else n_sus_cha = "����";
	if (n_exi_sev_n > 0) n_ser_cha = "����";
	else if (n_exi_sev_n < 0) n_ser_cha = "����";
	else n_ser_cha = "����";
	cout << endl;
	system("color F4");
	cout << "\t\t\t<<<<<<<<<<<<<<<<====ȫ����������====>>>>>>>>>>>>>>>>>>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          ����ʱ�䣺" << setw(2) << max / 100 << "-" << setw(2) << max % 10 << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          �ۼ�ȷ�" << setw(6) << n_cum_dia << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          ����ȷ�" << setw(6) << n_new_dia << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          �ۼ�������" << setw(6) << n_cum_cur << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          ����������" << setw(6) << n_new_cur << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          �ۼ�������" << setw(6) << n_cum_dea << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          ����������" << setw(6) << n_new_dea << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          �������ƣ�" << setw(6) << n_exi_sus << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          ���Ʊ仯��" << setw(6) << n_sus_cha << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          ������֢��" << setw(6) << n_exi_sev << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<          ��֢�仯��" << setw(6) << n_ser_cha << "\t\t\t    >>" << endl;
	cout << "\t\t\t<<-------------------------------------------------->>" << endl;
	cout << "\t\t\t<<<<<<<<<<<<<<<<=====================>>>>>>>>>>>>>>>>>" << endl;
}

//��ʼ��
data_message_p::data_message_p()
{
	first = NULL;
	last = NULL;
}

//�������
void data_message_p::add()
{
	int Time, New_dia, New_cur, New_dea, New_red_sus, New_red_sev;
	string Province;
	cout << endl << endl;
	cout << "\t\t\tע:ʱ�������ʽ����3��2�գ�����302��3��15������315\n\t\t\tʱ�䣺"; cin >> Time;
	cout << "\t\t\t������"; cin >> Province;
	cout << "\t\t\t����ȷ�"; cin >> New_dia;
	cout << "\t\t\t����������"; cin >> New_cur;
	cout << "\t\t\t����������"; cin >> New_dea;
	cout << "\t\t\t����/�������ƣ�"; cin >> New_red_sus;
	cout << "\t\t\t����/������֢��"; cin >> New_red_sev;

	Data* t = new Data(Time, Province, New_dia, New_cur, New_dea, New_red_sus, New_red_sev);
	Data* p = first;
	while (p)
	{
		if ((p->time == t->time) && (p->province == t->province))
		{
			cout << "\n\t\t\t����������¼��!" << endl;
			return;
		}
		p = p->next;
	}
	ofstream outfile("����.dat", ios::app);
	outfile << Time << " " << Province << " " << New_dia << " " << New_cur << " " << New_dea << " " << New_red_sus << " " << New_red_sev << " " << endl;
	outfile.close();
	if (first == NULL)
	{
		first = last = t;
	}
	else
	{
		last->next = t;
		last = last->next;
	}
}

//���ô������ļ�-������
void data_message_p::input()
{
	int Time, New_dia, New_cur, New_dea, New_red_sus, New_red_sev;
	string Province;
	ifstream infile("����.dat");
	if (!infile)
	{
		cout<<"\t\tû�����ݣ�";
		exit(1);
	}
	//�ļ��Ѿ��򿪣��Ѿ������ļ�
	//�ļ�  ��û������
	//����---������
	while (!infile.eof())
		//while (infile.peek() != EOF)
	{

		infile >> Time >> Province >> New_dia >> New_cur
			>> New_dea >> New_red_sus >> New_red_sev;
		Data* p = first;
		while (p)
		{
			if (p->time == Time && p->province == Province)
			{
				return;
			}
			p = p->next;
		}
		Data* t = new Data(Time, Province, New_dia, New_cur, New_dea, New_red_sus, New_red_sev);
		if (first == NULL)
		{
			first = last = t;
		}
		else
		{
			last->next = t;
			last = last->next;
		}
	}

	infile.close();

}

//��������ĳʡ������
void data_message_p::c_p()
{
	Data::j_time(first);
}

//�����޸�ĳʡ���ݵĺ���
void data_message_p::revise()
{
	string r_province;
	int r_time, r_new_dia, r_new_cur, r_new_dea;
	int r_new_red_sus, r_new_red_sev;
	cout << endl << endl;
	cout << "\n\t\t\t��������Ҫ�޸ĵĵ�����"; cin >> r_province;
	cout << "\n\t\t\tע:ʱ�������ʽ����3��2�գ�����302��3��15������315\n\t\t\t��������Ҫ�޸ĵ�ʱ�䣺"; cin >> r_time;
	int a;
	while (1)
	{
		cout << "\n\t\t\t\t------------------ ";
		cout << "\n\t\t\t\t1.����ȷ��\n\t\t\t\t2.��������\n\t\t\t\t3.��������";
		cout << "\n\t\t\t\t4.���� / ��������\n\t\t\t\t5.���� / ������֢";
		cout << "\n\t\t\t\t------------------ ";
		cout << "\n\t\t\t\t�޸ĵ�ĳ�����ݣ���������Ӧ��ţ�"; cin >> a;
		if (a != 1 && a != 2 && a != 3 && a != 4 && a != 5)
		{
			cout << "\n\t\t\t\t��������������������룡" << endl;
		}
		else break;
	}
	switch (a)
	{
	case 1:cout << "\n\t\t\t\t����ȷ���Ϊ��"; cin >> r_new_dia; break;
	case 2:cout << "\n\t\t\t\t����������Ϊ��"; cin >> r_new_cur; break;
	case 3:cout << "\n\t\t\t\t����������Ϊ��"; cin >> r_new_dea; break;
	case 4:cout << "\n\t\t\t\t����/�������Ƹ�Ϊ��"; cin >> r_new_red_sus; break;
	case 5:cout << "\n\t\t\t\t����/������֢��Ϊ��"; cin >> r_new_red_sev; break;
	}
	Data* t = first;
	while (t)
	{
		if ((t->time == r_time) && (t->province == r_province))
		{
			switch (a)
			{
			case 1:t->new_dia = r_new_dia; break;
			case 2:t->new_cur = r_new_cur; break;
			case 3:t->new_dea = r_new_dea; break;
			case 4:t->new_red_sus = r_new_red_sus; break;
			case 5:t->new_red_sev = r_new_red_sev; break;
			}
		}
		t = t->next;
	}
	t = first;
	ofstream outfile("����.dat", ios::out);
	while (t)
	{
		outfile << t->time << " " << t->province << " " << t->new_dia << " " << t->new_cur << " " << t->new_dea << " " << t->new_red_sus << " " << t->new_red_sev << " " << endl;
		t = t->next;
	}
	outfile.close();
}

//��������ĳʡ������
void data_message_p::search_o()
{
	Data::display_o(first);
}
void data_message_p::g_d()
{
	cout << endl << endl;
	cout << "\t\t\t\t�յ������ ";
	Data::guai_dian(first);
}
void data_message_p::showAll_p()
{
	cout << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<====ȫ��������������====>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << " ���  ȫ������ �ۼ�ȷ��  ����ȷ��  �ۼ�����  ��������  �ۼ�����  ��������  ��������  ���Ʊ仯  ������֢  ��֢�仯" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------  " << endl;
	Data::display_p(first);
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<========>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
}
void data_message_p::showAll_n()
{
	Data::display_n(first);
}
void data_message_p::exitt()
{
	exit(1);
}
void data_message_p::showMenu1()
{
	cout << endl << endl;
	cout << "\t\t\t***********************************************" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t**       �¹��������ݹ���ϵͳ���˵�          **" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t**           1.  ¼������                    **" << endl;
	cout << "\t\t\t**           2.  ����������                  **" << endl;
	cout << "\t\t\t**           3.  ȫ������                    **" << endl;
	cout << "\t\t\t**           4.  �޸�����                    **" << endl;
	cout << "\t\t\t**           5.  ��ѯĳʡ����                **" << endl;
	cout << "\t\t\t**           6.  ��ѯ�յ�                    **" << endl;
	cout << "\t\t\t**           7.  ��ѯһ��ʱ��ȫ����ƽ������  **" << endl;
	cout << "\t\t\t**           8.  �˳�                        **" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t***********************************************" << endl;
}
void data_message_p::showMenu2()
{
	cout << endl << endl;
	cout << "\t\t\t***********************************************" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t**       �¹��������ݹ���ϵͳ���˵�          **" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t**         1.  ����������                    **" << endl;
	cout << "\t\t\t**         2.  ȫ������                      **" << endl;
	cout << "\t\t\t**         3.  ��ѯĳʡ����                  **" << endl;
	cout << "\t\t\t**         4.  ��ѯ�յ�                      **" << endl;
	cout << "\t\t\t**         5.  ��ѯһ��ʱ��ȫ����ƽ������    **" << endl;
	cout << "\t\t\t**         6.  �˳�                          **" << endl;
	cout << "\t\t\t**                                           **" << endl;
	cout << "\t\t\t***********************************************" << endl;
}