#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


struct InfoOfStudent {
	string Name = "", Familia = "", Otchestvo = "";
	int group = 0;
	int index = 0;
	char sex = 0;
	int grades[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
};
int CountOfStudents() {
	ifstream File("Students.txt");
	if (File.is_open())
	{
		int count = 0;
		string line;
		while (!File.eof())
		{
			getline(File, line);
			count++;
		}
		File.close();
		int n;
		n = count / 7;
		return n;
	}
	else return 0;
}
// 1 задание
void NewStudent(InfoOfStudent student) {
	cout << "Фамилия: ";
	cin >> student.Familia;
	cout << "Имя: ";
	cin >> student.Name;
	cout << "Отчество: ";
	cin >> student.Otchestvo;
	cout << "Номер группы: ";
	cin >> student.group;
	cout << "Id: ";
	cin >> student.index;
	cout << "Пол (F/M): ";
	cin >> student.sex;
	cout << "Успеваемость(8 оценок): ";
	for (int i = 0; i < 8; i++) cin >> student.grades[i];
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (student.grades[i] == 2) count++;
	}
	if (count == 0) {
		ofstream File;
		File.open("Students.txt", ios::app);
		if (!File.is_open())
			cout << "Ошибка в открытии файла";
		else {
			File << student.Familia << '\n' << student.Name << '\n' << student.Otchestvo << '\n' << student.group << '\n';
			File << student.index << '\n' << student.sex << '\n';
			for (int i = 0; i < 8; i++) {
				File << student.grades[i] << " ";
			}
			File << '\n';
			File.close();
			cout << "Данные успешно сохранены в файле";
		}
	}
	else cout << "Информация об этом студенте не может быть сохранена по причине наличии неудовлетворительной оценки";

}
//2 задание
void EdittingInfoOfStudent(int size) {
	int n;
	fstream File("Students.txt");
	InfoOfStudent* student = new InfoOfStudent[size];
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		if (size == 0) cout << "Список пуст" << endl;
		else {
			for (int i = 0; i < size; i++) {
				File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].group >> student[i].index >> student[i].sex;
				for (int j = 0; j < 8; j++) {
					File >> student[i].grades[j];
				}
			}
		}
	}
	File.close();
	cout << "Введите id студента, которого хотите изменить: "; cin >> n;
	File.open("Students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		if (size == 0) cout << "Список пуст" << endl;
		else {
			for (int i = 0; i < size; i++) {
				if (student[i].index == n) {
					cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Группа " << student[i].group << '\n' << "id  " << student[i].index << '\n' << "Пол  " << student[i].sex << '\n' << "Успеваемость  ";
					for (int j = 0; j < 8; j++) {
						cout << student[i].grades[j] << " ";
					}
					cout << '\n' << '\n';
					int m;
					string NewName, NewFamilia, NewOtchestvo;
					int NewGroup, NewIndex, NewGrades[8];
					char NewSex;
					cout << "Меню:" << '\n' << "1.Изменение Фамилии" << '\n' << "2.Изменение Имени" << '\n' << "3.Изменение Отчества" << '\n' << "4.Изменение номера группы" << '\n' << "5.Изменение id" << '\n' << "6.Изменение пола" << '\n' << "7.Изменение успеваемости" << '\n';
					cout << "Введите число для редактирования определенной информации студента: ";
					cin >> m;
					switch (m)
					{
					case(1):
						cout << "Введите новые данные(Фамилия): ";
						cin >> NewFamilia;
						student[i].Familia = NewFamilia;
						break;
					case(2):
						cout << "Введите новые данные(Имя): ";
						cin >> NewName;
						student[i].Name = NewName;
						break;
					case(3):
						cout << "Введите новые данные(Отчество): ";
						cin >> NewOtchestvo;
						student[i].Otchestvo = NewOtchestvo;
						break;
					case(4):
						cout << "Введите новые данные(Номер группы): ";
						cin >> NewGroup;
						student[i].group = NewGroup;
						break;
					case(5):
						cout << "Введите новые данные(id): ";
						cin >> NewIndex;
						student[i].index = NewIndex;
						break;
					case(6):
						cout << "Введите новые данные(Пол): ";
						cin >> NewSex;
						student[i].sex = NewSex;
						break;
					case(7):
						cout << "Введите новые данные(Успеваемость): ";
						for (int j = 0; j < 8; j++) {
							cin >> NewGrades[j];
							student[i].grades[j] = NewGrades[j];
						}
						break;
					default:
						cout << "Неверно введено число" << endl;
						break;
					}
				}
				File << student[i].Familia << '\n' << student[i].Name << '\n' << student[i].Otchestvo << '\n' << student[i].group << '\n';
				File << student[i].index << '\n' << student[i].sex << '\n';
				for (int j = 0; j < 8; j++) {
					File << student[i].grades[j] << " ";
				}
				File << '\n';
			}
			File.close();
			cout << "Данные успешно сохранены в файле";
		}
	}
	delete[] student;
}
//3 задание
void InfoOfAllStudents() {
	ifstream File("Students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		int count;
		count = CountOfStudents();
		if (count == 0)
			cout << "Файл пуст";
		else {
			string line;
			while (!File.eof()) {
				getline(File, line);
				cout << line << '\n';
			}
		}
		File.close();
	}
}
//4 задание
void GroupOfStudents(int size) {
	int n;
	cout << "Введите номер группы: ";
	cin >> n;
	InfoOfStudent* student = new InfoOfStudent[size];
	ifstream File("Students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		if (size == 0) cout << "Список пуст" << endl;
		else {
			int temp = 0;
			for (int i = 0; i < size; i++) {
				File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].group >> student[i].index >> student[i].sex;
				for (int j = 0; j < 8; j++) {
					File >> student[i].grades[j];
				}
				if (student[i].group == n) {
					cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Группа " << student[i].group << '\n' << "id  " << student[i].index << '\n' << "Пол  " << student[i].sex << '\n' << "Успеваемость  ";
					for (int j = 0; j < 8; j++) {
						cout << student[i].grades[j] << " ";
					}
					cout << endl;
					temp++;
				}
			}
			File.close();
			if (temp == 0) cout << "Группа не найдена" << endl;
		}
	}
	delete[] student;
}
//5 задание
void TopOfGrades(int size) {
	double* p = new double[size], count = 0;
	int* MassOfIndex = new int[size];
	InfoOfStudent* student = new InfoOfStudent[size];
	ifstream File("Students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		if (size == 0) cout << "Список пуст" << endl;
		else {
			int temp = 0;
			for (int i = 0; i < size; i++) {
				File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].group >> student[i].index >> student[i].sex;
				for (int j = 0; j < 8; j++) {
					File >> student[i].grades[j];
					count += student[i].grades[j];
				}
				temp++;
				count /= 8;
				p[i] = count; count = 0; MassOfIndex[i] = student[i].index;
			}
			File.close();
			if (temp == 0) cout << "Группа не найдена" << endl;
		}
	}
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (p[j] < p[j + 1]) { swap(p[j], p[j + 1]); swap(MassOfIndex[j], MassOfIndex[j + 1]); }
		}
		for (int j = size - 1; j >= 1; j--) {
			if (p[j] > p[j - 1]) { swap(p[j], p[j - 1]); swap(MassOfIndex[j], MassOfIndex[j - 1]); }
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (MassOfIndex[i] == student[j].index) {
				cout << "ФИО  " << student[j].Familia << " " << student[j].Name << " " << student[j].Otchestvo << '\n' << "Группа " << student[j].group << '\n' << "id  " << student[j].index << '\n' << "Пол  " << student[j].sex << '\n' << "Успеваемость  ";
				for (int k = 0; k < 8; k++) cout << student[j].grades[k] << " ";
				cout << endl;
			}
		}
	}

	delete[] student; delete[] p; delete[] MassOfIndex;
}
//6 задание
void SexOfStudents(int size) {
	int M = 0, F = 0;
	InfoOfStudent* student = new InfoOfStudent[size];
	ifstream File("Students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		if (size == 0) cout << "Список пуст" << endl;
		else {
			int temp = 0;
			for (int i = 0; i < size; i++) {
				File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].group >> student[i].index >> student[i].sex;
				for (int j = 0; j < 8; j++) {
					File >> student[i].grades[j];
				}
				if (student[i].sex == 'M') {
					M++;
					temp++;
				}
				else { F++; temp++; }
			}
			File.close();
			if (temp == 0) cout << "Список пуст" << endl;
		}
		cout << M << " - количество студентов мужского пола" << '\n' << F << " - количество студентов женского пола";
	}
	delete[] student;
}
//7 задание
void InfoOfGrades(int size) {
	int grade_three = 0, grade_four = 0;
	InfoOfStudent* student = new InfoOfStudent[size];
	ifstream File("Students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		int size = CountOfStudents();
		if (size == 0) cout << "Список пуст" << endl;
		else {
			int temp = 0;
			int n;
			cout << "1) Студенты, не получающие стипендию" << '\n' << "2) Студенты, учащиеся на <хорошо>" << '\n' << "3) Студенты, учащиеся на <отлично>" << '\n';
			cout << "Введите число: ";
			cin >> n;
			switch (n)
			{
			case(1):
				for (int i = 0; i < size; i++) {
					File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].group >> student[i].index >> student[i].sex;
					for (int j = 0; j < 8; j++) {
						File >> student[i].grades[j];
						if (student[i].grades[j] == 3) grade_three++;
						if (student[i].grades[j] == 4) grade_four++;
					}
					if (grade_three != 0) {
						cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Группа " << student[i].group << '\n' << "id  " << student[i].index << '\n' << "Пол  " << student[i].sex << '\n' << "Успеваемость  ";
						for (int k = 0; k < 8; k++) cout << student[i].grades[k] << " ";
					}
					cout << endl;
					temp++, grade_three = 0, grade_four = 0;
				}
				break;
			case(2):
				for (int i = 0; i < size; i++) {
					File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].group >> student[i].index >> student[i].sex;
					for (int j = 0; j < 8; j++) {
						File >> student[i].grades[j];
						if (student[i].grades[j] == 3) grade_three++;
						if (student[i].grades[j] == 4) grade_four++;
					}
					if (grade_three == 0 && grade_four != 0) {
						cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Группа " << student[i].group << '\n' << "id  " << student[i].index << '\n' << "Пол  " << student[i].sex << '\n' << "Успеваемость  ";
						for (int k = 0; k < 8; k++) cout << student[i].grades[k] << " ";
					}
					cout << endl;
					temp++, grade_three = 0, grade_four = 0;
				}
				break;
			case(3):
				for (int i = 0; i < size; i++) {
					File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].group >> student[i].index >> student[i].sex;
					for (int j = 0; j < 8; j++) {
						File >> student[i].grades[j];
						if (student[i].grades[j] == 3) grade_three++;
						if (student[i].grades[j] == 4) grade_four++;
					}
					if (grade_three == 0 && grade_four == 0) {
						cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Группа " << student[i].group << '\n' << "id  " << student[i].index << '\n' << "Пол  " << student[i].sex << '\n' << "Успеваемость  ";
						for (int k = 0; k < 8; k++) cout << student[i].grades[k] << " ";
					}
					cout << endl;
					temp++, grade_three = 0, grade_four = 0;
				}
				break;
			default:
				cout << "Введено число неправильно";
				break;
			}
			File.close();
			if (temp == 0) cout << "Группа не найдена" << endl;
		}
	}
	delete[] student;
}
//8 задание
void IndexOfStudents(int size) {
	int n;
	InfoOfStudent* student = new InfoOfStudent[size];
	cout << "Введите id студента: ";
	cin >> n;
	ifstream File("Students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		int size = CountOfStudents();
		if (size == 0) cout << "Список пуст" << endl;
		else {
			int temp = 0;
			for (int i = 0; i < size; i++) {
				File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].group >> student[i].index >> student[i].sex;
				for (int j = 0; j < 8; j++) {
					File >> student[i].grades[j];
				}
				if (student[i].index == n) {
					cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Группа " << student[i].group << '\n' << "id  " << student[i].index << '\n' << "Пол  " << student[i].sex << '\n' << "Успеваемость  ";
					for (int j = 0; j < 8; j++) {
						cout << student[i].grades[j] << " ";
					}
					temp++;
				}
			}
			File.close();
			if (temp == 0) cout << "id не найден" << endl;
		}
	}
	delete[] student;
}

