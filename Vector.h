//
// Created by raspberry on 26.11.2020.
//
#pragma once
#ifndef INDIVIDUAL7_VECTOR_H
#define INDIVIDUAL7_VECTOR_H
#include "BusRoute.h"

template<typename Type>
class Vector {
private:
    Type *routes;
    int length;

    void change_size(int difference);

public:
    Vector();

    Vector(Type *vector, int length);

    Vector(const Vector &vector);

    void push(Type &elem);

    Type pop();

    Type &operator[](int index);

    int size();

    ~Vector();
};

template<typename Type>
Vector<Type>::Vector() {
    length = 0;
    routes = new Type[0];
}
template<typename Type>
Vector<Type>::Vector(Type *routes, int length) {
    this->length = length;
    this->routes = new Type[length];
    for (int i = 0; i < length; i++) {
        *(this->routes + i) = *(routes + i);
    }
}
template<typename Type>
Vector<Type>::Vector(const Vector<Type> &vector) {
    length = vector.length;
    routes = new Type[length];
    for (int i = 0; i < length; ++i) {
        *(routes + i) = *(vector.routes + i);
    }
}
template<typename Type>
void Vector<Type>::push(Type &el) {
    change_size(1);
    *(routes + length - 1) = el;
}
template<typename Type>
Type Vector<Type>::pop() {
    Type last = Type(*(routes + length - 1));
    change_size(-1);
    return last;
}
template<typename Type>
Type &Vector<Type>::operator[](int index) {
    if (index >= length || index < 0)
        throw std::out_of_range("index of Vector out of range");
    return *(routes + index);
}
template<typename Type>
Vector<Type>::~Vector() {
    delete[] routes;
}
template<typename Type>
int Vector<Type>::size() {
    return length;
}
template <typename Type>
void Vector<Type>::change_size(int difference) {
    Type *new_Type = new Type[length + difference];
    for (int i = 0; i < length; ++i) {
        *(new_Type + i) = (*(routes + i));
    }
    length += difference;
    routes = new_Type;
}

#endif //INDIVIDUAL7_VECTOR_H
