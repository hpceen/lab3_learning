#ifndef LAB3_STRUCRT_S_H
#define LAB3_STRUCRT_S_H

#include <iostream>

struct data {
    int a;
    int b;
    double c;
    std::string d;

    data() { //пустой конструктор (по умолчанию)
        a = 0;
        b = 0;
        c = 0;
    }

    data(int _a, int _b, double _c, std::string &_d) { //конструктор принимающий значения
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }

    data(const data &param) { //копирующий конструктор
        a = param.a;
        b = param.b;
        c = param.c;
        d = param.d;
    }

    ~data() = default; //деструктор по дефолту

    void set(); //неиспользуемый метод устанавливающий новые значения

    void print() const; //печать всех значений

    void type_print(
            const std::type_info &type) const; //печать определенного типа из структуры используется через typeid(тип)
    //пример использования: type_print(typeid(int));

    data &operator=(const data &param) = default; //оператор присваивания по дефолту

    friend inline std::ostream &operator<<(std::ostream &ostream,
                                           const data &data); //перегруженный оператор вывода для структуры (выводит занчения через " ")

    friend inline std::istream &
    operator>>(std::istream &istream, data &data); //перегруженный оператор ввода для структуры
};

inline std::ostream &operator<<(std::ostream &ostream, const data &data) {
    ostream << data.a << " " << data.b << " " << data.c << " " << data.d << std::endl;
    return ostream;
}

inline std::istream &operator>>(std::istream &istream, data &data) {
    std::cout << "int a = ";
    istream >> data.a;
    std::cout << "int b = ";
    istream >> data.b;
    std::cout << "double c = ";
    istream >> data.c;
    std::cout << "string d = ";
    std::cout.flush();
    istream >> data.d;
    return istream;
}

#endif //LAB3_STRUCRT_S_H
