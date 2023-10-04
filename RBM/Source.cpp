#include <iostream>

int main() {
    setlocale(0, "");
    bool cycle = 1;
    char type;
    while (cycle) {
        do {
            std::cout << "Введите тип числа, двоичное представление которого нужно. 'i' для типа int, 'f' для типа float.\n"
                << "Если вы хотите вывести сколько памяти отводится под различные типы данных - введите 's'. \nВвод: ";
            std::cin >> type;
        } while (!type);
        if (type == 'i') {
            int number;
            std::cout << "Введите целое число: ";
            std::cin >> number;
            int order = sizeof(int) * 8;
            int mask = 1 << (order - 1);

            for (int i = 0; i < order; i++) {
                std::cout << ((number & mask) ? "1" : "0");
                number <<= 1;
                if (i == 0 || i % 8 == 7) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        else if (type == 'f') {
            std::cout << "Введите вещественное число: ";
            union {
                int integerA;
                float floatB;
            };
            std::cin >> floatB;
            int order = sizeof(int) * 8;
            int mask = 1 << (order - 1);

            for (int i = 0; i < order; i++) {
                std::cout << ((integerA & mask) ? "1" : "0");
                integerA <<= 1;
                if (i == 0 || i == 8) {
                    std::cout << " ";
                }
            }

            std::cout << std::endl;

        }
        else if (type == 's') {
            std::cout << "Размер int: " << sizeof(int) << " байта" << std::endl;
            std::cout << "Размер short int: " << sizeof(short int) << " байта" << std::endl;
            std::cout << "Размер long int: " << sizeof(long int) << " байта" << std::endl;
            std::cout << "Размер float: " << sizeof(float) << " байта" << std::endl;
            std::cout << "Размер double: " << sizeof(double) << " байт" << std::endl;
            std::cout << "Размер long double: " << sizeof(long double) << " байт" << std::endl;
            std::cout << "Размер char: " << sizeof(char) << " байт" << std::endl;
            std::cout << "Размер bool: " << sizeof(bool) << " байт" << std::endl << std::endl;
        }
        else {
            std::cout << "Неверный ввод";
        }
        std::cout << "\n\nВы хотите повторить? \nВведите '1' если да, иначе '0': ";
        std::cin >> cycle;
    }
    return 0;
}


