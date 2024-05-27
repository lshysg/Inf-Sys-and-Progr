//Lab2.8 В-5
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Структура, представляющая информацию о мониторе
struct Monitor {
    string brand; // Фирма
    double size;  // Размер по диагонали
    double price; // Стоимость
};

int main() {
    setlocale(0, "Rus");
    // Создаем вектор для хранения информации о мониторах
    vector<Monitor> monitors = {
        {"Samsung", 21.5, 15000},
        {"LG", 24, 18000},
        {"Acer", 19, 12000},
        {"Dell", 27, 25000},
        {"Asus", 23.8, 20000}
    };

    // Записываем информацию о мониторах в бинарный файл
    ofstream outputFile("monitors.bin", ios::binary);
    for (const auto& monitor : monitors) {
        outputFile.write(reinterpret_cast<const char*>(&monitor), sizeof(Monitor));
    }
    outputFile.close();

    // Читаем информацию о мониторах из бинарного файла
    ifstream inputFile("monitors.bin", ios::binary);
    if (!inputFile.is_open()) {
        cout << "Не удалось открыть бинарный файл\n";
        return 1;
    }

    vector<Monitor> loadedMonitors;
    Monitor loadedMonitor;

    // Считываем информацию о мониторах из бинарного файла
    while (inputFile.read(reinterpret_cast<char*>(&loadedMonitor), sizeof(Monitor))) {
        loadedMonitors.push_back(loadedMonitor);
    }
    inputFile.close();

    // Вычисляем среднюю цену мониторов размером не менее 19 дюймов
    double totalPrice = 0;
    int count = 0;
    for (const auto& m : loadedMonitors) {
        if (m.size >= 19) {
            totalPrice += m.price;
            count++;
        }
    }

    // Печатаем информацию о мониторах размером не менее 19 дюймов
    if (count > 0) {
        double averagePrice = totalPrice / count;
        cout << "Средняя цена мониторов размером не менее 19 дюймов: " << averagePrice << " рублей\n";
        cout << "Информация о мониторах размером не менее 19 дюймов:\n";
        for (const auto& m : loadedMonitors) {
            if (m.size >= 19) {
                cout << "Фирма: " << m.brand << ", Диагональ: " << m.size << " дюймов, Цена: " << m.price << " рублей\n";
            }
        }
    }
    else {
        cout << "Нет мониторов размером не менее 19 дюймов\n";
    }

    return 0;
}


