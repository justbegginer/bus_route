//
// Created by raspberry on 26.11.2020.
//
#pragma once
#ifndef INDIVIDUAL7_VECTOR_H
#define INDIVIDUAL7_VECTOR_H
#include "BusRoute.h"

class Vector {
private:
    BusRoute *routes;
    int length;
    void change_size(int difference);
public:
    Vector();
    Vector(BusRoute *routes , int length);
    Vector(const Vector &vector);
    void push(BusRoute busRoute);
    BusRoute pop();
    BusRoute& operator[](int index);
    int size();
    ~Vector();
};


#endif //INDIVIDUAL7_VECTOR_H
