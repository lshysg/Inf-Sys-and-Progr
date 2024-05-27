//Lab2.10 В-5
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Структура для хранения информации о покупках
struct Purchase {
    char name[50]; // Фамилия и инициалы покупателя
    char date[20]; // Дата покупки
    float totalCost; // Общая стоимость приобретенного товара
    float discountPercent; // Начальный процент скидки на последующие приобретаемые товары
};

// Функция для записи структуры в бинарный файл
void writeToFile(const char* filename, Purchase* data, int count) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    file.write(reinterpret_cast<char*>(data), count * sizeof(Purchase));
    file.close();
}

// Функция для чтения и печати содержимого бинарного файла
void readAndPrintFile(const char* filename, int count) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return;
    }

    Purchase purchase;
    cout << "Содержимое файла:" << endl;
    for (int i = 0; i < count; ++i) {
        file.read(reinterpret_cast<char*>(&purchase), sizeof(Purchase));
        cout << "Покупатель: " << purchase.name << endl;
        cout << "Дата покупки: " << purchase.date << endl;
        cout << "Общая стоимость: " << purchase.totalCost << " руб." << endl;
        cout << "Процент скидки: " << purchase.discountPercent << "%" << endl;
        cout << "----------------------------------" << endl;
    }

    file.close();
}

// Функция для увеличения процента скидки на 5%, если общая стоимость превышает 5000 руб.
void increaseDiscount(const char* filename, int count) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для модификации!" << endl;
        return;
    }

    Purchase purchase;
    for (int i = 0; i < count; ++i) {
        file.seekg(i * sizeof(Purchase));
        file.read(reinterpret_cast<char*>(&purchase), sizeof(Purchase));

        if (purchase.totalCost > 5000) {
            purchase.discountPercent += 5.0f;
            file.seekp(i * sizeof(Purchase));
            file.write(reinterpret_cast<char*>(&purchase), sizeof(Purchase));
        }
    }

    file.close();

    cout << "Модификация файла завершена." << endl;
}

int main() {
    setlocale(0, "Rus");
    const char* filename = "purchases.bin";
    const int numPurchases = 3;

    // Создание данных о покупках
    Purchase purchases[numPurchases] = {
        {"Иванов И.И.", "01.05.2024", 3000.0f, 5.0f},
        {"Петров П.П.", "02.05.2024", 6000.0f, 10.0f},
        {"Сидоров С.С.", "03.05.2024", 4500.0f, 7.0f}
    };

    // Запись данных в бинарный файл
    writeToFile(filename, purchases, numPurchases);

    // Чтение и печать содержимого файла
    readAndPrintFile(filename, numPurchases);

    // Увеличение процента скидки при необходимости
    increaseDiscount(filename, numPurchases);

    // Повторное чтение и печать содержимого файла после модификации
    readAndPrintFile(filename, numPurchases);

    return 0;
}
