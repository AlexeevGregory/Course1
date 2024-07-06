#include <stdio.h>
#include <chrono>
#include <iostream>
#include <cmath>
using namespace std;
using namespace chrono;

int main()
{
	setlocale(0, "");
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
		cout<< "\n" << "Хотите повторить?(1 - да, 0 - нет)" << "\n";
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