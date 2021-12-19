#pragma once

#include "Sequences.h"

template<typename T>
bool cmp1(const T &a, const T &b) {//сравнение двух элементов
    return a <= b;
}

template<typename T>
bool cmp2(const T &a, const T &b) {
    return a < b;
}

template<typename T>
bool cmp3(const T &a, const T &b) {
    return a > b;
}

//в связном списке доступ к итому элементу линейный
//в массиве он контс