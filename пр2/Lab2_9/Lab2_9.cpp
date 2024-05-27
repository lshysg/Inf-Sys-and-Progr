//Lab2.9 В-5
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void writeToFile(const char* filename, const char* data, int length) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    file.write(data, length);
    file.close();
}

void readAndPrintFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return;
    }

    char c;
    cout << "Содержимое файла:" << endl;
    while (file.get(c)) {
        cout << c;
    }
    cout << endl;

    file.close();
}

void convertToUppercase(const char* inputFilename, const char* outputFilename) {
    ifstream inputFile(inputFilename, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия входного файла для чтения!" << endl;
        return;
    }

    ofstream outputFile(outputFilename, ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия выходного файла для записи!" << endl;
        inputFile.close();
        return;
    }

    char c;
    while (inputFile.get(c)) {
        if (islower(c)) {
            c = toupper(c);
        }
        outputFile.put(c);
    }

    inputFile.close();
    outputFile.close();

    cout << "Преобразование в прописные буквы завершено." << endl;
}

int main() {
    setlocale(0, "Rus");
    const char* filename = "data.bin";
    const char* convertedFilename = "data_uppercase.bin";

    // Запись русского алфавита в файл
    const char* russianAlphabet = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
    int length = strlen(russianAlphabet);
    writeToFile(filename, russianAlphabet, length);

    // Чтение и вывод содержимого файла
    readAndPrintFile(filename);

    // Преобразование содержимого файла в прописные буквы
    convertToUppercase(filename, convertedFilename);

    // Чтение и вывод содержимого преобразованного файла
    readAndPrintFile(convertedFilename);

    return 0;
}

