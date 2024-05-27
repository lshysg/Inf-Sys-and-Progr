// В-5, Создания шаблона класса «однонаправленный линейный список» 
#include <iostream>
#include <locale>
#include <stdexcept>

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList();

    // Добавление элемента в конец списка
    void push_back(const T& value);
    // Удаление первого вхождения элемента
    void remove(const T& value);
    // Получение элемента по индексу
    T& at(std::size_t index);
    // Проверка, пуст ли список
    bool empty() const { return head == nullptr; }
    // Возвращение размера списка
    std::size_t size() const;

private:
    Node<T>* head;
    Node<T>* tail;
};

template<typename T>
LinkedList<T>::~LinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template<typename T>
void LinkedList<T>::remove(const T& value) {
    if (!head) throw std::out_of_range("Список пуст. Удаление невозможно.");

    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
        return;
    }

    Node<T>* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (current->next) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        if (temp == tail) tail = current;
        delete temp;
    }
    else {
        throw std::invalid_argument("Элемент не найден.");
    }
}

template<typename T>
T& LinkedList<T>::at(std::size_t index) {
    if (!head) throw std::out_of_range("Список пуст.");

    Node<T>* current = head;
    std::size_t count = 0;

    while (current && count < index) {
        current = current->next;
        count++;
    }

    if (!current) throw std::out_of_range("Индекс вне диапазона.");

    return current->data;
}

template<typename T>
std::size_t LinkedList<T>::size() const {
    Node<T>* current = head;
    std::size_t count = 0;

    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    setlocale(0, "Rus");

    try {
        // Создание списка для int
        LinkedList<int> intList;
        intList.push_back(10);
        intList.push_back(20);
        intList.push_back(30);
        std::cout << "Элемент по индексу 1: " << intList.at(1) << std::endl;
        intList.remove(20);
        std::cout << "Элемент по индексу 1 после удаления: " << intList.at(1) << std::endl;

        // Создание списка для double
        LinkedList<double> doubleList;
        doubleList.push_back(1.1);
        doubleList.push_back(2.2);
        doubleList.push_back(3.3);
        std::cout << "Элемент по индексу 1: " << doubleList.at(1) << std::endl;
        doubleList.remove(2.2);
        std::cout << "Элемент по индексу 1 после удаления: " << doubleList.at(1) << std::endl;

        // Создание списка для std::string
        LinkedList<std::string> stringList;
        stringList.push_back("Привет");
        stringList.push_back("Мир");
        stringList.push_back("!");
        std::cout << "Элемент по индексу 1: " << stringList.at(1) << std::endl;
        stringList.remove("Мир");
        std::cout << "Элемент по индексу 1 после удаления: " << stringList.at(1) << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
