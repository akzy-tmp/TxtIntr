#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Для std::atof

void printHelp() {
    std::cout << "Использование: calculator -o <операция> <операнды>\n";
    std::cout << "Доступные операции: summa, minus, multiply, divide\n";
    std::cout << "Пример: calculator -o summa 45 13 -2\n";
}

double calculate(const std::string& operation, const std::vector<double>& operands) {
    double result = operands[0]; // Начальное значение для операций

    for (size_t i = 1; i < operands.size(); ++i) {
        if (operation == "summa") {
            result += operands[i];
        } else if (operation == "minus") {
            result -= operands[i];
        } else if (operation == "multiply") {
            result *= operands[i];
        } else if (operation == "divide") {
            if (operands[i] == 0) {
                std::cerr << "Ошибка: Деление на ноль.\n";
                exit(EXIT_FAILURE);
            }
            result /= operands[i];
        } else {
            std::cerr << "Ошибка: Неизвестная операция.\n";
            exit(EXIT_FAILURE);
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printHelp();
        return 1;
    }

    std::string operation;
    std::vector<double> operands;

    // Обработка аргументов
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-o") {
            if (i + 1 < argc) {
                operation = argv[++i]; // Установка операции
            } else {
                std::cerr << "Ошибка: Не указана операция.\n";
                return 1;
            }
        } else {
            operands.push_back(std::atof(argv[i])); // Преобразование строки в число
        }
    }

    if (operation.empty()) {
        std::cerr << "Ошибка: Операция не указана.\n";
        printHelp();
        return 1;
    }

    double result = calculate(operation, operands);
    std::cout << "Результат: " << result << std::endl;

    return 0;
}