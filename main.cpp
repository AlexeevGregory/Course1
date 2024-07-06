#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	setlocale(0, "");
	unsigned int lines, mask;
	int celoe, nomer, b;
	while (true)
	{
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




//ИДЗ к практической работе 1 ( арифметический метод (3-4 задания)).
/*#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	setlocale(0, "");
	unsigned int lines, mask;
	float k, ost, n;
	int k_c, p = 1, f, m, K;
	cout << "Введите номер задания: ";
	cin >> m;
	switch (m) {

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
		mask = 1 << lines - 1;
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
		cin >> k;
		if (k >= 0)
		{
			f = 1;
			k_c = k / 1;
			ost = k - k_c;
		}
		else
		{
			f = -1;
			k *= (-1);
			k_c = k / 1;
			ost = k - k_c;
		}
		int mas_p3[8], mas_mant3[23];

		n = k;
		while ((n <= 1) or (n > 2))
		{
			if (n > 2)
			{
				p++;
				n /= 2;

			}
			else
			{
				p--;
				n *= 2;
			}
		}

		for (int i = 0; i < 23; i++)
		{
			if (k_c > 1)
			{
				mas_mant3[i] = k_c % 2;
				k_c /= 2;
			}
			else
			{
				if (ost != 0)
				{
					ost *= 2;
					if (ost >= 1)
					{
						mas_mant3[i] = 1;
						ost -= 1;
					}
					else
					{
						mas_mant3[i] = 0;
					}
				}
				else
				{
					mas_mant3[i] = 0;
				}
			}
		}

		p += pow(2, 8 - 1) - 1;
		for (int i = 0; i < 8; i++)
		{
			if (p > 1)
			{
				mas_p3[i] = p % 2;
				p /= 2;
			}
			else
			{
				mas_p3[i] = 0;
			}
		}

		//ЗАПИСЬ ЧИСЛА В ДВОИЧНОМ КОДЕ:
		if (f > 0)
		{
			cout << 0 << " ";
		}
		else
		{
			cout << 1 << " ";
		}

		for (int i = 0; i < 8; ++i)
		{
			cout << setw(0) << left << mas_p3[i];
		}

		cout << " ";

		for (int i = 0; i < 23; ++i)
		{
			cout << setw(0) << left << mas_mant3[i];
		}
		cout << endl;

		return 0;
		break;
	case 4:
		cout << "Введите число: ";
		double k1, ost1;
		cin >> k1;
		if (k1 >= 0)
		{
			f = 1;
			k_c = k1 / 1;
			ost1 = k1 - k_c;
		}
		else
		{
			f = -1;
			k1 *= (-1);
			k_c = k1 / 1;
			ost1 = k1 - k_c;
		}
		int mas_p[11], mas_mant[52];

		n = k1;
		while ((n <= 1) or (n > 2))
		{
			if (n > 2)
			{
				p++;
				n /= 2;

			}
			else
			{
				p--;
				n *= 2;
			}
		}

		for (int i = 0; i < 52; i++)
		{
			if (k_c > 1)
			{
				mas_mant[i] = k_c % 2;
				k_c /= 2;
			}
			else
			{
				if (ost1 != 0)
				{
					ost1 *= 2;
					if (ost1 >= 1)
					{
						mas_mant[i] = 1;
						ost1 -= 1;
					}
					else
					{
						mas_mant[i] = 0;
					}
				}
				else
				{
					mas_mant[i] = 0;
				}
			}
		}

		p += pow(2, 8 - 1) - 1;
		for (int i = 0; i < 11; i++)
		{
			if (p > 1)
			{
				mas_p[i] = p % 2;
				p /= 2;
			}
			else
			{
				mas_p[i] = 0;
			}
		}

		//ЗАПИСЬ ЧИСЛА В ДВОИЧНОМ КОДЕ:
		if (f > 0)
		{
			cout << 0 << " ";
		}
		else
		{
			cout << 1 << " ";
		}

		for (int i = 0; i < 11; ++i)
		{
			cout << setw(0) << left << mas_p[i];
		}

		cout << " ";

		for (int i = 0; i < 52; ++i)
		{
			cout << setw(0) << left << mas_mant[i];
		}
		cout << endl;

		return 0;
		break;

	}
	return 0;
}*/