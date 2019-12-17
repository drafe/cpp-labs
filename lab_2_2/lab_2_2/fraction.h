#pragma once

class fraction
{
	int x; //���������
	int y; //�����������
	static int counter; //�������
public:
	fraction(int,int);
	fraction(const fraction&);
	~fraction();

	int count();

	void reduce(); //���������� �����
	void print();
	static int gcd(int, int);  //������� ��� ���������� ���
	static void printAsFraction(double); //������ ������ ���������� ����� � ���� ������������
	static void printAsFraction(const char*);  //��������, decimal_fraction = 0.43 �� ������ 43/100
	
	fraction operator +(fraction);
	fraction operator -(fraction);
	fraction operator *(fraction);
	fraction operator /(fraction);
};

