#ifndef LAB3_CLASS_S_H
#define LAB3_CLASS_H

#include <iostream>
#include <vector>
#include "strucrt_d.h"

class param_stack {
private:
    std::vector<data> stack;
public:

    param_stack() = default;

    param_stack(data *params, const int start,
                const int finish) { //создание из массива поданного в аргументы от start index до finish index с размером finish - start + 1 + 10;
        for (int i = start, j = 0; i < finish + 1; ++i, ++j) {
            stack[j] = params[i];
        }
    }

    param_stack(std::vector<data> params, const int start,
                const int finish) { //перегрузка предыдущего метода для использование vector-а
        for (int i = start, j = 0; i < finish + 1; ++i, ++j) {
            stack[j] = params[i];
        }
    }

    param_stack(param_stack const &paramStack) { //копирующий конструктор
        stack = paramStack.stack;
    }

    data &operator[](int index); //обращение к массиву через оператор класса

    void add(); //добавление со вводом из потока ввода

    void add(int _a, int _b, double _c, std::string _d); //добавление с параметрами

    void add(data const &param); //добавление с копированием

    void print() const; //неиспользуемая печать всего массива

    void del(int index); //удаление элемента по индексу в массиве

    param_stack operator+(const param_stack &stack1); //оператор сложения (скалдывает два экземпляра класса и возвращает
    //третий с массивом состоящим из двух других и объединенными размерами

    param_stack &operator++(); //префиксный оператор ++ (добавляет один пустой элемент)

    param_stack operator++(int); //постфиксный оператор ++

    param_stack &operator-(); //унарный опертаор - (заменяет все значения на отрицательные)

    param_stack &operator+=(
            param_stack &added); //добавляет к массиву класса все значения из другого массива класса не увеличивая размер size

    friend inline std::ostream &operator<<(std::ostream &ostream,
                                           param_stack &paramStack); //перегруженный оператор вывода всех значений массива класса

    friend inline std::istream &
    operator>>(std::istream &istream, param_stack &paramStack); //перегруженный оператор ввода добавляющий один элемент
};

inline std::istream &
operator>>(std::istream &istream, param_stack &paramStack) {//перегруженный оператор ввода добавляющий один элемент
    data data;
    istream >> data;
    paramStack.stack.push_back(data);
    return istream;
}

inline std::ostream &
operator<<(std::ostream &ostream, param_stack &paramStack) {//перегруженный оператор вывода всех значений массива класса
    for (int i = 0; i < paramStack.stack.size(); ++i) {
        ostream << paramStack.stack[i];
    }
    return ostream;
}

#endif //LAB3_CLASS_S_H
