#include <iostream> 
#include <ctime>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <math.h>

int myStrcmp(const char* s1, const char* s2)
{
	int r = 0;
	int size1 = strlen(s1);
	int size2 = strlen(s2);
	int size = size1 < size2 ? size1 : size2;

	for (size_t i = 0; i < size && r == 0; ++i)
		r = s1[i] - s2[i];

	if (r < 0) r = -1;
	else if (r > 0) r = 1;
	return r;
}
char* myStrchr(char* s, int c)
{
	size_t i = 0;
	size_t length = sizeof(s) / sizeof(s[0]);
	for (; (i < length) && (s[i] != c); ++i);
	if (i == length) return NULL;
		return s + i;
}
void task3() 
{
	//Функция strcmp. Формат int strcmp(const char* s1, const char* s2).
	//Функция сравнивает строку s1 со строкой s2 в лексикографическом порядке.
	//Если s1<s2, то результат равен - 1, если s1 = s2, то 0, если s1>s2, то 1.

	char s1[] = "abB";
	char s2[] = "abbc";

	//int stand = strcmp(s1, s2);
	//int myF = myStrcmp(s1, s2);
	char* stand = strchr(s1, 'c');
	char* myF = myStrchr(s1, 'c');


	printf("String 1: %s\nString 2: %s\nStandart: %s\nMy func: %s", s1, s2, stand,myF);

	//%d - int
	//%s - char*
	//%f - double\float
	//%p - byte
}

void initArr(int** a2D, size_t len_x, size_t len_y) //инициализация 2d массива факториалами
{
	for (size_t i = 0; i < len_x; ++i)
	{
		for (size_t j = 0; j < len_y; ++j)
		{
			if (i > 0)								//пожалеем пк и упростим ему жизнь
			{
				*(*(a2D + i) + j) = *(*(a2D + i - 1) + j)* (i + j);
			}
			else if (j > 0)
			{
				*(*(a2D + i) + j) = *(*(a2D + i) + j - 1) * (i + j);
			}
			else {									//или 'в лоб' вычислим факториал
				*(*(a2D + i) + j) = 1;
				for (size_t z = 1; z < i + j; ++z)
				{
					*(*(a2D + i) + j) = *(*(a2D + i) + j) * z;
				}
			}
		}
	}
}
void print2d(int** a2D, size_t len_x, size_t len_y)
{
	for (size_t i = 0; i < len_x; ++i)
	{
		for (size_t j = 0; j < len_y; ++j)
			//std::cout << std::setw(8) << a2D[i][j];
			std::cout << std::setw(8) << *(*(a2D + i) + j); //<< "\t";
		std::cout << std::endl;
	}
}
void print1d(int* a1D, size_t length)
{
	for (size_t i = 0; i < length; ++i)
		std::cout << std::setw(8) << *(a1D + i);//<< "\t";
}
void free1d(int* a1D)
{
	delete[] a1D;
}
void free2d(int** a2D, size_t len_x)
{
	for (size_t i = 0; i < len_x; ++i)					
	{
		delete[] *(a2D + i);
	}
	delete[] a2D;
}
int* create1d(int** a2D, size_t len_x, size_t len_y, size_t length)
{
	int* newA = new int[length];
	for (size_t i = 0; i < len_x; i += 2)
		for (size_t j = 0; j < len_y; ++j)
			*(newA + i / 2 * len_x + j) = *(*(a2D + i) + j);
	return newA;
}
void task2()
{
	const size_t L = 5, Length = 15;


	int** arr2D = new int*[L];							// 2d массив, объявленный динамически
	for (size_t i = 0; i < L; ++i)
	{
		*(arr2D + i)= new int[L];
	}

	initArr(arr2D,L,L);
	print2d(arr2D,L,L);
	std::cout << std::endl;
	int* arr1D = create1d(arr2D,L,L,Length);			//создаем 1d массив
	print1d(arr1D, Length);

	free2d(arr2D, L);									//освобождаем память
	free1d(arr1D);
}

void printArr(double arr[], size_t length)
{
	for (size_t i = 0; i < length; ++i)
	{
		std::cout << arr[i] << " ";
		//printf("%f ", arr[i]);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	printf("\n\n");
}
double processArray(double inpt[], size_t length, double x, double outpt[])
{
	for (size_t i = 0; i < length; ++i)				// заполнение массива случ. числами [-20.0..70.0]
	{
		inpt[i] = (double)(rand() % 90) - 20.0;
	}
	printArr(inpt, length);

	double maxItem = -30;
	size_t indexM = 0;
	for (size_t i = 0; i < length; ++i)				//поиск наибольшего значения
	{
		if (abs(inpt[i]) > abs(maxItem))
		{
			maxItem = inpt[i];
			indexM = i;
		}
	}

	for (size_t i = 0; i < length; ++i)				//изменение исходного массива
	{
		inpt[i] = inpt[i] / maxItem;
	}

	for (size_t i = 0; i < indexM; ++i)				//создание нового массива
	{
		outpt[i] = inpt[i];
	}
	for (size_t i = indexM; i < length; ++i)
	{
		outpt[i] = x;
	}

	return maxItem;
}
void task1()
{
	const size_t Length = 20;

	double
		randomArr[Length] = { 0.0 },
		arr[Length] = { 0.0 };
	double x;

	time_t now = time(0); //чтобы прям рандомненько
	srand((size_t)now); //подключение рандома

	std::cout << "Input X : "; std::cin >> x; std::cout << std::endl;
	//printf("Input X : "); 	scanf_s("%f", &x); printf("%f",x);
	double res = processArray(randomArr, Length, x, arr);
	std::cout << "Max Item = " << res << std::endl;
	printf("Max Item = %f", res);
	printArr(randomArr, Length);
	printArr(arr, Length);
}
class shop1
{
	std::string name;
	std::string address;
	int foundation;
	int num;
	int profit;
	double profit3month;
	//double profitaverage;
};
class shop2
{
	std::string name;
	std::string address;
	int foundation;
	int num;
	int profit;
	//double profit3month;
};
int main12344()
{
	std::cout << sizeof(shop1) << "\n";
	std::cout << sizeof(shop2) << "\n";
	std::cout << sizeof(int) << "\n";
	std::cout << sizeof(std::string) << "\n";

	char x;

	/*std::cout << "Input number of task (1-3) : ";
	char x;
	std::cin >> x;
	switch (x)
	{
	case '1': task1();
		break;
	case '2': task2();
		break;
	case '3': task3();
		break;
	default: std::cout << "Incorrect char" << std::endl;
		break;
	}*/
	std::cin >> x;
	return 0;
}
int main()
{
	int x[10] = { 42, 0 , 5, 3 };
	int* y = x + 3;
	int z = *x + *y;
	std::cout << *x << " + " << *y << " = " << z<<std::endl;
	std::cout << pow(2,3);
	std::cin >> z;
	return 0;
}
