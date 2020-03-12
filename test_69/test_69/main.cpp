#define _CRT_SECURE_NO_WARNINGS 1
//����ǿ�ȵȼ�
//���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ����֡�
//һ�����볤��: 5 ��: С�ڵ���4 ���ַ�    10 ��: 5 ��7 �ַ�                25 ��: ���ڵ���8 ���ַ�
//������ĸ:     0 ��: û����ĸ            10 ��: ȫ����С����д��ĸ      20 ��: ��Сд�����ĸ
//��������:     0 ��: û������            10 ��: 1 ������                  20 ��: ����1 ������
//�ġ�����:     0 ��: û�з���            10 ��: 1 ������                  25 ��: ����1 ������
//�塢����:     2 ��: ��ĸ������          3 ��: ��ĸ�����ֺͷ���           5 ��: ��Сд��ĸ�����ֺͷ���
//�������ֱ�׼:>= 90: �ǳ���ȫ          >= 80: ��ȫ��Secure��            >= 70: �ǳ�ǿ         >= 60: ǿ��Strong��
//               >= 50: һ�㣨Average��   >= 25: ����Weak��                >= 0:  �ǳ���
//��Ӧ���Ϊ��VERY_WEAK, WEAK, AVERAGE,  STRONG, VERY_STRONG, SECURE, VERY_SECURE 
//���������������ַ��������а�ȫ������
//ע����ĸ��a-z, A-Z    ���֣�-9
//���Ű������£� (ASCII��������UltraEdit�Ĳ˵�view->ASCII Table�鿴)
//               !"#$%&'()*+,-./     (ASCII�룺x21~0x2F)
//               :;<=>?@             (ASCII<=><=><=><=><=>�룺x3A~0x40)
//               [\]^_`              (ASCII�룺x5B~0x60)
//               {|}~                (ASCII�룺x7B~0x7E)

//��������:����һ��string������
//�������:�������ȼ�
//����: 38$@NoNoNo
//���: VERY_SECURE
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Evaluate(string &password)
{
	int score = 0;

	//һ�����볤��:
	if (password.size() <= 4)
		score += 5;
	else if (password.size() <= 7)
		score += 10;
	else
		score += 25;
	//������ĸ:��������: �ġ�����:
	int majuscule = 0;//��д��ĸ 
	int small_letter = 0;//Сд��ĸ
	int num = 0;//����
	int symbol = 0;//����
	for (size_t i = 0; i < password.size(); i++)
	{
		if (password[i] >= '0'&&password[i] <= '9')
			num++;
		else if (password[i] >= 'A'&&password[i] <= 'Z')
			majuscule++;
		else if (password[i] >= 'a'&&password[i] <= 'z')
			small_letter++;
		else
			symbol++;
	}
	if (majuscule != 0 && small_letter != 0)//��ĸ��
		score += 20;
	else if (majuscule > 0 || small_letter > 0)
		score += 10;

	if (num > 1)//���ַ�
		score += 20;
	else if (num == 1)
		score += 10;

	if (symbol > 1)//���ŷ�
		score += 25;
	else if (symbol == 1)
		score += 10;

	if (majuscule != 0 && small_letter != 0 && num != 0 && symbol != 0)//������
		score += 5;
	else if ((majuscule != 0 || small_letter != 0) && num != 0 && symbol != 0)
		score += 3;
	else if ((majuscule != 0 || small_letter != 0) && num != 0)
		score += 2;

	if (score >= 60)
	{
		if (score >= 80)
		{
			if (score >= 90)
				return 6;
			else
				return 5;
		}
		else
		{
			if (score >= 70)
				return 4;
			else
				return 3;
		}
	}
	else
	{
		if (score >= 25)
		{
			if (score >= 50)
				return 2;
			else
				return 1;
		}
		else
			return 0;
	}
}

int main()
{
	//����ǿ�ȣ���->ǿ  0->6��
	vector<string> cla = { "VERY_WEAK", "WEAK", "AVERAGE", "STRONG", "VERY_STRONG", "SECURE", "VERY_SECURE" };
	string password;

	while (cin >> password)
	{
		cout << cla[Evaluate(password)] << endl;
	}

	return 0;
}