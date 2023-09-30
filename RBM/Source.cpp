#include <iostream>

using namespace std;

int main() {
    setlocale(0, "");
    cout << "Размер int: " << sizeof(int) << " байта" << endl;
    cout << "Размер short int: " << sizeof(short int) << " байта" << endl;
    cout << "Размер long int: " << sizeof(long int) << " байта" << endl;
    cout << "Размер float: " << sizeof(float) << " байта" << endl;
    cout << "Размер double: " << sizeof(double) << " байт" << endl;
    cout << "Размер long double: " << sizeof(long double) << " байт" << endl;
    cout << "Размер char: " << sizeof(char) << " байт" << endl;
    cout << "Размер bool: " << sizeof(bool) << " байт" << endl;
    
    return 0;
}