//Lab2.2 В-5
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(0, "Rus");
    ifstream file1("a1.txt"); // Открытие первого файла
    ifstream file2("a2.txt"); // Открытие второго файла

    if (!file1.is_open() || !file2.is_open()) { // Проверка на успешное открытие файлов
        cout << "Не удалось открыть один из файлов\n";
        return 1;
    }

    double number1, number2;
    double negativeProduct = 1.0; // Начальное значение произведения

    while (file1 >> number1 && file2 >> number2) { // Чтение чисел из обоих файлов
        if (number1 < 0 && number2 < 0) { // Если оба числа отрицательные
            negativeProduct *= number1 * number2; // Умножаем их и добавляем к произведению
        }
    }

    file1.close(); // Закрытие первого файла
    file2.close(); // Закрытие второго файла

    cout << "Произведение отрицательных элементов двух файлов: " << negativeProduct << endl;

    return 0;
}
