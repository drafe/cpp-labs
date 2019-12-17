#pragma once
#include <iostream>

class shop
{
	std::string name;
	std::string address;
	int foundation;
	int num;
	int profit;
	double profit3month;
	double profitaverage;
public:
	shop();
	shop(shop&);
	shop(std::string, std::string, int, int, int);
	~shop();

	void setName(std::string);
	void setAddress(std::string);
	void setFoundation(int);
	void setNumber(int);
	void setProfit(double);

	std::string getName();
	std::string getAddress();
	int getFoundation();
	int getNumber();
	double getProfit();
	double getProfit3month();
	double getProfitAverage();

	void print();
	void sales();

	static shop* sortdecrease3(shop*, const size_t);
	static shop* sortdecreaseA(shop*, const size_t);
	
	void serialize();
	void serialize(const std::string& ); //запись в файл
	void deserialize();
	void deserialize(const std::string&);//чтение из файла
};

