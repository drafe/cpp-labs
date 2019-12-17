#include "pch.h"
#include "shop.h"
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <windows.h>
#include <fstream>

shop::shop() : shop("shop","address", 2000, -1, 0) {}
shop::shop(shop& s) : name(s.name), address(s.address), foundation(s.foundation), num(s.num), profit(s.profit),
profit3month(s.profit3month), profitaverage(s.profitaverage){}
shop::shop(std::string name_, std::string add_, int year_, int num_, int prof_) : 
		   name(name_), address(add_), foundation(year_), num(num_), profit(prof_) {
	this->profit3month = 0;
	this->profitaverage = 0;
}
shop::~shop() {	 }

void shop::setName(std::string nm) { name = nm; }
void shop::setAddress(std::string ad) { address = ad; }
void shop::setFoundation(int ye) { foundation = ye; }
void shop::setNumber(int nu) { num = nu; }
void shop::setProfit(double tp) { profit = tp; }

std::string shop::getName() { return name; }
std::string shop::getAddress() { return address; }
int shop::getFoundation() { return foundation; }
int shop::getNumber() { return num; }
double shop::getProfit() { return profit; }
double shop::getProfit3month() { return profit3month; };
double shop::getProfitAverage() { return profitaverage; };

void shop::print() {
	std::cout << "Name : " << name << std::endl;
	std::cout << "Address : " << address << std::endl;
	std::cout << "Year of foundation : " << foundation << std::endl;
	std::cout << "Number : " << num << std::endl;
	std::cout << "Total profit : " << profit << std::endl;
	std::cout << "Profit per 3 months: " << profit3month << std::endl;
	std::cout << "Average profit : " << profitaverage << std::endl;
}
void shop::sales(){
	std::string months[3] = { "September", "October", "November" };
	int* monthlyProfit = new int[3];
	double startingProfit = profit;
	for (int i = 0; i < 3; i++)
	{
		monthlyProfit[i] = rand() % 15000 - 3000;
		profit += monthlyProfit[i];
		std::cout << months[i] << " sales:" << monthlyProfit[i] << std::endl;
	}
	std::cout << std::endl;
	profit3month = profit - startingProfit;
	profitaverage = ((monthlyProfit[2] - monthlyProfit[1]) + (monthlyProfit[1] - monthlyProfit[0])) / 2;
}

shop* shop::sortdecrease3(shop* arr, const size_t size) {
	/*size_t size = sizeof(arr) / sizeof(arr[0]);*/
	shop* stores = new shop[size];
	for (size_t i = 0; i < size; ++i) {
		stores[i] = arr[i];
	}
	shop temp;
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t j = 0; j < size - i - 1; ++j) {
			if (stores[j].profit3month > stores[j + 1].profit3month) {
				// меняем элементы местами
				temp = stores[j];
				stores[j] = stores[j + 1];
				stores[j + 1] = temp;
			}
		}
	}
	return stores;
}
int condit(const void* a, const void* b)
{
	double n1 = ((shop*)a)->getProfitAverage();
	double n2 = ((shop*)b)->getProfitAverage();
	int s = (int)(n2 - n1);
	return s;
}
shop* shop::sortdecreaseA(shop* arr, const size_t size) {
	shop* stores = new shop[size];
	for (size_t i = 0; i < size; ++i) {
		stores[i] = arr[i];
	}
	qsort(stores, size, sizeof(shop), condit);
	return stores;
}

void shop::serialize() { serialize("Text.txt"); }

void shop::serialize(const std::string& path) { //запись в файл
	std::ofstream out(path);

	if (out.is_open()) {
		out << name << std::endl;
		out << address << std::endl;
		out << foundation << std::endl;
		out << num << std::endl;
		out << profit << std::endl;
	}
	out.close();
	std::cout << name << " has serialised in " << path << std::endl;
}
void shop::deserialize(){ deserialize("Text.txt"); }
void shop::deserialize(const std::string& path) {//чтение из файла
	std::cout << std::endl;
	std::string line;
	std::ifstream in(path);
	if (in.is_open()) {
		getline(in,name);
		getline(in, address);
		in >> foundation;
		in >> num;
		in >> profit ;
		profit3month = 0;
		profitaverage = 0;
	}
	in.close();
	std::cout << name << " has deserialised from " << path << std::endl;
}