#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>

void printHelp() {
    std::cout << "Использование: calculator -o <операция> <операнды>\n";
    std::cout << "Доступные операции:\n";
    std::cout << "  summa    - Сложение (аддитивный)\n";
    std::cout << "  minus    - Вычитание (аддитивный)\n";
    std::cout << "  multiply  - Умножение (мультипликативный)\n";
    std::cout << "  divide    - Деление (мультипликативный)\n";
    std::cout << "  average   - Среднее арифметическое (статистический)\n";
    std::cout << "  median    - Медиана (статистический)\n";
    std::cout << "  sin       - Синус (тригонометрический, режим градусов и радиан)\n";
    std::cout << "Пример: calculator -o summa 45 13 -2\n";
}

double calculate(const std::string& operation, const std::vector<double>& operands) {
    if (operation == "summa") {
        double result = 0;
        for (double operand : operands) {
            result += operand;
        }
        return result;
    } else if (operation == "minus") {
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            result -= operands[i];
        }
        return result;
    } else if (operation == "multiply") {
        double result = 1;
        for (double operand : operands) {
            result *= operand;
        }
        return result;
    } else if (operation == "divide") {
        double result = operands[0];
        for (size_t i = 1; i < operands.size(); ++i) {
            if (operands[i] == 0) {
                std::cerr << "Ошибка: Деление на ноль.\n";
                exit(EXIT_FAILURE);
            }
            result /= operands[i];
        }
        return result;
    } else if (operation == "average") {
        double sum = 0;
        for (double operand : operands) {
            sum += operand;
        }
        return sum / operands.size();
    } else if (operation == "median") {
        std::vector<double> sortedOperands = operands;
        std::sort(sortedOperands.begin(), sortedOperands.end());
        size_t n = sortedOperands.size();
        return (n % 2 == 0) ? (sortedOperands[n / 2 - 1] + sortedOperands[n / 2]) / 2 : sortedOperands[n / 2];
    } else if (operation == "sin") {
        if (operands.size() != 1) {
            std::cerr << "Ошибка: Для синуса требуется один аргумент.\n";
            exit(EXIT_FAILURE);
        }
        return std::sin(operands[0] * M_PI / 180); // Преобразование в радианы
    } else {
        std::cerr << "Ошибка: Неизвестная операция.\n";
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printHelp();
        return 1;
    }

    std::string operation;
    std::vector<double> operands;

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-o") {
            if (i + 1 < argc) {
                operation = argv[++i];
            } else {
                std::cerr << "Ошибка: Не указана операция.\n";
                return 1;
            }
        } else {
            operands.push_back(std::atof(argv[i]));
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
