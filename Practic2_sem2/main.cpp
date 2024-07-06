#include <iostream>
#include <string>
#include <stdio.h> 
#include <chrono> 
using namespace std;
using namespace chrono;

struct List {
	int data = 0;
	List* head = 0;
	List* tail = 0;
};

struct List* CreateList(unsigned Length) {
	List* Curr = 0, * Next = 0;
	for (unsigned i = 1; i <= Length; ++i)
	{
		Curr = new List;
		Curr->tail = Next;
		if (Next)
			Next->head = Curr;
		Next = Curr;
	}
	Curr->head = 0;
	return Curr;
}
int CountOfElements(List* Item) {
	int count = 0;
	while (Item) {
		count++;
		Item = Item->tail;
	}
	return count;
}
struct List* DelHeadItem(List* Beg, List* HeadItem, int count) {
	if (count > 1) {
		struct List* Item = Beg->tail;
		Item->head = NULL;
		delete Beg;
		HeadItem = Item;
	}
	else delete Beg;
	return HeadItem;
}
void DelItem(List*& Beg) {
	struct List* prev = Beg->head, * next = Beg->tail;
	if (prev != NULL) prev->tail = Beg->tail;
	if (next != NULL) prev->head = Beg->head;
	delete Beg;
}
void AddItem(List* root, List* Beg, int number, int index) {
	struct List* Item, * p;
	Item = new List;
	if (index != -1) {
		p = Beg->tail;
		Beg->tail = Item;
		Item->data = number;
		Item->tail = p;
		Item->head = Beg;
		if (p != NULL)
			p->head = Item;
	}
	else {
		Item->data = number;
		Item->head = root->head;
		root->head = Item;
		Beg->head = Item;
	}

}
void InfoOfList(List* Item) {
	cout << "Список:" << endl;
	while (Item)
	{
		cout << Item->data << " ";
		Item = Item->tail;
	}
	cout << endl;
}
struct List* Swap(struct List* Item1, struct List* Item2, struct List* root) {
	struct List* prev1 = Item1->head, * prev2 = Item2->head, * next1 = Item1->tail, * next2 = Item2->tail;
	if (Item2 == next1) {
		Item2->tail = Item1;
		Item2->head = prev1;
		Item1->tail = next2;
		Item1->head = Item2;
		if (next2 != NULL) next2->head = Item1;
		if (Item1 != root) prev1->tail = Item2;
	}
	else {
		if (Item1 == next2)
		{
			Item1->tail = Item2;
			Item1->head = prev2;
			Item2->tail = next1;
			Item2->head = Item1;
			if (next1 != NULL) next1->head = Item2;
			if (Item1 != root) prev2->tail = Item1;
		}
		else {
			if (Item1 != root) prev1->tail = Item2;
			Item2->tail = next1;
			if (Item2 != root) prev2->tail = Item1;
			Item1->tail = next2;
			Item2->head = prev1;
			if (next2 != NULL) next2->head = Item1;
			Item1->head = prev2;
			if (next1 != NULL) next1->head = Item2;
		}
	}
	if (Item1 == root) return(Item2);
	if (Item2 == root) return(Item1);
	return(root);
}
//задание 1(а)
void CreateDoubleLineList_A(List* list, List* Item) {
	int n;
	cout << "Введите число (количество элементов списка): ";
	cin >> n;
	list = CreateList(n);
	Item = list;
	cout << "Список: " << endl;
	while (Item)
	{
		Item->data = rand() % 100 - 1;
		cout << Item->data << " ";
		Item = Item->tail;
	}
	cout << endl;
}
//задание 1(б)
void CreateDoubleLineList_B(List* list, List* Item) {
	string str, str1;
	int count = 0, size = 0;
	List* Reserv_Item;
	cin.get();
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') count++;
	}
	size = ++count;
	list = CreateList(count);
	Item = list;
	int* arr = new int[size];
	count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') { str1 += str[i]; }
		if (i == str.length() - 1) { arr[count] = stoi(str1); count++; str1 = " "; }
		if (str[i] == ' ') { arr[count] = stoi(str1); count++; str1 = " "; }
	}
	count = 0;
	while (Item)
	{
		Item->data = arr[count];
		cout << Item->data << " ";
		Item = Item->tail;
		count++;
	}
	cout << endl;
	delete[] arr;
}
//задание 2
void TimeToCreateList(List* root) {
	int n;
	cout << "Введите число: ";
	cin >> n;
	auto start = steady_clock::now();
	root = CreateList(n);
	auto end = steady_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	cout << "Время, затраченное на создание списка: " << result.count() << " наносекунд" << endl;
	start = steady_clock::now();
	int* arr = new int[n];
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "Время, затраченное на создание массива: " << result.count() << " наносекунд" << endl;
}
//задание 3
void Third_Question(List* root, List* Item) {
	int n1, n2, index, number, count = 0, flag = 0, CountOfItem = 0, FlagOfNumber = 0, end = 0;
	List* ElementOfCurrIndex = 0, * SecondElement = 0;
	int n;
	cout << "Введите число (количество элементов списка): ";
	cin >> n;
	root = CreateList(n);
	Item = root;
	cout << "Список: " << endl;
	while (Item)
	{
		Item->data = rand() % 100 - 1;
		cout << Item->data << " ";
		Item = Item->tail;
	}
	Item = root;
	cout << endl;
	while (true) {
		CountOfItem = 0; flag = 0; FlagOfNumber = 0;
		cout << "Меню: " << '\n' << "1) Удаление элемента" << '\n' << "2) Добавление элемента" << '\n' << "3) Обмен элементов" << '\n' << "4) Получение элемента" << endl << "5) Прекращение работы со списком" << endl << "Введите число: ";
		cin >> n1;
		switch (n1)
		{
		case(1):
			cout << "1) Удаление элемента по индексу" << '\n' << "2) Удаление элемента по значению" << '\n' << "Введите число: ";
			cin >> n2;
			switch (n2)
			{
			case(1):
				cout << "Введите индекс элемента: ";
				cin >> index;
				if (index < n) {
					while (Item)
					{
						if (count == index) {
							ElementOfCurrIndex = Item;
							count = 0;
							break;
						}
						else {
							count++;
							Item = Item->tail;
						}
					}
					Item = root;
					CountOfItem = CountOfElements(Item);
					if (ElementOfCurrIndex == root) root = DelHeadItem(ElementOfCurrIndex, root, CountOfItem);
					else DelItem(ElementOfCurrIndex);
					if (CountOfItem == 1) {
						FlagOfNumber = 1;
					}
					else {
						Item = root;
						InfoOfList(Item);
					}

				}
				else {
					cout << "Введен неправильный индекс" << endl;
				}
				break;
			case(2):
				cout << "Введите значение элемента: ";
				cin >> number;
				while (Item)
				{
					if (number == Item->data) {
						ElementOfCurrIndex = Item;
						FlagOfNumber = 1;
						break;
					}
					else {
						Item = Item->tail;
					}
				}
				Item = root;
				CountOfItem = CountOfElements(Item);
				if (FlagOfNumber == 1) {
					if (ElementOfCurrIndex == root) root = DelHeadItem(ElementOfCurrIndex, root, CountOfItem);
					else DelItem(ElementOfCurrIndex);
					if (CountOfItem == 1) {
						FlagOfNumber = 1;
					}
					else {
						Item = root;
						InfoOfList(Item);
						FlagOfNumber = 0;
					}
				}
				else
					cout << "Введенное значение не найдено" << endl;
				break;
			default:
				cout << "Введено неправильное значение" << endl;
				break;
			}
			break;
		case(2):
			cout << "Введите индекс элемента списка, перед которым нужно добавить новый элемент или (-1), чтобы поставить новый элемент в начало списка: ";
			cin >> index;
			while (Item)
			{
				if (index == -1) {
					ElementOfCurrIndex = Item;
					break;
				}
				if (count == index) {
					ElementOfCurrIndex = Item;
					count = 0;
					break;
				}
				if (count != index) {
					count++;
					Item = Item->tail;
				}
			}
			Item = root;
			cout << "Введите значение элемента: ";
			cin >> number;
			AddItem(root, ElementOfCurrIndex, number, index);
			InfoOfList(Item);
			break;
		case(3):
			cout << "Введите индексы элементов списка для обмена: ";
			cin >> index;
			cin >> number;
			if (index < n && number < n) {
				while (Item)
				{
					if (count == index) ElementOfCurrIndex = Item;
					if (count == number) SecondElement = Item;
					count++;
					Item = Item->tail;
				}
				count = 0;
				root = Swap(ElementOfCurrIndex, SecondElement, root);
				Item = root;
				InfoOfList(Item);
			}
			else {
				if (index == number) cout << "Нельзя вводить один и тот же элемент для обмена";
				else cout << "Индексы были введены неправильно";
			}
			break;
		case(4):
			cout << "1) Получение элемента по индексу" << '\n' << "2) Получение элемента по значению" << endl << "Введите число: ";
			cin >> n2;
			switch (n2)
			{
			case(1):
				cout << "Введите индекс элемента: ";
				cin >> index;
				while (Item)
				{
					count++;
					Item = Item->tail;
					if (count == index) {
						cout << "Значение элемента по индексу: " << Item->data << endl;
						count = 0; flag = 1;
						break;
					}
				}
				Item = root;
				if (flag == 0) cout << "Элемент не найден" << endl;
				break;
			case(2):
				cout << "Введите значение элемента: ";
				cin >> number;
				while (Item)
				{
					count++;
					Item = Item->tail;
					if (number == Item->data) {
						cout << "Элемент присутствует в списке на позиции " << count << endl;
						count = 0; flag = 1;
						break;
					}
				}
				Item = root;
				if (flag == 0) cout << "Элемент не найден" << endl;
				break;
			default:
				cout << "Введено неправильное значение";
				break;
			}
			break;
		case(5):
			end = 1;
			break;
		default:
			cout << "Введено неправильное значение";
			break;
		}
		if (FlagOfNumber == 1) {
			cout << "Список пуст" << endl;
			break;
		}
		if (end == 1) break;
	}
}
//задание 4
void Fourth_Question(List* root, List* Item) {
	auto start = steady_clock::now(); auto end = steady_clock::now(); auto result = duration_cast<nanoseconds>(end - start);
	int n1, n2, index, number, count = 0, flag = 0, CountOfItem = 0, FlagOfNumber = 0, Stop = 0, i;
	List* ElementOfCurrIndex = 0, * SecondElement = 0;
	int n;
	cout << "Введите число (количество элементов списка): ";
	cin >> n;
	root = CreateList(n);
	int* arr = new int[n], * New_arr = 0;
	Item = root;
	cout << "Список: " << endl;
	while (Item)
	{
		Item->data = rand() % 100 - 1;
		arr[count] = Item->data;
		cout << Item->data << " ";
		Item = Item->tail;
		count++;
	}
	Item = root;
	count = 0;
	cout << endl;
	CountOfItem = 0; flag = 0; FlagOfNumber = 0;
	cout << "Меню: " << '\n' << "1) Время на удаление элемента списка/массива" << '\n' << "2) Время на добавление элемента списка/массива" << '\n' << "3) Время на получение элемента списка/массива" << endl << "Введите число: ";
	cin >> n1;
	switch (n1)
	{
	case(1):
		cout << "Введите индекс элемента: ";
		cin >> index;
		start = steady_clock::now();
		if (index < n) {
			while (Item)
			{
				if (count == index) {
					ElementOfCurrIndex = Item;
					count = 0;
					break;
				}
				else {
					count++;
					Item = Item->tail;
				}
			}
			Item = root;
			CountOfItem = CountOfElements(Item);
			if (ElementOfCurrIndex == root) root = DelHeadItem(ElementOfCurrIndex, root, CountOfItem);
			else DelItem(ElementOfCurrIndex);
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			Item = root;
			InfoOfList(Item);
			cout << "Время, потраченное на удаление элемента списка: " << result.count() << " наносекунд" << endl;
			start = steady_clock::now();
			count = n - 1;
			int* New_arr = new int[count];
			int i = 0;
			while (i < n)
			{
				if (i < index) {
					New_arr[i] = arr[i];
					i++;
				}
				if (i >= index) {
					New_arr[i - 1] = arr[i];
					i++;
				}
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			cout << "Время, потраченное на удаление элемента массива: " << result.count() << " наносекунд" << endl;
		}
		else {
			cout << "Введен неправильный индекс" << endl;
		}
		break;
	case(2):
		cout << "Введите индекс элемента списка, перед которым нужно добавить новый элемент или (-1), чтобы поставить новый элемент в начало списка: ";
		cin >> index;
		start = steady_clock::now();
		while (Item)
		{
			if (index == -1) {
				ElementOfCurrIndex = Item;
				count = 0;
				break;
			}
			if (count == index) {
				ElementOfCurrIndex = Item;
				count = 0;
				break;
			}
			if (count != index) {
				count++;
				Item = Item->tail;
			}
		}
		Item = root;
		cout << "Введите значение элемента: ";
		cin >> number;
		AddItem(root, ElementOfCurrIndex, number, index);
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		InfoOfList(Item);
		cout << "Время, потраченное на добавление элемента списка: " << result.count() << " наносекунд" << endl;
		start = steady_clock::now();
		count = n + 1;
		New_arr = new int[count];
		i = 0;
		while (i < n)
		{
			if (i < index) {
				New_arr[i] = arr[i];
				i++;
			}
			if (i = index) {
				New_arr[i] = number;
				i++;
			}
			if (i > index) {
				New_arr[i] = arr[i - 1];
				i++;
			}
		}
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		cout << "Время, потраченное на добавление элемента массива: " << result.count() << " наносекунд" << endl;
		break;
	case(3):
		cout << "1) Получение элемента по индексу" << '\n' << "2) Получение элемента по значению" << endl << "Введите число: ";
		cin >> n2;
		switch (n2)
		{
		case(1):
			cout << "Введите индекс элемента: ";
			cin >> index;
			start = steady_clock::now();
			while (Item)
			{
				count++;
				Item = Item->tail;
				if (count == index) {
					count = 0; flag = 1;
					break;
				}
			}
			end = steady_clock::now();
			if (flag == 0) cout << "Элемент не найден" << endl;
			else cout << "Значение элемента по индексу: " << Item->data << endl;
			result = duration_cast<nanoseconds>(end - start);
			cout << "Время, потраченное на поиск элемента списка: " << result.count() << " наносекунд" << endl;
			start = steady_clock::now();
			for (int j = 0; j < n; j++) {
				if (j == index) break;
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			cout << "Время, потраченное на поиск элемента массива: " << result.count() << " наносекунд" << endl;
			break;
		case(2):
			cout << "Введите значение элемента: ";
			cin >> number;
			start = steady_clock::now();
			while (Item)
			{
				count++;
				Item = Item->tail;
				if (number == Item->data) {
					count = 0; flag = 1;
					break;
				}
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			Item = root;
			if (flag == 0) cout << "Элемент не найден" << endl;
			else cout << "Элемент присутствует в списке на позиции " << count << endl;
			cout << "Время, потраченное на поиск элемента списка: " << result.count() << " наносекунд" << endl;
			start = steady_clock::now();
			for (int j = 0; j < n; j++) {
				if (arr[j] == number) break;
			}
			end = steady_clock::now();
			result = duration_cast<nanoseconds>(end - start);
			cout << "Время, потраченное на поиск элемента массива: " << result.count() << " наносекунд" << endl;
			break;
		default:
			cout << "Введено неправильное значение"<< endl;
			break;
		}
		break;
	default:
		cout << "Введено неправильное значение" << endl;
		break;
	}
	delete[] arr, New_arr;
	Item = root;
	List* elem = 0;
	while (Item){
		elem = Item;
		Item = Item->tail;
		delete elem;
	}
}

int main() {
	int c, count = 0, size = 0;
	List* root = 0, * Element = 0;
	srand(time(0));
	setlocale(0, "");
	while (true) {
		cout << "1)Ввод по количеству(задание 1, пункт а)" << '\n' << "2)Ввод по строке чисел(задание 1, пункт б)" << '\n' << "3)Создание двусвязного списка и массива на время" << '\n' << "4)Удаление элемента/Добавление элемента/Обмен элементов/Получение элемента" << '\n' << "5)Удаление элемента/Добавление элемента/Обмен элементов/Получение элемента на время" << endl;
		cout << "Введите число: ";
		cin >> c;
		switch (c) {
		case(1):
			CreateDoubleLineList_A(root, Element);
			break;
		case(2):
			CreateDoubleLineList_B(root, Element);
			break;
		case(3):
			TimeToCreateList(root);
			break;
		case(4):
			Third_Question(root, Element);
			break;
		case(5):
			Fourth_Question(root, Element);
			break;
		default:
			cout << "Введено неправильное значение" << endl;
			break;
		}
	}
}