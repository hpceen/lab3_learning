#include <iostream>
#include <class_d.h>

void print_menu() {
    std::cout << "1 - Добавление параметра." << std::endl;
    std::cout << "2 - Удаление параметра." << std::endl;
    std::cout << "3 - Печать массива параметров." << std::endl;
    std::cout << "4 - Выход." << std::endl;
}

int get_a() {
    int a;
    std::cin >> a;
    while (a < 1 || a > 4)
        std::cin >> a;
    return a;
}

int main() {
    param_stack stack;
    while (true) {
        print_menu();
        int a = get_a();
        if (a == 1) {
            try {
                stack.add();
            }
            catch (std::exception &err) {
                std::cout << "[] ERROR   " << err.what() << std::endl;
            }
        }
        if (a == 2) {
            try {
                int index;
                std::cout << "Введите index удаляемого элемента" << std::endl;
                std::cin >> index;
                stack.del(index);
            }
            catch (std::exception &err) {
                std::cout << "[] ERROR   " << err.what() << std::endl;
            }
        }
        if (a == 3) {
            std::cout << stack << std::endl;
        }
        if (a == 4) {
            break;
        }
    }
    return 0;
}