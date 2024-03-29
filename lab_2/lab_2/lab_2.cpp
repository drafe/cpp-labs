// lab_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Matrix.h"
#include "Vector.h"
#include <iostream>

//Написать классы Vector и Matrix для хранения и обработки одномерных и двумерных массивов, соответственно.
//Реализовать задание 2 лабораторной работы №1 с помощью созданных классов.Все функции оформить в виде методов классов.
//В коде отразить следующее :
// Выделение и освобождение динамической памяти производить в конструкторах и деструкторах классов, соответственно.
// В классе Vector перегрузить оператор индексации[].В классе Matrix добавить методы T at(int i, int j) const и 
//setAt(int i, int j, T val), которые позволяют получить и установить значение элемента массива с индексом[i][j], 
//T – это тип элементов массива по варианту(int или double).
// Перегрузить операторы инкремента и декремента(как префиксного, так и постфиксного).Смысл инкремента / декремента 
//всего массива заключается в инкременте / декременте каждого элемента массива.


int main()
{
	Matrix matrix(3, 3);
	matrix.init();
	matrix.print();
	std::cout << std::endl;
	//int size = matrix.size();
	Vector vector(matrix);
	vector.print();

	/*std::cout << std::endl;
	(++vector).print();
	Vector vtmp = vector++;
	std::cout << "vector++ : ";
	vector.print();
	std::cout << std::endl;
	std::cout << "vtmp : ";
	vtmp.print();

	std::cout << std::endl;
	vtmp = vector--;
	std::cout << "vector-- : ";
	vector.print();
	std::cout << std::endl;
	std::cout << "vtmp : ";
	vtmp.print();*/

	std::cout << std::endl;
	(++matrix).print();
	Matrix mtmp = matrix++;
	std::cout << "matrix++ : " << std::endl;
	matrix.print();
	std::cout << std::endl;
	std::cout << "mtmp : " << std::endl;
	mtmp.print();

	std::cout << std::endl;
	(--matrix).print();
	//mtmp = *(new Matrix(4, 4));
	//mtmp.print();
	//mtmp = matrix;
	//mtmp.print();

	Matrix mtmp1 = matrix--;
	std::cout << "matrix-- : " << std::endl;
	matrix.print();
	std::cout << std::endl;
	std::cout << "mtmp1 : " << std::endl;
	mtmp1.print();
	return 0;
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
