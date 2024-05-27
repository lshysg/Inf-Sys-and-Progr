//Lab2_1 В-5
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(0, "Rus");
    ifstream inputFile("a.txt"); // Открытие файла для чтения

    if (!inputFile.is_open()) { // Проверка на успешное открытие файла
        cout << "Не удалось открыть файл a.txt\n";
        return 1;
    }

    double number;
    int zeroCount = 0;
    double positiveSum = 0.0;

    while (inputFile >> number) { // Чтение чисел из файла
        if (number == 0.0) {
            zeroCount++; // Увеличение счетчика нулевых элементов
        }
        else if (number > 0.0) {
            positiveSum += number; // Добавление положительного элемента к сумме
        }
    }

    inputFile.close(); // Закрытие файла

    cout << "Количество нулевых элементов: " << zeroCount << endl;
    cout << "Сумма положительных элементов: " << positiveSum << endl;

    return 0;
}
