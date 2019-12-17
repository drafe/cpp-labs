#include "pch.h"
#include "Vector.h"
#include <iostream>
#include <iomanip>

Vector::Vector() : Vector(5) {}
Vector::Vector(int len_) {
	len = len_;
	v = new int[len];
	for (size_t i = 0; i < len; i++) v[i] = 0;
}
Vector::Vector(const Vector& vector) : Vector(vector.len) {
	//v = new int[len];
	for (size_t i = 0; i < len; i++) v[i] = vector[i];
}
Vector::Vector(const Matrix& matrix) {
	///по алгоритму из варианта///
	len = matrix.size() - matrix.getcolumn() * (matrix.getrow() / 2);
	v = new int[len];
	for (size_t i = 0; i < matrix.getrow(); i += 2)
		for (size_t j = 0; j < matrix.getcolumn(); ++j)
			v[i / 2 * matrix.getcolumn() + j] = matrix.at(i, j);
}

Vector::~Vector()
{
	delete[] v;
	v = nullptr;
}

void Vector::print() {
	for (size_t i = 0; i < len; ++i)
		std::cout << std::setw(8) << *(v + i);
}

int Vector::length() const { return len; }

Vector& Vector::operator++() { 
	for (size_t i = 0; i < len; ++i) ++v[i]; 
	return *this;
}
Vector& Vector::operator--() { 
	for (size_t i = 0; i < len; ++i) --v[i];
	return *this;
}

Vector Vector::operator++(int) {
	//// Создаём временный объект класса Number с текущим значением переменной m_number
	//Number temp(m_number);
	//// Используем оператор инкремента версии префикс для реализации перегрузки оператора инкремента версии постфикс
	//++(*this); // реализация перегрузки
	//// Возвращаем временный объект
	//return temp;
	Vector tmp(*this);
	++(*this);
	return tmp;
}
Vector Vector::operator--(int) {
	Vector tmp(*this);
	--(*this);
	return tmp;
}

int& Vector::operator [](int index)const { return *(v + index); }
