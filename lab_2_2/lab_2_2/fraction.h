#pragma once

class fraction
{
	int x; //числитель
	int y; //знаменатель
	static int counter; //счетчик
public:
	fraction(int,int);
	fraction(const fraction&);
	~fraction();

	int count();

	void reduce(); //сокращение дроби
	void print();
	static int gcd(int, int);  //функция для нахождения нод
	static void printAsFraction(double); //методы вывода десятичной дроби в виде обыкновенной
	static void printAsFraction(const char*);  //например, decimal_fraction = 0.43 на экране 43/100
	
	fraction operator +(fraction);
	fraction operator -(fraction);
	fraction operator *(fraction);
	fraction operator /(fraction);
};

