// lab_2_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include "shop.h"
#include <windows.h>
#include <vector>

//Написать собственный класс, в соответствии с вариантом.Продемонстрировать в коде инкапсуляцию данных, применение конструкторов 
//без параметров и с параметрами для инициализации данных.Класс должен содержать метод serialize() для сохранения данных класса 
//в файл и метод deserialize() для чтения данных класса из файла по умолчанию в текущей директории, а также перегруженные методы
//serialize(const std::string& filename) и deserialize(const std::string& filename) для работы с файлом с указанным в параметре 
//именем
//Класс МАГАЗИН.
//Данные: название, адрес, год основания, номер, суммарная прибыль.
//Создать два объекта - магазина в куче и один в стеке.Данные первых двух заполнить с помощью сеттеров, а третий проинициализировать 
//с помощью конструктора с параметрами.В главной функции проимитировать отдельно продажи за сентябрь, октябрь и ноябрь.Вывести все 
//магазины отдельно в двух рейтинговых списках(сначала один, затем второй) : 1) отсортировать в порядке убывания общей прибыли за 
//3 месяца; 2) отсортировать в порядке убывания среднего прироста прибыли за 3 месяца.

void print(shop* arr, size_t size) {
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "\n# " << i + 1 << " #\n";
		arr[i].print();
	}
 }

int main()
{
   // std::cout << "Hello World!\n"; 
	srand(time(NULL));
	shop* shop1 = new shop();
	shop1->setName("The 'GUM' shop");
	shop1->setAddress("Moscow, Red Square");
	shop1->setFoundation(1864);
	shop1->setNumber(1);
	double random2 = rand() % 25000 - 5000;
	shop1->setProfit(random2);
	shop1->print();

	shop* shop2 = new shop();
	shop2->setName("The GB's shop");
	shop2->setAddress("London, Green st");
	shop2->setFoundation(1904);
	shop2->setNumber(2);
	double random3 = rand() % 30000 - 10000;
	shop2->setProfit(random3);
	shop2->print();

	double random1 = rand() % 20000 - 8000;
	shop shop3("The Vatrushka shop", "Donetsk, Artema street, 63", 2014, 3, random1);
	shop1->sales();
	shop2->sales();
	shop3.sales();
	shop3.print();
	shop3.serialize();
	shop shop4("The Samsa shop", "Abhasia", 2001, 4, random1);
	shop4.print();
	shop4.deserialize();
	shop4.print();

	shop shops[3] = { *shop1,*shop2, shop3 };
	//shops[0] = shop1;
	//shops[1] = shop2;
	//shops[2] = &shop3;

	shop* sorted3month = shop::sortdecrease3(shops, sizeof(shops) / sizeof(shops[0]));
	shop* sortedAverage = shop::sortdecreaseA(shops, sizeof(shops) / sizeof(shops[0]));

	std::cout << "\nSorted by profit per 3 months\n" << std::endl;
	print(sorted3month, 3);

	std::cout << "\nSorted by average profit\n" << std::endl;
	print(sortedAverage, 3);
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
