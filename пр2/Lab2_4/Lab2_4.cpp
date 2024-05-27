//Lab2.4 В-5
#include <iostream>
#include <fstream>
#include <climits> // Для использования INT_MAX
#include <vector>

using namespace std;

int main() {
    setlocale(0, "Rus");
    ifstream inputFile("numbers.txt"); // Открытие файла с целыми числами для чтения

    if (!inputFile.is_open()) { // Проверка на успешное открытие файла
        cout << "Не удалось открыть файл numbers.txt\n";
        return 1;
    }

    vector<int> numbers; // Вектор для хранения чисел из файла
    int number;
    int minPositive = INT_MAX; // Начальное значение для наименьшего положительного числа

    // Считывание чисел из файла и сохранение в векторе
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close(); // Закрытие файла

    // Поиск наименьшего положительного числа среди чисел на четных позициях
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i % 2 == 0 && numbers[i] > 0 && numbers[i] < minPositive) {
            minPositive = numbers[i];
        }
    }

    if (minPositive == INT_MAX) { // Если не было найдено положительных чисел на четных позициях
        cout << "В файле нет положительных чисел на четных позициях\n";
    }
    else {
        cout << "Наименьший положительный компонент файла среди компонент на четных позициях: " << minPositive << endl;
    }

    return 0;
}

