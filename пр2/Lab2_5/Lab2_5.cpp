//Lab2.5 В-5
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Patient {
    string surname;
    string name;
    string patronymic;
    char gender;
    string nationality;
    int height;
    int weight;
    string birthDate;
    string phoneNumber;
    string address;
    int hospitalNumber;
    string department;
    int medicalCardNumber;
    string diagnosis;
    string bloodGroup;
};

int main() {
    setlocale(0, "Rus");
    system("chcp 1251");
    ifstream inputFile("patients.txt");
    ofstream outputFile("patients_department_18.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Не удалось открыть файлы\n";
        return 1;
    }

    vector<Patient> patients;

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;
        Patient patient;
        bool foundDepartment = false;
        while (getline(ss, token, ';')) {
            if (!foundDepartment) {
                patient.surname = token;
                foundDepartment = true;
            }
            else {
                patient.department = token;
                break;
            }
        }
        if (patient.department == " 18") { // Проверяем отделение
            patients.push_back(patient);
        }
    }

    for (const auto& patient : patients) {
        outputFile << "Пациент:\n"
            << patient.surname << ";" << patient.name << ";" << patient.patronymic << ";"
            << patient.gender << ";" << patient.nationality << ";" << patient.height << ";" << patient.weight << ";"
            << patient.birthDate << ";" << patient.phoneNumber << ";" << patient.address << ";" << patient.hospitalNumber << ";"
            << patient.department << ";" << patient.medicalCardNumber << ";" << patient.diagnosis << ";" << patient.bloodGroup << "\n";
    }

    inputFile.close();
    outputFile.close();

    cout << "Результаты сохранены в файле patients_department_18.txt\n";

    return 0;
}



