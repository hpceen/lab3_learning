#include "strucrt_d.h"

void data::set() {
    std::cout << "int a = ";
    std::cin >> a;
    std::cout << "int b = ";
    std::cin >> b;
    std::cout << "double c = ";
    std::cin >> c;
    std::cout << "string d = ";
    std::cout.flush();
    std::cin >> d;
}

void data::print() const {
    std::cout << a << " " << b << " " << c << " " << d << std::endl;
}

void data::type_print(const std::type_info &type) const {
    if (type == typeid(int)) {
        std::cout << a << " " << b << std::endl;
    } else if (type == typeid(double)) {
        std::cout << c << std::endl;
    } else if (type == typeid(std::string) || type == typeid(std::basic_string<char>) || type == typeid(char *)) {
        std::cout << d << std::endl;
    } else {
        std::cout << "This type doesn't exist" << std::endl;
    }
}