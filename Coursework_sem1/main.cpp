#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>
#include <cmath>
#include <Windows.h>

using namespace std;
using namespace chrono;
void Practic_1();
void Practic_2();
void Practic_3();
void Practic_4();
//Функции для 3 практической
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
//Функции к 4 практической
string FileReading();
string FileEditing();
string FileSorting();
string FileChange();
void Searching(string buffer);

int main()
{
	setlocale(0, "");
	int Number;
	cout << "Введите номер работы(1-4): ";
	cin >> Number;
	switch (Number)
	{
	case(1):
		Practic_1();
		break;
	case(2):
		Practic_2();
		break;
	case(3):
		Practic_3();
		break;
	case(4):
		Practic_4();
		break;
	default:
		cout << "Ошибка: введено неправильное значение";
		break;
	}
}

void Practic_1()
{
	unsigned int lines, mask;
	int celoe, nomer, b;
	while (true)
	{
		cout << "Меню:" << endl << "1)Вывод количество отведенных байт на различные типы данных"<< endl << "2)Двоичное представление целого числа в памяти" << endl << "3)Двоичное представление числа типа float в памяти" << endl << "4)Двоичное представление числа типа double в памяти" << endl;
		cout << "Введите номер задания(1-4): ";
		cin >> nomer;
		switch (nomer) {

		case 1:
			cout << "int: " << sizeof(int) << "\n";
			cout << "short int: " << sizeof(short int) << "\n";
			cout << "long int: " << sizeof(long int) << "\n";
			cout << "float: " << sizeof(float) << "\n";
			cout << "double: " << sizeof(double) << "\n";
			cout << "char: " << sizeof(char) << "\n";
			cout << "bool: " << sizeof(bool) << "\n";
			break;

		case 2:
			int K;
			cout << "Введите число: ";
			cin >> K;
			lines = 32;
			mask = 1 << (lines - 1);
			for (int i = 1; i <= lines; i++)
			{
				putchar(K & mask ? '1' : '0');
				K <<= 1;
				if (i % 8 == 0)
				{
					putchar(' ');
				}
				if (i % lines - 1 == 0)
				{
					putchar(' ');
				}
			}
			break;

		case 3:
			union
			{
				int value;
				float input_number;
			};
			cout << "Введите число: ";
			cin >> input_number;

			lines = 32;
			mask = 1 << lines - 1;
			for (int i = 1; i <= lines; i++)
			{
				putchar(value & mask ? '1' : '0');
				value <<= 1;
				if (i == 9)
				{
					putchar(' ');
				}
				if (i == 1)
				{
					putchar(' ');
				}
			}
			break;

		case 4:
			cout << "Введите число: ";
			int f = 0;
			union
			{
				int mas[2];
				double a;
			};
			std::cout << "Введите число: ";
			std::cin >> a;
			lines = 32,
				mask = 1;
			mask <<= (lines - 1);
			for (int j = 0; j < 2; j++)
			{
				// замена местами переменных int
				if (j == 0)
				{
					f += 1;
				}
				else
				{
					f -= 1;
				}
				for (int i = 0; i < lines; i++)
				{
					putchar(mas[f] & mask ? '1' : '0');
					mas[f] <<= 1;
					if ((i == 0) and (j == 0))
					{
						putchar(' ');
					}
					if ((i == 11) and (j == 0))
					{
						putchar(' ');
					}
				}
			}
			break;
		}
		if ((nomer != 1) and (nomer != 2) and (nomer != 3) and (nomer != 4))
		{
			cout << "Error";
			break;
		}
		else
		{
			std::cout << "\n" << "Продолжить?(1 - да; 0 - нет)" << "\n";
			cin >> b;
			if (b == 0)
			{
				break;
			}
		}
	}
}
void Practic_2()
{
	const int N = 100;
	int task, answer, mas[N], mas_sort[N];

	for (int i = 0; i < N; i++)
	{
		mas[i] = rand() % 199 - 99;
		mas_sort[i] = mas[i];
	}

	while (true)
	{
		int CountCombSort = 0, SwapSort;
		float k = 1.247, S = N - 1;
		int max = -100, min = 100;
		bool InsertSortFlag;
		int count = 0, average;
		int a, b;
		int number, bin, stepen, flag, nomer_bin;
		double val;
		int index1, index2{}, exchng1, exchng2;
		auto start = steady_clock::now();
		auto end = steady_clock::now();
		auto result = duration_cast<nanoseconds>(end - start);
		srand(time(0));

		cout << "\n" << "Введите номер задания: ";
		cin >> task;

		//Сортировка массива
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
				if (mas_sort[j] > mas_sort[j + 1]) {
					swap(mas_sort[j], mas_sort[j + 1]);
				}
		}


		switch (task)
		{
		case(1):
			cout << "Массив:" << "\n";
			for (int i = 0; i < N; i++)
			{
				cout << mas[i] << " ";
			}
			break;
		case(2):
			srand(time(0));
			cout << "\nBubble sort" << "\n";
			start = steady_clock::now();
			cout << endl;
			for (int i = 0; i < N - 1; i++)
			{
				for (int j = 0; j < N - i - 1; j++)
					if (mas_sort[j] > mas_sort[j + 1]) {
						swap(mas_sort[j], mas_sort[j + 1]);
					}
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			for (int i = 0; i < N; i++)
			{
				cout << mas_sort[i] << " ";
			}
			cout << "\n" << "Время: " << result.count() << " - ns" << "\n";
			cout << "\n\n";

			// Сбрасывание отсортированного массива 
			for (int i = 0; i < N; i++)
			{
				mas_sort[i] = mas[i];
			}

			srand(time(0));
			start = steady_clock::now();
			cout << endl;
			cout << "\nShaker sort" << "\n";
			for (int i = 0; i < N - 1; i++) {
				for (int j = 0; j < N - i - 1; j++) {
					if (mas_sort[j] > mas_sort[j + 1]) {
						swap(mas_sort[j], mas_sort[j + 1]);
					}
				}
				for (int j = N - 1; j >= 1; j--) {
					if (mas_sort[j] < mas_sort[j - 1]) {
						swap(mas_sort[j], mas_sort[j - 1]);
					}
				}
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			for (int i = 0; i < N; i++)
			{
				cout << mas_sort[i] << " ";
			}
			cout << "\n" << "Время: " << result.count() << " - ns" << "\n";
			cout << "\n\n";

			// Сбрасывание отсортированного массива
			for (int i = 0; i < N; i++)
			{
				mas_sort[i] = mas[i];
			}

			srand(time(0));
			start = steady_clock::now();
			cout << endl;
			cout << "\nInsert sort" << "\n";
			do
			{
				InsertSortFlag = false;
				for (int i = 0; i < N - 1; i++)
				{
					int j = i;
					while (mas_sort[j] > mas_sort[j + 1])
					{
						if (mas_sort[j] > mas_sort[j + 1])
						{
							swap(mas_sort[j], mas_sort[j + 1]);
							j--;
							InsertSortFlag = true;
						}
						break;
					}
				}

			} while (InsertSortFlag);
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			for (int i = 0; i < N; i++)
			{
				cout << mas_sort[i] << " ";
			}
			cout << "\n" << "Время: " << result.count() << " - ns" << "\n";
			cout << "\n\n";


			// Сбрасывание отсортированного массива
			for (int i = 0; i < N; i++)
			{
				mas_sort[i] = mas[i];
			}

			srand(time(0));
			cout << "\nComb sort" << "\n";
			start = steady_clock::now();
			cout << endl;
			while (S >= 1)
			{
				for (int i = 0; i + S < N; i++)
				{
					if (mas_sort[i] > mas_sort[int(i + S)])
					{
						SwapSort = mas_sort[int(i + S)];
						mas_sort[int(i + S)] = mas_sort[i];
						mas_sort[i] = SwapSort;
					}
				}
				S /= k;
			}

			while (true)
			{
				for (int i = 0; i < N - 1; i++)
				{
					if (mas_sort[i] > mas_sort[i + 1])
					{
						SwapSort = mas_sort[i + 1];
						mas_sort[i + 1] = mas_sort[i];
						mas_sort[i] = SwapSort;
					}
					else
						CountCombSort++;
				}
				if (CountCombSort == N - 1)
					break;
				else
					CountCombSort = 0;
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			for (int i = 0; i < N; i++)
			{
				cout << mas_sort[i] << " ";
			}
			cout << "\n" << "Время: " << result.count() << " - ns" << "\n";
			cout << "\n\n";
			break;

		case(3):
			srand(time(0));
			cout << "Задание 3:" << "\n";
			start = steady_clock::now();
			cout << endl;
			cout << "Нахождение минимума и максимума в неотсортированном массиве" << "\n";
			for (int i = 0; i < N; i++)
			{
				if (mas[i] >= max)
					max = mas[i];
				if (mas[i] <= min)
					min = mas[i];
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			cout << "Наибольший элемент массива: " << max << "\n" << "Наименьший элемент массива: " << min << "\n";
			cout << "Время: " << result.count() << " - ns" << "\n";

			//Сортировка массива
			for (int i = 0; i < N - 1; i++)
			{
				for (int j = 0; j < N - i - 1; j++)
					if (mas_sort[j] > mas_sort[j + 1]) {
						swap(mas_sort[j], mas_sort[j + 1]);
					}
			}
			srand(time(0));
			cout << "Нахождение минимума и максимума в отсортированном массиве" << "\n";
			start = steady_clock::now();
			cout << endl;
			min = mas_sort[0];
			max = mas_sort[99];
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			cout << "Наибольший элемент массива: " << max << "\n" << "Наименьший элемент массива: " << min << "\n";
			cout << "Время: " << result.count() << " - ns" << "\n";
			cout << "\n\n";
			break;

		case (4):
			max = mas_sort[0];
			min = mas_sort[99];
			average = (max + min) / 2;
			cout << "Индексы значений: ";
			for (int i = 0; i < N; i++)
			{
				if (mas_sort[i] <= average)
				{
					if (mas_sort[i] == average)
					{
						cout << i << " ";
						count++;
					}
				}
				else
					break;
			}
			cout << "\n" << "Количество элементов, равных среднему значению: " << count;
			cout << "\n\n";
			break;

		case (5):
			cout << "Введите число: ";
			cin >> a;
			for (int i = 0; i < N; i++)
			{
				if (mas_sort[i] < a)
					count++;
				else
					break;
			}
			cout << "Количество чисел, которые меньше введенного числа: " << count << "\n\n";
			break;

		case (6):
			cout << "Введите число: ";
			cin >> b;
			for (int i = N - 1; i > 0; i--)
			{
				if (mas_sort[i] > b)
					count++;
				else
					break;
			}
			cout << "Количество чисел, которые больше введенного числа: " << count << "\n\n";
			break;

		case(7):
			cout << "Введите число: ";
			cin >> number;

			//Бинарный поиск числа
			cout << "Этапы процесса бинарного поиска: ";
			stepen = 0;
			bin = ((N / 2) - 1);
			val = 0;
			while (val < N)
			{
				stepen++;
				val = pow(2, stepen);
			}
			nomer_bin = bin;
			start = steady_clock::now();
			cout << endl;
			while (mas_sort[nomer_bin] != number)
			{
				if (count <= log2(val))
				{
					bin /= 2;
					if (mas_sort[nomer_bin] < number)
					{
						count++;
						nomer_bin += bin;
						std::cout << mas_sort[nomer_bin] << " ";
					}
					else
					{
						count++;
						nomer_bin -= bin;
						std::cout << mas_sort[nomer_bin] << " ";
					}
				}
				else
				{
					std::cout << "\n" << "Введенного числа не существует в массиве" << "\n";
					break;
				}
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			std::cout << "\n" << "Количество ходов бинарного поиска: " << count;
			cout << "\n" << "Время: " << result.count() << " - ns" << "\n";


			//Простой перебор чисел
			srand(time(0));
			start = steady_clock::now();
			cout << endl;
			for (int i = 0; i < N; i++)
			{
				if (mas_sort[i] = number)
				{
					flag = 1;
					cout << "Число по простому перебору: " << mas_sort[i] << "\n";
					break;
				}
			}
			if (flag == 0)
			{
				cout << "\n" << "Введенное число отсутствует" << "\n";
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			cout << "Время: " << result.count() << " - ns" << "\n\n";
			break;

		case (8):
			cout << "Введите индексы чисел, которые хотите поменять местами: ";
			cin >> index1 >> index2;
			exchng1 = mas_sort[index1];
			exchng2 = mas_sort[index2];
			mas_sort[index1] = exchng2;
			mas_sort[index2] = exchng1;
			for (int i = 0; i < N; i++)
			{
				if (i == index1)
				{
					cout << mas_sort[i] << "!" << " ";
				}
				else
				{
					if (i == index2)
					{
						cout << mas_sort[i] << "!" << " ";
					}
					else
						cout << mas_sort[i] << " ";
				}


			}
			break;

		}
		cout << "\n" << "Хотите повторить?(1 - да, 0 - нет)" << "\n";
		cin >> answer;
		if (answer == 0)
		{
			break;
		}
		else
		{
			if ((answer != 0) and (answer != 1))
			{
				cout << "Ошибка: введено неправильное значение переменной" << "\n";
				cout << "\n" << "Хотите повторить?(1 - да, 0 - нет)" << "\n";
				cin >> answer;
				if (answer == 0)
					break;
			}
		}
	}
}
void Practic_3()
{
	int Mas[n][n], MasOfPermutation[n][n], MasSort[n][n], Number, * p = *Mas, * pSortMas = *MasSort;
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
void Practic_4()
{
	string OutPutLine;
	int n;
	cout << "Меню:" << endl << "2)Редактирование тескта." << endl << "3)Вывести на экран слова последовательности в обратном порядке." << endl << "4)Вывести на экран ту же последовательность, заменив во всех словах первую букву соответствующей прописной буквой." << endl << "5)Нахождение подстроки по методу Бойера-Мура." << endl;
	cout << "Введите номер задания: ";
	cin >> n;
	system("cls");
	switch (n)
	{
	case(2):
		cout << FileEditing() << endl;
		break;
	case(3):
		cout << FileSorting() << endl;
		break;
	case(4):
		cout << FileChange() << endl;
		break;
	case(5):
		Searching(OutPutLine);
		break;
	default:
		cout << "Ошибка: введено неправильное значение";
		break;
	}
}

//Функции к 3 практической
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
			Arr[i][j] = rand() % (N * N) - 1;
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
	switch (Flag)
	{
	case(0):
		for (int i = 0; i < N * N; ++i)
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

//Функции к 4 практической
string FileReading()
{
	string Name, line;
	cout << "Введите название файла: ";
	cin >> Name;
	ifstream File;
	File.open(Name);
	if (File.is_open())
	{
		while (getline(File, line))
		{
		}
	}
	File.close();
	return line;
}
string FileEditing()
{
	string CapsLetter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", Letter = "abcdefghijklmnopqrstuvwxyz", buffer;
	char LetterReplace[2] = { ' ', '\0' }, PunctMarks[] = { '.',',',';',':','?','!','"','[',']','{','}','\0' };
	int j, n;
	int flag = 0;
	cout << "Какой способ чтения данных вам нужен?" << endl << "1)Чтение с клавиатуры." << endl << "2)Чтение с файла." << endl << "Введите число: ";
	cin >> n;
	if (n == 1)
	{
		getline(cin, buffer);
	}
	else
		if (n == 2)
		{
			buffer = FileReading();
		}
		else
			cout << "Ошибка: введено неправильное значение";
	system("cls");
	cout << "Изначальный вид строки" << endl << buffer << endl << "Итог работы:" << endl;
	for (int i = 0; i < buffer.length() - 1; ++i)
	{
		//Удаление лишних пробелов
		if ((buffer[i] == ' ') and (buffer[i + 1] == ' '))
		{
			buffer.erase(i, 1);
		}
		//Замена букв на строчные
		if (CapsLetter.find(buffer[i], 0) != (-1))
		{
			j = CapsLetter.find(buffer[i], 0);
			LetterReplace[0] = Letter[j];
			buffer.replace(i, 1, LetterReplace);
		}
		//Нахождение "лишних" знаков препинания
		for (int j = 0; j < strlen(PunctMarks); ++j)
		{
			if (PunctMarks[j] == buffer[i])
				flag++;
		}
		//Удаление "лишних" знаков препинания
		if ((flag == 1) and (buffer[i] == buffer[i + 1]))
		{
			buffer.erase(i, 1);
		}
	}
	return buffer;
}
string FileSorting()
{
	string CapsLetter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", Letter = "abcdefghijklmnopqrstuvwxyz", SortLine, line;
	int j;
	string buffer = FileEditing();
	while (buffer.rfind(' ') != (-1))
	{
		j = buffer.rfind(' ') + 1;
		while (j != buffer.length() - 1)
		{
			line += buffer[j];
			j++;
		}
		SortLine += line;
		buffer.erase(buffer.rfind(' '), line.length() + 1);
		line = "";
		SortLine += ' ';
	}
	SortLine += buffer;
	return SortLine;
}
string FileChange()
{
	string CapsLetter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", Letter = "abcdefghijklmnopqrstuvwxyz", SortLine, line;
	int j = 0;
	string buffer = FileSorting();
	char LetterReplace[2] = { ' ', '\0' };
	for (int i = 0; i < buffer.length(); ++i)
	{
		if (i == 0)
		{
			j = Letter.find(buffer[i], 0);
			LetterReplace[0] = CapsLetter[j];
			buffer.replace(i, 1, LetterReplace);
		}
		else
		{
			if ((buffer[i] == ' ') and (Letter.find(buffer[i + 1], 0) != (-1)))
			{
				j = Letter.find(buffer[i + 1], 0);
				LetterReplace[0] = CapsLetter[j];
				buffer.replace(i + 1, 1, LetterReplace);
			}
		}
	}
	return buffer;
}
void Searching(string buffer)
{
	string underline, LineOfComparison;
	buffer = FileEditing();
	cout << "Нахождение подстроки по метод Бойера-Мура:" << endl;
	cout << "Введите подстроку, которую вы хотите найти: ";
	cin >> underline;
	int index = 0, count = 0, CountOfLines = 0, j = 0;
	while (index < buffer.length())
	{
		if (index + underline.length() <= buffer.length())
		{
			for (int k = index; k < underline.length() + index; ++k)
			{
				LineOfComparison += buffer[k];
			}
			j = underline.length() - 1;
			while (LineOfComparison[j] == underline[j])
			{
				count++;
				if (j > 0)
					j--;
				else
					break;
			}
			if ((count == 0) and (underline.rfind(LineOfComparison[LineOfComparison.length() - 1]) != (-1)))
			{
				j = underline.length() - underline.rfind(LineOfComparison[LineOfComparison.length() - 1]) - 1;
			}
			else
				if (count == underline.length())
				{
					CountOfLines++;
					j = 1;
				}
				else
					if (underline.rfind(LineOfComparison[LineOfComparison.length() - 1]) != (-1))
						j = underline.length();
					else
						j = underline.length() - count;
			count = 0;
			index += j;
			LineOfComparison = "";
		}
		else
			break;
	}
	cout << "Количество найденных подстрок в строке: " << CountOfLines << endl;
	CountOfLines = 0;
	cout << "Линейный поиск подстроки" << endl;
	for (int i = 0; i < buffer.length() - underline.length(); ++i)
	{
		count = 0;
		for (int n = 0; n < underline.length(); ++n)
		{
			if (underline[n] == buffer[n + i])
				count++;
		}
		if (count == underline.length())
			CountOfLines++;
	}
	cout << "Количество найденных подстрок в строке линейным поиском: " << CountOfLines;
}