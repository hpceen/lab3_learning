#include "class_s.h"

data &param_stack::operator[](const int index) {
    if (index < cur_size && index >= 0) return stack[index];
    else throw std::invalid_argument("No such element");
}

void param_stack::add() {
    if (empty() == 1) {
        throw std::overflow_error("No space");
    } else {
        std::cin >> stack[cur_size];
    }
    ++cur_size;
}

void param_stack::add(int _a, int _b, double _c, std::string _d) {
    if (empty() == 1) {
        throw std::overflow_error("No space");
    } else {
        stack[cur_size].a = _a;
        stack[cur_size].b = _b;
        stack[cur_size].c = _c;
        stack[cur_size].d = std::move(_d);
    }
    ++cur_size;
}

void param_stack::add(data const &param) {
    if (empty() == 1) {
        throw std::overflow_error("No space");
    } else {
        stack[cur_size] = param;
    }
    ++cur_size;
}

void param_stack::print() const {
    for (int i = 0; i < cur_size; ++i) {
        std::cout << stack[i];
    }
}

[[nodiscard]] short int param_stack::empty() const {
    if (cur_size == 0) return -1;
    else if (cur_size < size) return 0;
    else return 1;
}

void param_stack::del(int index) {
    if (index <= cur_size - 1 && index >= 0) {
        if (index != cur_size - 1)
            stack[index] = stack[cur_size - 1];
        stack[cur_size - 1] = data();
        --cur_size;
    } else {
        throw std::invalid_argument("Invalid index");
    }
}

param_stack param_stack::operator+(const param_stack &stack1) {
    param_stack paramStack(size + stack1.size);
    paramStack.cur_size = cur_size + stack1.cur_size;
    int j = 0;
    for (int i = 0; i < cur_size; ++i, ++j) {
        paramStack.stack[j] = stack[i];
    }
    for (int i = 0; i < stack1.cur_size; ++i, ++j) {
        paramStack.stack[j] = stack1.stack[i];
    }
    return paramStack;
}

param_stack &param_stack::operator++() {
    if (cur_size == size) throw std::overflow_error("Not enough space");
    ++cur_size;
    return *this;
}

param_stack param_stack::operator++(int) {
    param_stack prev(*this);
    ++(*this);
    return prev;
}

param_stack &param_stack::operator-() {
    for (int i = 0; i < cur_size; ++i) {
        stack[i].a *= -1;
        stack[i].b *= -1;
        if (stack[i].c != 0) stack[i].c *= -1;
    }
    return *this;
}

param_stack &param_stack::operator+=(param_stack &added) {
    if (cur_size + added.cur_size >= size) throw std::overflow_error("Not enough space");
    for (int i = 0; i < added.cur_size; ++i) {
        add(added.stack[i]);
    }
    return *this;
}