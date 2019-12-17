#pragma once
#include "Matrix.h"


class Vector
{
private:
	int* v;
	int len;
public:
	Vector();
	Vector(int );
	~Vector();
	Vector(const Vector& );
	Vector(const Matrix& );

	void print();
	
	int length() const;

	Vector& operator++();
	Vector& operator--();
	Vector operator++(int);
	Vector operator--(int);

	int& operator [](int )const;
};
