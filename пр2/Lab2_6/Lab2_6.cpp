//Lab2.6 В-5
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

int main() {
    setlocale(0, "Rus");
    ifstream inputFile("dates.txt");
    ofstream outputFile("min_year.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Не удалось открыть файлы\n";
        return 1;
    }

    vector<Date> dates;
    int minYear = INT_MAX;

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;
        Date date;
        getline(ss, token, ',');
        date.day = stoi(token);
        getline(ss, token, ',');
        date.month = stoi(token);
        getline(ss, token, ',');
        date.year = stoi(token);
        dates.push_back(date);
        if (date.year < minYear) {
            minYear = date.year;
        }
    }

    outputFile << "Год с наименьшим номером: " << minYear << endl;

    inputFile.close();
    outputFile.close();

    cout << "Результат сохранен в файле min_year.txt\n";

    return 0;
}

