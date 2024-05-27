// Лаб_6, В-5, программы на учитывающая заявки на авиабилеты.
//В программе реализованы функции для добавления, удаления, 
//вывода заявок по номеру рейса и дате вылета, а также вывод всех заявок.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class TicketRequest {
public:
    std::string destination;
    std::string flightNumber;
    std::string passengerName;
    std::string departureDate;

    TicketRequest(std::string dest, std::string flightNum, std::string passName, std::string depDate)
        : destination(dest), flightNumber(flightNum), passengerName(passName), departureDate(depDate) {}

    void print() const {
        std::cout << "Пункт назначения: " << destination
            << ", Номер рейса: " << flightNumber
            << ", Пассажир: " << passengerName
            << ", Дата вылета: " << departureDate << std::endl;
    }
};

class TicketRequestManager {
private:
    std::vector<TicketRequest> requests;

public:
    void addRequest(const TicketRequest& request) {
        requests.push_back(request);
    }

    void removeRequest(const std::string& flightNumber, const std::string& departureDate) {
        auto it = std::remove_if(requests.begin(), requests.end(),
            [&flightNumber, &departureDate](const TicketRequest& request) {
                return request.flightNumber == flightNumber && request.departureDate == departureDate;
            });

        if (it != requests.end()) {
            requests.erase(it, requests.end());
            std::cout << "Заявка успешно удалена.\n";
        }
        else {
            std::cout << "Не найдена заявка для удаления.\n";
        }
    }

    void printRequestsByFlightAndDate(const std::string& flightNumber, const std::string& departureDate) const {
        bool found = false;
        for (const auto& request : requests) {
            if (request.flightNumber == flightNumber && request.departureDate == departureDate) {
                request.print();
                found = true;
            }
        }
        if (!found) {
            std::cout << "Заявки на рейс " << flightNumber << " на дату " << departureDate << " не найдены.\n";
        }
    }

    void printAllRequests() const {
        if (requests.empty()) {
            std::cout << "Заявок нет.\n";
        }
        else {
            for (const auto& request : requests) {
                request.print();
            }
        }
    }
};

void showMenu() {
    std::cout << "Меню:\n";
    std::cout << "1. Добавить заявку\n";
    std::cout << "2. Удалить заявку\n";
    std::cout << "3. Показать заявки по номеру рейса и дате вылета\n";
    std::cout << "4. Показать все заявки\n";
    std::cout << "5. Выход\n";
    std::cout << "Введите ваш выбор: ";
}

int main() {
    setlocale(0, "Rus");
    TicketRequestManager manager;
    int choice;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очистка буфера ввода

        switch (choice) {
        case 1: {
            std::string destination, flightNumber, passengerName, departureDate;
            std::cout << "Введите пункт назначения: ";
            std::getline(std::cin, destination);
            std::cout << "Введите номер рейса: ";
            std::getline(std::cin, flightNumber);
            std::cout << "Введите фамилию и инициалы пассажира: ";
            std::getline(std::cin, passengerName);
            std::cout << "Введите дату вылета (ГГГГ-ММ-ДД): ";
            std::getline(std::cin, departureDate);
            manager.addRequest(TicketRequest(destination, flightNumber, passengerName, departureDate));
            break;
        }
        case 2: {
            std::string flightNumber, departureDate;
            std::cout << "Введите номер рейса: ";
            std::getline(std::cin, flightNumber);
            std::cout << "Введите дату вылета (ГГГГ-ММ-ДД): ";
            std::getline(std::cin, departureDate);
            manager.removeRequest(flightNumber, departureDate);
            break;
        }
        case 3: {
            std::string flightNumber, departureDate;
            std::cout << "Введите номер рейса: ";
            std::getline(std::cin, flightNumber);
            std::cout << "Введите дату вылета (ГГГГ-ММ-ДД): ";
            std::getline(std::cin, departureDate);
            manager.printRequestsByFlightAndDate(flightNumber, departureDate);
            break;
        }
        case 4: {
            manager.printAllRequests();
            break;
        }
        case 5:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неправильный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
