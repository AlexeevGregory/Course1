#include <iostream>
#include <Windows.h>
using namespace std;

const int n = 6;
void FillingArrRand(int Arr[n][n], const int N);
void OutPut(int Arr[n][n], const int N);
void FillingNewElements_A(int Arr[n][n], const int N, int* P);
void FillingNewElements_B(int Arr[n][n], const int N, int* P);
void Permutation_A(int Arr[n][n], int FinalArr[n][n], const int N);
void Permutation_B(int Arr[n][n], int FinalArr[n][n], const int N);
void Permutation_C(int Arr[n][n], int FinalArr[n][n], const int N);
void Permutation_D(int Arr[n][n], int FinalArr[n][n], const int N);
void Sorting(int Arr[n][n], int SortArr[n][n], const int N, int* P);
void Calculation(int Arr[n][n], const int N, int* P);

int main()
{
	setlocale(0, "");
	int Mas[n][n], MasOfPermutation[n][n], MasSort[n][n], Number, *p = *Mas, * pSortMas = *MasSort;
	cout << "Меню заданий:" << "\n" << "1 - Подстановка элементов в матрицу" << "\n" << "2 - Перестановка блоков матрицу" << "\n" << "3 - Сортировка матрицы" << "\n" << "4 - Взаимодействие числа с матрицей" << "\n";
	cout << "Введите номер задания: ";
	cin >> Number;
	switch (Number)
	{
	case(1):
		system("cls");
		Number = 0;
		cout << "Меню задания:" << "\n" << "1 - способ (а) заполнения элемента" << "\n" << "2 - способ (b) заполнения элемента" << "\n" << "Введите число: ";
		cin >> Number;
		if ((Number >= 1) and (Number <= 2))
		{
			if (Number == 1)
			{
				system("cls");
				FillingNewElements_A(Mas, n, p);
			}	
			if (Number == 2)
			{
				system("cls");
				FillingNewElements_B(Mas, n, p);
			}
		}
				
		else
			cout << "Ошибка: введена неправильна переменная" << "\n";
		break;
	case(2):
		system("cls");
		FillingArrRand(Mas, n);
		Number = 0;
		cout << "Меню задания:" << "\n" << "1 - способ (а) перестановки блоков массива" << "\n" << "2 - способ (b) перестановки блоков массива" << "\n" << "3 - способ (c) перестановки блоков массива" << "\n" << "4 - способ (d) перестановки блоков массива" << "\n" << "Введите число: ";
		cin >> Number;
		system("cls");
		cout << "Массив: " << "\n";
		OutPut(Mas, n);
		cout << "Результат работы:" << "\n";
		if ((Number >= 1) and (Number <= 4))
		{
			if (Number == 1)
				Permutation_A(Mas, MasOfPermutation, n);
			if (Number == 2)
				Permutation_B(Mas, MasOfPermutation, n);
			if (Number == 3)
				Permutation_C(Mas, MasOfPermutation, n);
			if (Number == 4)
				Permutation_D(Mas, MasOfPermutation, n);
		}
		else
			cout << "Ошибка: введена неправильна переменная" << "\n";
		break;
	case(3):
		FillingArrRand(Mas, n);
		cout << "Массив:" << "\n";
		OutPut(Mas, n);
		cout << "Отсортированный массив:" << "\n";
		Sorting(Mas, MasSort, n, pSortMas);
		break;
	case(4):
		system("cls");
		Calculation(Mas, n, p);
		break;
	default:
		cout << "Ошибка: введена неправильна переменная" << "\n";
		break;
	}
}
void FillingArr(int Arr[n][n], const int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Arr[i][j] = 0;
		}
	}
}
void FillingArrRand(int Arr[n][n], const int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Arr[i][j] = rand() % (N*N) - 1;
		}
	}
}

