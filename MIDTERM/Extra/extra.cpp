#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <sstream>

using namespace std;

string Unit(int number_of_digit) {
    switch (number_of_digit/3) {
        case 0: 
            return "";
        case 1: 
            return "Kilo";
        case 2: 
            return "Mega";
        case 3: 
            return "Giga";
        case 4: 
            return "Tera";
        case 5: 
            return "Peta";
        case 6: 
            return "Exa";
        default: 
            return "Exa";        
    }
}

string suffixWithUnit(double number) {
    //split number to integer_part and decimal_part
    long long integer_part = (long long)(number);
    string pre = to_string(integer_part);

    double decimal_part = number - integer_part;
    //convert decimal part to int. Ex: 0.123 = 123 
    while (decimal_part > (long long)(decimal_part)) {
        decimal_part *= 10;
    }
    string post = (decimal_part != 0) ? to_string((long long)(decimal_part)) : "";
    if (pre.length() % 3 == 0) {
        return pre.substr(0, 3) + ((post != "") ? ("." + pre.substr(3) + post) : "") + " " + Unit(pre.length() - 1);
    } else return pre.substr(0, pre.length() % 3) + "." + pre.substr(pre.length() % 3) + post +  " " + Unit(pre.length());
}

int main() {
    cout << suffixWithUnit(0.12) << endl;

    cout << suffixWithUnit(1234) << endl;

    cout << suffixWithUnit(12345) << endl;
    cout << suffixWithUnit(1234567) << endl;
    cout << suffixWithUnit(12345678) << endl;

    return 0;
}