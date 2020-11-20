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
    _arriving_time = Time(arriving_time);
}
BusRoute::BusRoute(const BusRoute &bus_route) {
    _route_number = bus_route._route_number;
    _arriving_time = Time(bus_route._arriving_time);
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

bool BusRoute::operator<(const BusRoute &rhs) const {
    return (_route_number < rhs._route_number);
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



