#ifndef LAB3_CLASS_S_H
#define LAB3_CLASS_S_H

#include <iostream>
#include <vector>
#include "strucrt_s.h"

class param_stack {
private:
    std::vector<data> stack;
    int size;
    int cur_size;
public:

    param_stack() { //по умолчанию с размером 5
        size = 5;
        stack.resize(size);
        cur_size = 0;
    }

    explicit param_stack(int const _size) { //стандартное создание с заданием размера
        size = _size;
        stack.resize(size);
        cur_size = 0;
    }

    param_stack(data *params, const int start,
                const int finish) { //создание из массива поданного в аргументы от start index до finish index с размером finish - start + 1 + 10;
        size = finish - start + 1 + 10;
        stack.resize(size);
        cur_size = finish - start + 1;
        for (int i = start, j = 0; i < finish + 1; ++i, ++j) {
            stack[j] = params[i];
        }
    }

    param_stack(std::vector<data> params, const int start,
                const int finish) { //перегрузка предыдущего метода для использование vector-а
        size = finish - start + 1 + 10;
        stack.resize(size);
        cur_size = finish - start + 1;
        for (int i = start, j = 0; i < finish + 1; ++i, ++j) {
            stack[j] = params[i];
        }
    }

    param_stack(param_stack const &paramStack) { //копирующий конструктор
        stack = paramStack.stack;
        size = paramStack.size;
        cur_size = paramStack.cur_size;
    }

    data &operator[](int index); //обращение к массиву через оператор класса

    void add(); //добавление со вводом из потока ввода

    void add(int _a, int _b, double _c, std::string _d); //добавление с параметрами

    void add(data const &param); //добавление с копированием

    void print() const; //неиспользуемая печать всего массива

    [[nodiscard]] short int empty() const; // -1 пустой; 0 частично заполнен; 1 полностью заполнен

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
    if (paramStack.cur_size == paramStack.size) throw std::overflow_error("Not enough space");
    istream >> paramStack.stack[paramStack.cur_size];
    ++paramStack.cur_size;
    return istream;
}

inline std::ostream &
operator<<(std::ostream &ostream, param_stack &paramStack) {//перегруженный оператор вывода всех значений массива класса
    for (int i = 0; i < paramStack.cur_size; ++i) {
        ostream << paramStack.stack[i];
    }
    return ostream;
}

#endif //LAB3_CLASS_S_H
