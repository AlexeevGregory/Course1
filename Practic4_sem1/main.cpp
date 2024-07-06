#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
string FileReading();
string FileEditing();
string FileSorting();
string FileChange();
void Searching(string buffer);

int main()
{
	setlocale(0, "");
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
	char LetterReplace[2] = { ' ', '\0' }, PunctMarks[] = {',',';',':','?','!','"','[',']','{','}','\0'}, SpecialMark[2] = {'.', '\0'};
	int j, n, CountOfPoint;
	int flag = 0;
	cout << "Какой способ чтения данных вам нужен?" << endl << "1)Чтение с клавиатуры." << endl << "2)Чтение с файла." << endl << "Введите число: ";
	cin >> n;
	if (n == 1)
		getline(cin, buffer);
	else
		if (n == 2)
			buffer = FileReading();
		else
			cout << "Ошибка: введено неправильное значение";
	system("cls");
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
		/*else
		{
			CountOfPoint = 0;
			for (int j = i; (buffer[j] != ' ') or (j < buffer.length()); ++j)
			{
				if (buffer[j] == SpecialMark[0])
					CountOfPoint++;
			}
			if (CountOfPoint < 3)
			{
				buffer.erase(i, 1);
			}
			else
			{
				while (CountOfPoint != 3)
				{
					buffer.erase(i, 1);
					CountOfPoint--;
				}
			}
		}*/
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
		buffer.erase(buffer.rfind(' '), line.length()+1);
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
	string buffer = FileEditing();
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
	cout << "Строка:" << endl << buffer << endl;
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
					if(underline.rfind(LineOfComparison[LineOfComparison.length() - 1]) != (-1))
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
	cout <<"Количество найденных подстрок в строке: " << CountOfLines << endl;
	CountOfLines = 0;
	cout << "Линейный поиск подстроки" << endl;
	for (int i = 0; i < buffer.length() - underline.length(); ++i)
	{
		count = 0;
		for (int n = 0; n < underline.length(); ++n)
		{
			if (underline[n] == buffer[n+i])
				count++;
		}
		if (count == underline.length())
			CountOfLines++;
	}
	cout << "Количество найденных подстрок в строке линейным поиском: " << CountOfLines;
}