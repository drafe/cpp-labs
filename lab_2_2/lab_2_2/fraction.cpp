#include "pch.h"
#include "fraction.h"
#include <iostream>
#include <cmath>


int fraction::counter = 0;

fraction::fraction(int x_, int y_) : x(x_), y(y_) { ++counter; }
fraction::fraction(const fraction& f) : fraction(f.x, f.y) {}
fraction::~fraction() { }

int fraction::count() { return counter; }

void fraction::reduce() { //сокращение дроби
	int nod = gcd(x,y);
	x = x / nod;
	y = y / nod;
}
void fraction::print() {
	std::cout << x << "/" << y << std::endl;
}

int fraction::gcd(int n, int m) {  //функция для нахождения нод
	while (n != 0 && m != 0) {
		if (n > m) 
			n = n % m;
		else m = m % n;
	}
	return n + m;
}
void fraction::printAsFraction(double decimal_fraction) { //методы вывода десятичной дроби в виде обыкновенной
	fraction f((int)(decimal_fraction * 1000000), 1000000);
	f.reduce();
	std::cout << decimal_fraction << " = ";
	f.print();
}
void fraction::printAsFraction(const char* decimal_fraction) {  //например, decimal_fraction = 0.43 на экране 43/100
	double d = atof(decimal_fraction);
	printAsFraction(d);
}

fraction fraction::operator +(fraction f) {
	int x1 = f.x * this->y + f.y * this->x;
	int x2 = f.y * this->y;
	fraction fr(x1, x2);
	fr.reduce();
	return fr;
}
fraction fraction::operator -(fraction f) {
	return f+fraction(-1 * this->x, this->y);
}
fraction fraction::operator *(fraction f) {
	int x1 = f.x * this->x;
	int x2 = f.y * this->y;
	fraction fr(x1, x2);
	fr.reduce();
	return fr;
}
fraction fraction::operator /(fraction f) {
	return f * fraction(this->y, this->x);
}
