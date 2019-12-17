#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <iomanip>

Matrix::Matrix() : Matrix(10,10) {}
Matrix::Matrix(int row_, int column_) {
	row = row_;
	column = column_;
	m = new int*[row];
	for (int i = 0; i < row; i++) {
		m[i] = new int[column];
		for (int j = 0; j < column; j++) {
			m[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& matrix) : Matrix(matrix.row, matrix.column) {
	//m = new int*[row];
	for (int i = 0; i < row; i++) {
		m[i] = new int[column];
		for (int j = 0; j < column; j++) {
			m[i][j] = matrix.m[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (size_t i = 0; i < row; ++i) 
		delete[] * (m + i);
	delete[] m;
}

int Matrix::size() const { return row * column; }
int Matrix::getrow() const { return row; }
int Matrix::getcolumn() const { return column; }

int Matrix::at(int row_, int column_) const { return m[row_][column_]; }
void Matrix::setAt(int row_, int column_, int value) {
	m[row_][column_] = value;
}

void Matrix::init() {
	///инициализация факториалами///
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < column; ++j) {
			if (i > 0) {							//пожалеем пк и упростим ему жизнь
				m[i][j] = m[i-1][j] * (i + j);
			}
			else if (j > 0) {
				m[i][j] = m[i][j-1] * (i + j);
			}
			else {									//или 'в лоб' вычислим факториал
				m[i][j] = 1;
				for (size_t z = 1; z < i + j; ++z)
					m[i][j] *= z;
				
			}
		}
	}
}
void Matrix::print() {
	for (size_t i = 0; i < row; ++i){
		for (size_t j = 0; j < column; ++j)
			std::cout << std::setw(8) << m[i][j]; 
		std::cout << std::endl;
	}
}

//int Matrix::Factorial(int){}

Matrix& Matrix::operator++() {
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < column; ++j) ++m[i][j];
	}
	return *this;
}
Matrix& Matrix::operator--() {
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < column; ++j) --m[i][j];
	}
	return *this;
}
Matrix Matrix::operator++(int) {
	Matrix tmp(*this);
	++(*this);
	return tmp;
	//return ++(*this);
}
Matrix Matrix::operator--(int) {
	Matrix tmp(*this);
	--(*this);
	return tmp;
}
