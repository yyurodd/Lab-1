#include <iostream>

int main() {
    setlocale(0, "");
    bool cycle = 1;
    char type, choice;
    while (cycle) {
        do {
            std::cout << "Введите тип числа, двоичное представление которого нужно. 'i' для типа int, 'f' для типа float.\n"
                << "Если вы хотите вывести сколько памяти отводится под различные типы данных - введите 's'. \nВвод: ";
            std::cin >> type;
        } while (!type);
        if (type == 'i') {
            int number, copy;
            std::cout << "Введите целое число: ";
            std::cin >> number;
            copy = number;
            int order = sizeof(int) * 8;
            int mask = 1 << (order - 1);
            const int n = 32;
            int A[n];
            for (int i = 0; i < order; i++) {
                std::cout << ((number & mask) ? 1 : 0);

                number <<= 1;
                if (i == 0 || i % 8 == 7) {
                    std::cout << " ";
                }

            }
            std::cout << std::endl;
            {
                for (int i = 0; i < order; i++) {
                    A[i] = ((copy & mask) ? 1 : 0);
                    copy <<= 1;
                    
                }

            }
            
            std::cout << "\nВы хотите сдвинуть все биты, равные единице, вправо?\nВведите '1', если да, иначе '0': ";
            std::cin >> choice;
            if (choice == '1') {
                for (int i = 31; i >= 0; i--) {


                    if ((A[i] == 1) && (i == 31)) {
                        A[i] = 0;
                    }
                    else if ((A[i] == 1) && (i != 31)) {
                        A[i + 1] = 1;
                        A[i] = 0;
                    }

                }
                for (int i = 0; i < 32; i++) {
                    std::cout << A[i];
                    if (i == 0 || i % 8 == 7) {
                        std::cout << " ";
                    }
                }

            }
            std::cout << std::endl;
        }
        

        else if (type == 'f') {
            std::cout << "Введите вещественное число: ";
            const int n = 32;
            int A[n];
            union {
                int integerA;
                float floatB;
            };
            int copyA;
            std::cin >> floatB;
            copyA = integerA;
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
            {
                for (int i = 0; i < order; i++) {
                    A[i] = ((copyA & mask) ? 1 : 0);
                    copyA <<= 1;

                }

            }

            std::cout << "\nВы хотите сдвинуть все биты, равные единице, вправо?\nВведите '1', если да, иначе '0': ";
            std::cin >> choice;
            if (choice == '1') {
                for (int i = 31; i >= 0; i--) {


                    if ((A[i] == 1) && (i == 31)) {
                        A[i] = 0;
                    }
                    else if ((A[i] == 1) && (i != 31)) {
                        A[i + 1] = 1;
                        A[i] = 0;
                    }

                }
                for (int i = 0; i < 32; i++) {
                    std::cout << A[i];
                    if (i == 0 || i == 8) {
                        std::cout << " ";
                    }
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

