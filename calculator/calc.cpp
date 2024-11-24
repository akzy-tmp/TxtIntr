#include <iostream>
#include <getopt.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printHelp() {
    cout << "Usage:\n";
    cout << "  -o, --operation <operation>  Specify the operation to perform (average or median)\n";
    cout << "  Operands must be provided as positional parameters (e.g., 45 13 -2).\n";
    cout << "  You must provide between 7 and 10 operands.\n";
}

float calculateAverage(const vector<float>& operands) {
    float sum = 0;
    for (float num : operands) {
        sum += num;
    }
    return sum / operands.size();
}

float calculateMedian(vector<float>& operands) {
    sort(operands.begin(), operands.end());
    int n = operands.size();
    
    if (n % 2 == 0) {
        return (operands[n / 2 - 1] + operands[n / 2]) / 2;
    } else {
        return operands[n / 2];
    }
}

int main(int argc, char **argv) {
    // Проверка на количество аргументов
    if (argc < 9 || argc > 12) { // от 7 до 10 операндов + опция и операция
        printHelp();
        return 1;
    }

    string operation;
    vector<float> operands;

    // Обработка параметров командной строки
    int opt;
    while ((opt = getopt(argc, argv, "o:")) != -1) {
        switch (opt) {
            case 'o':
                operation = optarg; // Сохраняем операцию
                break;
            default:
                printHelp();
                return 1;
        }
    }

    // Сохраняем операнды
    for (int i = optind; i < argc; i++) {
        operands.push_back(strtof(argv[i], nullptr));
    }

    // Проверка на количество операндов
    if (operands.size() < 7 || operands.size() > 10) {
        printHelp();
        return 1;
    }

    // Выполнение операции
    if (operation == "average") {
        cout << "RESULT: " << calculateAverage(operands) << endl;
    } else if (operation == "median") {
        cout << "RESULT: " << calculateMedian(operands) << endl;
    } else {
        printHelp();
        return 1;
    }

    return 0;
}
