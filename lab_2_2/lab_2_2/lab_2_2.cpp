// lab_2_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "fraction.h"
#include <iostream>

//Написать класс Fraction для представления обыкновенных дробей(как отношения двух целых чисел x / y).
//Перегрузить операторы + , -, *, / для дробей.Реализовать метод void reduce() для сокращения дроби, а также статические методы :
// int gcd(int n, int m) функция для нахождения наибольшего общего делителя чисел n и m;
// void printAsFraction(double decimal_fraction)
// void printAsFraction(char* decimal_fraction)
//перегруженные методы вывода десятичной дроби в виде обыкновенной(например, при значении decimal_fraction = 0.43 на экране должно 
//вывестись 43 / 100, при 0.25 – 1 / 4 и т.д.).
//Также реализовать в виде статического члена класса счетчик всех созданных на данный момент в программе экземпляров дробей.
//Продемонстрировать работу созданного класса.Создать несколько объектов дробей.Произвести операции сложения, вычитания, умножения 
//и деления дробей.Вывести на экран результаты.Показать также результаты работы статических методов класса.

int main()
{
	fraction f(3, 14);
	fraction d(7, 21);
	fraction f1 = f + d;
	f1.print();
	d.reduce();
	d.print();
	std::cout << f1.count() << std::endl;
	double z = 3.5;
	fraction::printAsFraction(z);
	fraction::printAsFraction("4.35");

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
