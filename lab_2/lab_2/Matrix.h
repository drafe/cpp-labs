#pragma once

class Matrix
{
private:
	int row; //row
	int column;
	int** m;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix& );
	~Matrix();

	int size() const;
	int getrow() const;
	int getcolumn() const;

	int at(int, int ) const;
	void setAt(int, int , int );

	void init();
	void print();

	//int Factorial(int);

	Matrix& operator++();
	Matrix& operator--();
	Matrix operator++(int);
	Matrix operator--(int);
};
