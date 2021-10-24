#include "class_d.h"

data &param_stack::operator[](const int index) {
    return stack[index];
}

void param_stack::add() {
    std::cin >> *this;
}

void param_stack::add(int _a, int _b, double _c, std::string _d) {
    stack.emplace_back(_a, _b, _c, _d);
}

void param_stack::add(data const &param) {
    stack.push_back(param);
}

void param_stack::print() const {
    for (const auto &i: stack) {
        std::cout << i;
    }
}

void param_stack::del(int index) {
    if (index < 0 || index > stack.size() - 1) throw std::invalid_argument("Invalid index");
    stack.erase(stack.cbegin() + index);
}

param_stack param_stack::operator+(const param_stack &second) {
    param_stack paramStack(*this);
    for (const auto &i: second.stack) {
        paramStack.stack.push_back(i);
    }
    return paramStack;
}

param_stack &param_stack::operator++() {
    stack.emplace_back();
    return *this;
}

param_stack param_stack::operator++(int) {
    param_stack prev(*this);
    ++(*this);
    return prev;
}

param_stack &param_stack::operator-() {
    for (auto &i: stack) {
        i.a *= -1;
        i.b *= -1;
        if (i.c != 0) i.c *= -1;
    }
    return *this;
}

param_stack &param_stack::operator+=(param_stack &added) {
    for (const auto &i: added.stack) {
        stack.push_back(i);
    }
    return *this;
}

