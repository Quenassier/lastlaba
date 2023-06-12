#include <iostream> // Подключение библиотеки для стандартного ввода-вывода
#include <fstream> // Подключение библиотеки для работы с файлами
#include <vector> // Подключение библиотеки для работы с векторами
#include <map> // Подключение библиотеки для работы с отображениями (map)
#include <iomanip> // Подключение библиотеки для управления выводом
#include <string> // Подключение библиотеки для работы со строками

using namespace std; // Использование пространства имен std (стандартной библиотеки)

class ExpenseTracker { // Определение класса ExpenseTracker
private:
    std::string expensesFile; // Путь к файлу для записи расходов
    std::string incomeFile; // Путь к файлу для записи доходов
    std::map<std::string, double> expenseCategories; // Категории расходов и суммы расходов по каждой категории
    double totalExpenses; // Общая сумма расходов
    double totalIncome; // Общая сумма доходов

public:
    ExpenseTracker(const std::string& expensesFile, const std::string& incomeFile) // Конструктор класса ExpenseTracker
        : expensesFile(expensesFile), incomeFile(incomeFile), totalExpenses(0.0), totalIncome(0.0) {} // Инициализация полей класса

    void recordExpense(const std::string& category, double amount) { // Метод для записи расхода
        std::ofstream file(expensesFile, std::ios::app); // Создание объекта ofstream для записи в файл с опцией дополнения (append)
        if (file.is_open()) { // Проверка, удалось ли открыть файл для записи
            file << category << "," << amount << std::endl; // Запись категории и суммы расхода в файл
            file.close(); // Закрытие файла
            totalExpenses += amount; // Увеличение общей суммы расходов
            expenseCategories[category] += amount; // Увеличение суммы расходов в указанной категории
            std::cout << "Expense recorded successfully." << std::endl; // Вывод сообщения об успешной записи расхода
        }
        else {
            std::cout << "Unable to open expenses file." << std::endl; // Вывод сообщения об ошибке при открытии файла для записи расхода
        }
    }

    void recordIncome(double amount) { // Метод для записи дохода
        std::ofstream file(incomeFile, std::ios::app); // Создание объекта ofstream для записи в файл с опцией дополнения (append)
        if (file.is_open()) { // Проверка, удалось ли открыть файл для записи
            file << amount << std::endl; // Запись суммы дохода в файл
            file.close(); // Закрытие файла
            totalIncome += amount; // Увеличение общей суммы доходов
            std::cout << "Income recorded successfully." << std::endl; // Вывод сообщения об успешной записи дохода
        }
        else {
            std::cout << "Unable to open income file." << std::endl; // Вывод сообщения об ошибке при открытии файла для записи дохода
        }
    }

    void calculateBalances() { // Метод для вычисления баланса
        double balance = totalIncome - totalExpenses; // Вычисление баланса
        std::cout << "Total Income: " << totalIncome << std::endl; // Вывод общей суммы доходов
        std::cout << "Total Expenses: " << totalExpenses << std::endl; // Вывод общей суммы расходов
        std::cout << "Balance: " << balance << std::endl; // Вывод баланса
    }

    void calculateCategoryPercentagesLastMonth() { // Метод для вычисления процентного соотношения расходов по категориям за прошлый месяц
        std::map<std::string, double> categoryPercentages; // Категории расходов и их процентные соотношения
        double lastMonthExpenses = 0.0; // Сумма расходов за прошлый месяц
        std::ifstream file(expensesFile); // Создание объекта ifstream для чтения файла
        if (file.is_open()) { // Проверка, удалось ли открыть файл для чтения
            std::string line; // Переменная для хранения текущей строки
            while (getline(file, line)) { // Чтение файла построчно
                // Предполагается, что формат строки следующий: "категория,сумма"
                size_t pos = line.find(","); // Поиск позиции разделителя (",")
                std::string category = line.substr(0, pos); // Извлечение категории из строки
                double amount = stod(line.substr(pos + 1)); // Извлечение суммы расхода из строки и преобразование в тип double

                categoryPercentages[category] += amount; // Увеличение суммы расходов в указанной категории
                lastMonthExpenses += amount; // Увеличение суммы расходов за прошлый месяц
            }
            file.close(); // Закрытие файла

            std::cout << "Category Percentages for Last Month:" << std::endl; // Вывод заголовка для процентного соотношения расходов по категориям за прошлый месяц
            for (const auto& entry : categoryPercentages) { // Перебор всех категорий и их сумм расходов
                double percentage = (entry.second / lastMonthExpenses) * 100.0; // Вычисление процентного соотношения
                std::cout << entry.first << ": " << std::fixed << std::setprecision(2) << percentage << "%" << std::endl; // Вывод категории и процентного соотношения
            }
        }
        else {
            std::cout << "Unable to open expenses file." << std::endl; // Вывод сообщения об ошибке при открытии файла для чтения расходов
        }
    }

