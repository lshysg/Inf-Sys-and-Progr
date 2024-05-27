//Lab2.3 В-5
#include <iostream>
#include <fstream>
#include <string> // Для функции tolower

using namespace std;

int main() {

    setlocale(0, "Rus");
    ifstream inputFile("input.txt"); // Открытие исходного файла для чтения
    ofstream outputFile("output.txt"); // Создание нового файла для записи

    if (!inputFile.is_open() || !outputFile.is_open()) { // Проверка на успешное открытие файлов
        cout << "Не удалось открыть файлы\n";
        return 1;
    }

    string line;

    while (getline(inputFile, line)) { // Чтение строк из исходного файла
        for (char& c : line) { // Перебор всех символов в строке
            if (isupper(c)) { // Если символ - заглавная буква
                c = tolower(c); // Заменяем его на строчную
            }
        }
        outputFile << line << endl; // Записываем измененную строку в новый файл
    }

    inputFile.close(); // Закрытие исходного файла
    outputFile.close(); // Закрытие нового файла

    cout << "Процесс завершен. Результат записан в файл output.txt\n";

    return 0;
}