void OutPut(int Arr[n][n], const int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << Arr[i][j] << " ";
		}
		cout << "\n";
	}
}
//Задание 1
void FillingNewElements_A(int Arr[n][n], const int N, int* P)
{
	FillingArr(Arr, N);
	int count = 0, count_index = 0;
	while (count_index < n * n)
	{
		for (int i = count; i < n; ++i)
		{
			if (count_index < n)
			{
				*P = rand() % (n * n) + 1;
				OutPut(Arr, N);
				if (count_index != n - 1)
					P = P + 1;
				count_index++;
				Sleep(1000);
				system("cls");
			}
			else
			{
				P = P + 1;
				*P = rand() % (n * n) + 1;
				OutPut(Arr, N);
				count_index++;
				Sleep(1000);
				system("cls");
			}

		}
		count++;
		for (int i = count; i < n; ++i)
		{
			P = P + n;
			*P = rand() % (n * n) + 1;
			OutPut(Arr, N);
			count_index++;
			Sleep(1000);
			system("cls");

		}
		for (int i = count; i < n; ++i)
		{
			P = P - 1;
			*P = rand() % (n * n) + 1;
			OutPut(Arr, N);
			count_index++;
			Sleep(1000);
			system("cls");

		}
		count++;
		for (int i = count; i < n; ++i)
		{
			P = P - (n);
			*P = rand() % (n * n) + 1;
			OutPut(Arr, N);
			count_index++;
			Sleep(1000);
			system("cls");
		}
	}
	OutPut(Arr, N);
	cout << "\n";
}
void FillingNewElements_B(int Arr[n][n], const int N, int* P)
{
	FillingArr(Arr, N);
	int count_index = 0;
	while (count_index < n * n)
	{
		for (int i = 0; i < n; ++i)
		{
			*P = rand() % (n * n) + 1;
			OutPut(Arr, N);
			count_index++;
			if ((count_index % n != 0) and (count_index != 0))
				P = P + n;
			Sleep(100);
			system("cls");
		}
		if (count_index < N * N)
			P = P + 1;
		for (int i = 0; i < n; ++i)
		{
			*P = rand() % (n * n) + 1;
			OutPut(Arr, N);
			count_index++;
			if (count_index % n != 0)
				P = P - n;
			Sleep(100);
			system("cls");
		}
		if (count_index < N * N)
			P = P + 1;
	}
	OutPut(Arr, N);
	cout << "\n";
}
//Задание 2
void Permutation_A(int Arr[n][n], int FinalArr[n][n], const int N)
{
	for (int i = 0; i < N / 2; ++i)
	{
		for (int j = 0; j < N / 2; ++j)
		{
			FinalArr[i][j] = Arr[i + (N / 2)][j];
			FinalArr[i + (N / 2)][j] = Arr[i + (N / 2)][j + (N / 2)];
			FinalArr[i + (N / 2)][j + (N / 2)] = Arr[i][j + (N / 2)];
			FinalArr[i][j + (N / 2)] = Arr[i][j];
		}
	}
	OutPut(FinalArr, N);
	cout << "\n";
}
void Permutation_B(int Arr[n][n], int FinalArr[n][n], const int N)
{
	for (int i = 0; i < N / 2; ++i)
	{
		for (int j = 0; j < N / 2; ++j)
		{
			FinalArr[i][j] = Arr[i + (N / 2)][j + (N / 2)];
			FinalArr[i + (N / 2)][j + (N / 2)] = Arr[i][j];
			FinalArr[i + (N / 2)][j] = Arr[i][j + (N / 2)];
			FinalArr[i][j + (N / 2)] = Arr[i + (N / 2)][j];
		}
	}
	OutPut(FinalArr, N);
	cout << "\n";
}
void Permutation_C(int Arr[n][n], int FinalArr[n][n], const int N)
{
	for (int i = 0; i < N / 2; ++i)
	{
		for (int j = 0; j < N / 2; ++j)
		{
			FinalArr[i][j] = Arr[i + (N / 2)][j];
			FinalArr[i + (N / 2)][j] = Arr[i][j];
			FinalArr[i + (N / 2)][j + (N / 2)] = Arr[i][j + (N / 2)];
			FinalArr[i][j + (N / 2)] = Arr[i + (N / 2)][j + (N / 2)];
		}
	}
	OutPut(FinalArr, N);
	cout << "\n";
}
void Permutation_D(int Arr[n][n], int FinalArr[n][n], const int N)
{
	for (int i = 0; i < N / 2; ++i)
	{
		for (int j = 0; j < N / 2; ++j)
		{
			FinalArr[i][j] = Arr[i][j + (N / 2)];
			FinalArr[i][j + (N / 2)] = Arr[i][j];
			FinalArr[i + (N / 2)][j + (N / 2)] = Arr[i + (N / 2)][j];
			FinalArr[i + (N / 2)][j] = Arr[i + (N /
				2)][j + (N / 2)];
		}
	}
	OutPut(FinalArr, N);
	cout << "\n";
}
//Задание 3
void Sorting(int Arr[n][n], int SortArr[n][n], const int N, int* PSort)
{
	FillingArrRand(Arr, N);
	int Element = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			SortArr[i][j] = Arr[i][j];
		}
	}
	for (int i = 0; i < (N * N); ++i)
	{
		for (int j = 0; j < (N * N) - 1; ++j)
		{
			if (*PSort > *(PSort + 1))
			{
				Element = *(PSort + 1);
				*(PSort + 1) = *PSort;
				*PSort = Element;
			}
			PSort = PSort + 1;
		}
		for (int j = 0; j < (N * N) - 1; ++j)
		{
			if (*PSort < *(PSort - 1))
			{
				Element = *(PSort - 1);
				*(PSort - 1) = *PSort;
				*PSort = Element;
			}
			PSort = PSort - 1;
		}
	}
	OutPut(SortArr, N);
	cout << "\n";
}
//Задание 4
void Calculation(int Arr[n][n], const int N, int* P)
{
	FillingArrRand(Arr, N);
	int Number, Flag;
	cout << "Введите число, с которым будут взаимодействовать элементы матрицы: ";
	cin >> Number;
	cout << "Меню:" << "\n" << "0 - Умножение" << "\n" << "1 - Деление" << "\n" << "2 - Сложение" << "\n" << "3 - Вычитание" << "\n";
	cout << "Введите число: ";
	cin >> Flag;
	system("cls");
	cout << "Матрица:" << "\n";
	OutPut(Arr, N);
	switch(Flag)
	{
	case(0):
		for (int i = 0; i < N*N; ++i)
		{
			*P = *P * Number;
			P = P + 1;
		}
		cout << "Итог:" << "\n";
		OutPut(Arr, N);
		break;
	case(1):
		for (int i = 0; i < N * N; ++i)
		{
			*P = *P / Number;
			P = P + 1;
		}
		cout << "Итог:" << "\n";
		OutPut(Arr, N);
		break;
	case(2):
		for (int i = 0; i < N * N; ++i)
		{
			*P = *P + Number;
			P = P + 1;
		}
		cout << "Итог:" << "\n";
		OutPut(Arr, N);
		break;
	case(3):
		for (int i = 0; i < N * N; ++i)
		{
			*P = *P - Number;
			P = P + 1;
		}
		cout << "Итог:" << "\n";
		OutPut(Arr, N);
		break;
	default:
		cout << "Ошибка:введена неправильная переменная";
		break;
	}
}


