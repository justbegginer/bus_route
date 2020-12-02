//
// Created by raspberry on 20.11.2020.
//
#include "BusRoute.h"

BusRoute::BusRoute() {
    _route_number = 1;
    _destination_name = "center";
    _arriving_time = Time();
}

BusRoute::BusRoute(int route_number, std::string destination_name, const Time& arriving_time) {
    _route_number = route_number;
    _destination_name = destination_name;
    _arriving_time = arriving_time;
}
BusRoute::BusRoute(const BusRoute &bus_route) {
    _route_number = bus_route._route_number;
    _arriving_time = bus_route._arriving_time;
    _destination_name = bus_route._destination_name;
}

int BusRoute::getRouteNumber() const {
    return _route_number;
}

void BusRoute::setRouteNumber(int routeNumber) {
    _route_number = routeNumber;
}

const std::string &BusRoute::getDestinationName() const {
    return _destination_name;
}

void BusRoute::setDestinationName(const std::string &destinationName) {
    _destination_name = destinationName;
}

const Time &BusRoute::getArrivingTime() const {
    return _arriving_time;
}

void BusRoute::setArrivingTime(const Time &arrivingTime) {
    _arriving_time = arrivingTime;
}

bool operator<(const BusRoute &first , const BusRoute &rhs) {
    return (first._route_number < rhs._route_number);
}

bool BusRoute::operator>(const BusRoute &rhs) const {
    return (_route_number > rhs._route_number);
}

bool BusRoute::operator<=(const BusRoute &rhs) const {
    return !(*this > rhs);
}

bool BusRoute::operator>=(const BusRoute &rhs) const {
    return !(*this < rhs);
}

bool BusRoute::operator==(const BusRoute &rhs) const {
    return _route_number == rhs._route_number;
}

bool BusRoute::operator!=(const BusRoute &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const BusRoute &route) {
    os << "route_number: " << route._route_number << " ,destination_name: " << route._destination_name
       << " ,arriving_time: " << route._arriving_time;
    return os;
}

BusRoute & BusRoute::operator++() {
    ++_route_number;
    return *this;
}

BusRoute & BusRoute::operator--() {
    --_route_number;
    return *this;
}

BusRoute operator++(BusRoute &busRoute , int ) {
    BusRoute prefix_object(busRoute);
    ++busRoute;
    return prefix_object;
}

BusRoute operator--(BusRoute &busRoute, int) {
    BusRoute prefix_object(busRoute);
    --busRoute;
    return prefix_object;
}

BusRoute &BusRoute::operator=(const BusRoute &busRoute) {
    _route_number = busRoute._route_number;
    _arriving_time = busRoute._arriving_time;
    _destination_name = busRoute._destination_name;
    return *this;
}






