//
// Created by raspberry on 26.11.2020.
//

#include "Vector.h"

Vector::Vector() {
    length = 0 ;
    routes = new BusRoute[0];
}

Vector::Vector(BusRoute *routes, int length) {
    this->length = length;
    this->routes = new BusRoute[length];
    for (int i = 0 ; i < length ; i++){
        *(this->routes+i) = *(routes+i);
    }
}

Vector::Vector(const Vector &vector) {
    length = vector.length;
    routes = new BusRoute[length];
    for (int i = 0; i < length; ++i) {
        *(routes+i) = *(vector.routes+i);
    }
}

void Vector::push(BusRoute busRoute) {
    change_size(1);
    *(routes+length-1) = BusRoute(busRoute);
}

BusRoute Vector::pop() {
    BusRoute last = BusRoute(*(routes+length-1));
    change_size(-1);
    return last;
}

BusRoute &Vector::operator[](int index) {
    return *(routes+index);
}

Vector::~Vector() {
    delete [] routes;
}

int Vector::size() {
    return length;
}

void Vector::change_size(int difference) {
    BusRoute *new_routes = new BusRoute();
    for (int i = 0; i < length+difference; ++i) {
        *(new_routes+i) = BusRoute(*(routes+i));
    }
    length+=difference;
    routes = new_routes;
}
