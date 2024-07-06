#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;

struct Volleyball_person {
	string Familia = "", Name= "", Otchestvo = "";
	char sex = 0;
	int age = 0;
	int size_cloth = 0;
	int sport_category = 0;
	int course = 0;
};
int CountOfStudents() {
	ifstream File("students.txt");
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
		n = count / 8;
		return n;
	}
	else return 0;
}
/*void NewStudent(Volleyball_person student) {
	cout << "Фамилия: ";
	cin >> student.Familia;
	cout << "Имя: ";
	cin >> student.Name;
	cout << "Отчество: ";
	cin >> student.Otchestvo;
	cout << "Пол (F/M): ";
	cin >> student.sex;
	cout << "Возраст: ";
	cin >> student.age;
	cout << "Id: ";
	cin >> student.size_cloth;
	cout << "Успеваемость(8 оценок): ";
	cin >> student.sport_category;
	cout << "Успеваемость(8 оценок): ";
	cin >> student.course;
	ofstream File;
	File.open("students.txt", ios::app);
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		File << student.Familia << '\n' << student.Name << '\n' << student.Otchestvo << '\n' << student.age << '\n';
		File << student.size_cloth << '\n' << student.sport_category << '\n' << student.course;
		File << '\n';
		File.close();
	}
}*/
void InfoOfAllStudents(int size) {
	Volleyball_person* student = new Volleyball_person[size];
	ifstream File("students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		if (size == 0) cout << "Список пуст" << endl;
		else {
			int temp = 0;
			for (int i = 0; i < size; i++) {
				File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].sex >> student[i].age >> student[i].size_cloth >> student[i].sport_category >> student[i].course;
				if (student[i].sport_category != 0) {
					cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Пол  " << student[i].sex << '\n' << "Возраст " << student[i].age << '\n' << "Размер одежды " << student[i].size_cloth << '\n' << "Разряд " << student[i].sport_category << '\n' << "Номер курса " << student[i].course;
					cout << '\n' << '\n';
					temp++;
				}
			}
			File.close();
			if (temp == 0) cout << "Студенты не найдены" << endl;
		}
	}
	delete[] student;
}
void InfoOfAllStudents_F(int size) {
	Volleyball_person* student = new Volleyball_person[size];
	ifstream File("students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		if (size == 0) cout << "Список пуст" << endl;
		else {
			int temp = 0;
			for (int i = 0; i < size; i++) {
				File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].sex >> student[i].age >> student[i].size_cloth >> student[i].sport_category >> student[i].course;
				if (student[i].sex == 'F') {
					cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Пол " << student[i].sex << '\n' << "Возраст " << student[i].age << '\n' << "Размер одежды " << student[i].size_cloth << '\n' << "Разряд " << student[i].sport_category << '\n' << "Номер курса " << student[i].course;
					cout << endl;
					temp++;
				}
			}
			File.close();
			if (temp == 0) cout << "Студенты не найдены" << endl;
		}
	}
	delete[] student;
}
void AllStudentsOfCourse(int size) {
	int course;
	cout << "Введите число(номер курса): ";
	cin >> course;
	Volleyball_person* student = new Volleyball_person[size];
	ifstream File("students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		if (size == 0) cout << "Список пуст" << endl;
		else {
			int temp = 0;
			for (int i = 0; i < size; i++) {
				File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].sex >> student[i].age >> student[i].size_cloth >> student[i].sport_category >> student[i].course;
				if (student[i].course == course) {
					cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Пол " << student[i].sex << '\n' << "Возраст " << student[i].age << '\n' << "Размер одежды " << student[i].size_cloth << '\n' << "Разряд " << student[i].sport_category << '\n' << "Номер курса " << student[i].course;
					cout << endl;
					temp++;
				}
			}
			File.close();
			if (temp == 0) cout << "Студенты не найдены" << endl;
		}
	}
	delete[] student;
}
void AllStudentsOfSizeOfCloth(int size) {
	int size_cloth;
	cout << "Введите число(размер одежды): ";
	cin >> size_cloth;
	Volleyball_person* student = new Volleyball_person[size];
	ifstream File("students.txt");
	if (!File.is_open())
		cout << "Ошибка в открытии файла";
	else {
		if (size == 0) cout << "Список пуст" << endl;
		else {
			int temp = 0;
			for (int i = 0; i < size; i++) {
				File >> student[i].Familia >> student[i].Name >> student[i].Otchestvo >> student[i].sex >>  student[i].age >> student[i].size_cloth >> student[i].sport_category >> student[i].course;
				if (student[i].size_cloth > size_cloth && student[i].sex == 'M') {
					cout << "ФИО  " << student[i].Familia << " " << student[i].Name << " " << student[i].Otchestvo << '\n' << "Возраст " << "Пол " << student[i].sex << '\n' << student[i].age << '\n' << "Размер одежды " << student[i].size_cloth << '\n' << "Разряд " << student[i].sport_category << '\n' << "Номер курса " << student[i].course;
					cout << endl;
					temp++;
				}
			}
			File.close();
			if (temp == 0) cout << "Студенты не найдены" << endl;
		}
	}
	delete[] student;
}
int main() {
	setlocale(0, "");
	Volleyball_person student;
	int n, size = CountOfStudents();
	while (true)
	{
		cout << "Меню:" << '\n' << "1)Информация о студентах, имеющих разряд" << '\n' << "2)Информация о сборной женской команды по волеуболу" << '\n' << "3)Информация о студентах курса" << '\n' << "4)Информация о студентах, у которых размер одежды больше определенного числа";
		cout << '\n' << "Введите число(1-4): ";
		cin >> n;
		switch (n)
		{
		case(1):
			InfoOfAllStudents(size);
			break;
		case(2):
			InfoOfAllStudents_F(size);
			break;
		case(3):
			AllStudentsOfCourse(size);
			break;
		case(4):
			AllStudentsOfSizeOfCloth(size);
			break;
		default:
			cout << "Введено неправильное значение";
			break;
		}
	}
}