    void calculateCategoryPercentagesOverall() { // Метод для вычисления общего процентного соотношения расходов по категориям
        std::cout << "Category Percentages Overall:" << std::endl; // Вывод заголовка для общего процентного соотношения расходов по категориям
        for (const auto& entry : expenseCategories) { // Перебор всех категорий и их сумм расходов
            double percentage = (entry.second / totalExpenses) * 100.0; // Вычисление процентного соотношения
            std::cout << entry.first << ": " << std::fixed << std::setprecision(2) << percentage << "%" << std::endl; // Вывод категории и процентного соотношения
        }
    }
};

int main() { // Главная функция программы
    ExpenseTracker tracker("expenses.txt", "income.txt"); // Создание объекта класса ExpenseTracker с указанием путей к файлам расходов и доходов

    int choice; // Переменная для хранения выбора пользователя
    do {
        std::cout << "Expense Tracker Menu" << std::endl; // Вывод меню программы
        std::cout << "1. Record Expense" << std::endl; // Вывод пункта меню для записи расхода
        std::cout << "2. Record Income" << std::endl; // Вывод пункта меню для записи дохода
        std::cout << "3. Calculate Balances" << std::endl; // Вывод пункта меню для вычисления баланса
        std::cout << "4. Calculate Category Percentages (Last Month)" << std::endl; // Вывод пункта меню для вычисления процентного соотношения расходов по категориям за прошлый месяц
        std::cout << "5. Calculate Category Percentages (Overall)" << std::endl; // Вывод пункта меню для вычисления общего процентного соотношения расходов по категориям
        std::cout << "0. Exit" << std::endl; // Вывод пункта меню для выхода
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Ввод выбора пользователя

        switch (choice) { // Обработка выбора пользователя
        case 1: {
            std::string category; // Переменная для хранения категории расхода
            double amount; // Переменная для хранения суммы расхода
            std::cout << "Enter category: ";
            std::cin >> category; // Ввод категории расхода
            std::cout << "Enter amount: ";
            std::cin >> amount; // Ввод суммы расхода
            tracker.recordExpense(category, amount); // Вызов метода записи расхода
            break;
        }
        case 2: {
            double amount; // Переменная для хранения суммы дохода
            std::cout << "Enter amount: ";
            std::cin >> amount; // Ввод суммы дохода
            tracker.recordIncome(amount); // Вызов метода записи дохода
            break;
        }
        case 3:
            tracker.calculateBalances(); // Вызов метода вычисления баланса
            break;
        case 4:
            tracker.calculateCategoryPercentagesLastMonth(); // Вызов метода вычисления процентного соотношения расходов по категориям за прошлый месяц
            break;
        case 5:
            tracker.calculateCategoryPercentagesOverall(); // Вызов метода вычисления общего процентного соотношения расходов по категориям
            break;
        case 0:
            std::cout << "Exiting..." << std::endl; // Вывод сообщения о выходе из программы
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl; // Вывод сообщения о недопустимом выборе
            break;
        }

        std::cout << std::endl; // Печать пустой строки для отделения вывода меню от следующей итерации
    } while (choice != 0); // Выполнять цикл до выбора пункта выхода

    return 0; // Возвращение значения 0, что указывает на успешное завершение программы
}
