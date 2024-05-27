// Лабораторная 4, 5 вар
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

// Базовый класс String
class String {
protected:
    char* data;
    int length;

public:
    // Конструктор без параметров
    String() : data(nullptr), length(0) {}

    // Конструктор, принимающий С-строку
    String(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }

    // Конструктор, принимающий символ
    String(char ch) : length(1) {
        data = new char[2];
        data[0] = ch;
        data[1] = '\0';
    }

    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        std::cout << "Вызван конструктор копирования\n";
    }

    // Получение длины строки
    int get_length() const {
        return length;
    }

    // Очистка строки
    void clear() {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    // Деструктор
    virtual ~String() {
        delete[] data;
    }

    // Перегрузка операции присваивания
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }
};

// Производный класс StringIdentifier
class StringIdentifier : public String {
public:
    // Конструктор без параметров
    StringIdentifier() : String() {}

    // Конструктор, принимающий С-строку
    StringIdentifier(const char* str) {
        if (is_valid_identifier(str)) {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }
        else {
            length = 0;
            data = nullptr;
        }
    }

    // Конструктор, принимающий символ
    StringIdentifier(char ch) {
        if (is_valid_identifier_char(ch)) {
            length = 1;
            data = new char[2];
            data[0] = ch;
            data[1] = '\0';
        }
        else {
            length = 0;
            data = nullptr;
        }
    }

    // Конструктор копирования
    StringIdentifier(const StringIdentifier& other) : String(other) {}

    // Перевод всех символов строки в верхний регистр
    void to_upper() {
        for (int i = 0; i < length; ++i) {
            data[i] = std::toupper(data[i]);
        }
    }

    // Перевод всех символов строки в нижний регистр
    void to_lower() {
        for (int i = 0; i < length; ++i) {
            data[i] = std::tolower(data[i]);
        }
    }

    // Поиск первого вхождения символа в строку
    int find_first(char ch) const {
        for (int i = 0; i < length; ++i) {
            if (data[i] == ch) {
                return i;
            }
        }
        return -1;
    }

    // Деструктор
    virtual ~StringIdentifier() {}

    // Перегрузка операции присваивания
    StringIdentifier& operator=(const StringIdentifier& other) {
        if (this != &other) {
            String::operator=(other);
        }
        return *this;
    }

    // Перегрузка операции сложения (конкатенация)
    StringIdentifier operator+(const StringIdentifier& other) const {
        char* concatenated_data = new char[length + other.length + 1];
        std::strcpy(concatenated_data, data);
        std::strcat(concatenated_data, other.data);

        StringIdentifier result(concatenated_data);
        delete[] concatenated_data;
        return result;
    }

    // Перегрузка операции вычитания (удаление всех символов, входящих в другую строку)
    StringIdentifier operator-(const StringIdentifier& other) const {
        std::string result(data);
        for (int i = 0; i < other.length; ++i) {
            result.erase(std::remove(result.begin(), result.end(), other.data[i]), result.end());
        }

        return StringIdentifier(result.c_str());
    }

    // Перегрузка операции сравнения на больше
    bool operator>(const StringIdentifier& other) const {
        return std::strcmp(data, other.data) > 0;
    }

    // Перегрузка операции сравнения на меньше
    bool operator<(const StringIdentifier& other) const {
        return std::strcmp(data, other.data) < 0;
    }

private:
    // Проверка валидности идентификатора
    bool is_valid_identifier(const char* str) const {
        if (!std::isalpha(str[0]) && str[0] != '_') {
            return false;
        }
        for (int i = 1; str[i] != '\0'; ++i) {
            if (!std::isalnum(str[i]) && str[i] != '_') {
                return false;
            }
        }
        return true;
    }

    // Проверка валидности символа идентификатора
    bool is_valid_identifier_char(char ch) const {
        return std::isalnum(ch) || ch == '_';
    }
};

int main() {
    setlocale(0, "Rus");
    const int num_strings = 4;
    String* strings[num_strings];

    for (int i = 0; i < num_strings; ++i) {
        std::cout << "Введите строку: ";
        std::string input;
        std::cin >> input;

        strings[i] = new StringIdentifier(input.c_str());

        std::cout << "Созданная строка: " << input << std::endl;
    }

    for (int i = 0; i < num_strings; ++i) {
        std::cout << "Длина строки " << i << ": " << strings[i]->get_length() << std::endl;
    }

    for (int i = 0; i < num_strings; ++i) {
        delete strings[i];
    }

    return 0;
}
