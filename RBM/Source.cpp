#include <iostream>

using namespace std;


void print_binary_representation(int number) {
    int order = sizeof(int) * 8 - 1;
    int mask = 1 << order; 

    for (int i = 0; i <= order; i++) {
        std::cout << ((number & mask) ? "1" : "0");
        number <<= 1; 
        if (i % 4 == 3) {
            std::cout << " "; 
        }
    }

    std::cout << std::endl;
}


int main() {
    setlocale(0, "");
    
    cout << "Размер int: " << sizeof(int) << " байта" << endl;
    cout << "Размер short int: " << sizeof(short int) << " байта" << endl;
    cout << "Размер long int: " << sizeof(long int) << " байта" << endl;
    cout << "Размер float: " << sizeof(float) << " байта" << endl;
    cout << "Размер double: " << sizeof(double) << " байт" << endl;
    cout << "Размер long double: " << sizeof(long double) << " байт" << endl;
    cout << "Размер char: " << sizeof(char) << " байт" << endl;
    cout << "Размер bool: " << sizeof(bool) << " байт" << endl << endl;
    

    int num;
    std::cout << "Введите целое число: ";
    std::cin >> num;

    print_binary_representation(num);

    return 0;
}