int main()
{
	struct InfoOfStudent person;
	setlocale(0, "");
	int n, m, size = CountOfStudents();
	while (true) {
		cout << "Меню:"
			<< '\n' << "0) Выход из программы."
			<< '\n' << "1) Создание новой записи о студенте." 
			<< '\n' << "2) Внесение изменений в уже имеющуюся запись." 
			<< '\n' << "3) Вывод всех данных о студентах."
			<< '\n' << "4) Вывод информации обо всех студентах определенной группы." 
			<< '\n' << "5) Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию." 
			<< '\n' << "6) Вывод количества студентов мужского и женского пола." 
			<< '\n' << "7) Вывод данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»." 
			<< '\n' << "8) Вывод данных о студентах, имеющих определенный id в списке." << '\n';
		cout << "Введите число: ";
		cin >> n;
		system("cls");
		switch (n)
		{
		case(1):
			cout << "Введите число: ";
			cin >> m;
			for (int i = 0; i < m; i++) {
				NewStudent(person);
				cin.clear();
				system("cls");
			}
			break;
		case(2):
			EdittingInfoOfStudent(size);
			break;
		case(3):
			cout << " Информация обо всех студентах: " << '\n';
			InfoOfAllStudents();
			break;
		case(4):
			GroupOfStudents(size);
			break;
		case(5):
			TopOfGrades(size);
			break;
		case(6):
			SexOfStudents(size);
			break;
		case(7):
			InfoOfGrades(size);
			break;
		case(8):
			IndexOfStudents(size);
			break;
		case (0):
			exit;
			break;
		default:
			break;
		}
		if (n == 0) {
			cout << "Программа закрыта"; 
			break;
		}
		else cout << '\n' << '\n' << '\n';
	}
}