//идз к работе
/*#include <iostream>
#include <Windows.h>
using namespace std;
const int n = 6;
void OutPut(int Arr[n][n], const int N);
void FillingArrRand(int Arr[n][n], const int N);
void Multiplication(int Arr1[n][n], int Arr2[n][n], const int N);
int main()
{
	setlocale(0, "");
	int Mas1[n][n], Mas2[n][n];
	FillingArrRand(Mas1, n);
	cout << "\n";
	FillingArrRand(Mas2, n);
	cout << "\n";
	Multiplication(Mas1, Mas2, n);
}

void OutPut(int Arr[n][n], const int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << Arr[i][j] << " ";
		}
		cout << "\n";
	}
}
void FillingArrRand(int Arr[n][n], const int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Arr[i][j] = rand() % (N * N) - 1;
		}
	}
	OutPut(Arr, N);
}
void FillingArr(int Arr[n][n], const int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Arr[i][j] = 0;
		}
	}
}
void Multiplication(int Arr1[n][n], int Arr2[n][n], const int N)
{
	int Arr3[n][n];
	FillingArr(Arr3, N);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int m = 0; m < N; ++m)
			{
				Arr3[i][j] += (Arr1[i][m] * Arr2[m][j]);
			}
			OutPut(Arr3, N);
			Sleep(100);
			system("cls");
		}
	}
	cout << "Итоговая матрица:" << "\n";
	OutPut(Arr3, N);

}*/