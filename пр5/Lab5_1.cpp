//В-5. Реализация шаблонного класса Stack с использованием списка
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

template<typename T>
class Stack {
public:
    Stack() = default;
    ~Stack() = default;

    // Добавление элемента в стек
    void push(const T& value) {
        elements.push_back(value);
    }

    // Удаление верхнего элемента стека
    void pop() {
        if (elements.empty()) {
            throw std::out_of_range("Стек пустой. Невозможно удалить элемент.");
        }
        elements.pop_back();
    }

    // Возвращение верхнего элемента стека
    T& top() {
        if (elements.empty()) {
            throw std::out_of_range("Стек пустой. Невозможно удалить элемент.");
        }
        return elements.back();
    }

    // Проверка, пуст ли стек
    bool empty() const {
        return elements.empty();
    }

    // Возвращение количества элементов в стеке
    std::size_t size() const {
        return elements.size();
    }

private:
    std::list<T> elements;
};

// Пример использования в функции main
int main() {
    setlocale(0, "Rus");
    try {
        // Создание стека для int
        Stack<int> intStack;
        intStack.push(1);
        intStack.push(2);
        std::cout << "Верхний элемент intStack: " << intStack.top() << std::endl;
        intStack.pop();
        std::cout << "Верхний элемент intStack after pop: " << intStack.top() << std::endl;
        intStack.pop();
        // Вызовет исключение, так как стек пуст
        intStack.pop();

    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    try {
        // Создание стека для double
        Stack<double> doubleStack;
        doubleStack.push(3.14);
        doubleStack.push(2.71);
        std::cout << "Верхний элемент doubleStack: " << doubleStack.top() << std::endl;
        doubleStack.pop();
        std::cout << "Верхний элемент doubleStack после удаления: " << doubleStack.top() << std::endl;
        doubleStack.pop();
        // Вызовет исключение, так как стек пуст
        doubleStack.pop();

    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    try {
        // Создание стека для std::string
        Stack<std::string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");
        std::cout << "Верхний элемент stringStack: " << stringStack.top() << std::endl;
        stringStack.pop();
        std::cout << "Верхний элемент stringStack после удаления: " << stringStack.top() << std::endl;
        stringStack.pop();
        // Вызовет исключение, так как стек пуст
        stringStack.pop();

    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
