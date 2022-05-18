// Файловая система
#include <iostream>
#include <string>
#include <fstream> // file stream (файловый поток). Библиотека, позволяющая работать с классами, взаимодействующими с файлами.
// Классы - описание групп объектов, которые содержат в себе поля и методы.
using namespace std;

// Классы библиотеки fstream
// ofstream - output file stream
// ifstream - input file stream
// fstream - file stream

/*
	Ошибки открфтия фалов для записи:
	1. Неверный путь к файлу;
	2. Нет доступа для открытия файла;
	3. Файл открыт.

	Ошибки открытия файлов для чтения:
	1. Неверный путь к файлу;
	2. Нет доступа для открытия файла;
	3. Файла не существует.

	Ошибки при удалении файла:
	1. Неверный путь к файлу;
	2. Нет доступа для редактирования файла;
	3. Файла не существует;
	4. Файл открыт.
*/

// Задача 1
bool statistic(string& word);

// Задача 2
void printFile();
void clear();

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	string path = "file.txt"; // путь к файлу

	// Запись в файл - ofstream
	// Конструктор класса - метод, который выполняется, когда создаётся объект класса.
	ofstream out/*(path)*/; // Первый способ открытия файла
	// Объект ofstream создаёт файл даже если его нет.
	out.open(path, ios::app); // Второй способ открытия файла с возможностью добавления записи без удаления старых записей.
	out.open(path, ios::out); // Способ открытия файла с перезаписью старых записей.

	if (out.is_open()) {
		cout << "Файл открыт для записи.\n";
		string str;
		cout << "Введите строку:\n";
		getline(cin, str);
		out << str + "\n"; // Помещение строки str в файл
		cout << "Запись помещена в файл.\n";
		//out << "Bye!\n";
	}
	else
		cout << "Ошибка открытия файла!\n";


	out.close(); // Закрываем файл

	// Чтение из файла - ifstream
	ifstream in /*(path)*/;
	in.open(path); // Открытие существующего файла для чтения

	if (in.is_open()) {
		cout << "Файл открыт для чтения.\n";
		string fileStr;

		// Посимвольное считывание
		char sym;
		while (in.get(sym))
			fileStr += sym;
		cout << fileStr;

		// Пословное считывание
		while (!in.eof()) { // End of file
			string str;
			in >> str;
			if (str != "") // Чтобы в конце отступ был один раз, а не два раза
				fileStr += str + "\n";
		}
		cout << fileStr;

		// Построчное считывание
		string tmp;
		while (getline(in, tmp))
			fileStr += tmp + "\n";
		cout << fileStr;
	}
	else
		cout << "Ошибка открытия файла.\n";


	in.close(); // Закрываем файл

	if (!remove("file.txt")) // Удаляет файл
		cout << "Файл удалён.\n";
	else
		cout << "Ошибка удаления файла.\n";


	// Задача 1
	cout << "Задача 1.\n";
	int answer;
	do {
		cout << "Выберите действие:\n";
		cout << "1. Ввод слова;\n";
		cout << "2. Вывод содердимого файла;\n";
		cout << "3. Очистка файла;\n";
		cout << "4. Завершение работы.\n";
		cout << "Ввод -> ";
		cin >> answer;
		string str;
		switch (answer) {
		case 1:
			cout << "Введите слово:\n";
			cin >> str;
			cin.ignore();
			if (statistic(str))
				cout << "Слово записано.\n";
			else
				cout << "Ошибка записи.\n";
			break;
		case 2:
			cout << "Содержимое файла:\n";
			printFile();
			break;
		case 3:
			clear();
			cout << "Файл очищен.\n";
			break;
		case 4:
			cout << "Завершение работы...\n";
			break;
		default:
			cout << "Ошибка ввода.\n";
		}
		system("pause");
		system("cls");
	} while (answer != 4);
	cout << "Программа завершена.\n";

	return 0;
}
// Задача 1
// Запись слова в файл
bool statistic(string& word) {
	ofstream out;
	out.open("words.txt", ios::app);
	if (out.is_open()) {
		out << word + " " << word.length() << "\n";
		out.close();
		return true;
	}
	out.close();
	return false;
}

// Задача 2
// Вывод содержимого файла
void printFile() {
	ifstream in;
	in.open("words.txt");
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			cout << sym;
	}
	else
		cout << "Ошибка открытия файла.\n";

}
// Очищение файла
void clear() {
	ofstream out;
	out.open("words.txt");
	out.close();
}