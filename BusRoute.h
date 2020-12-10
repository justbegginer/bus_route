//
// Created by raspberry on 20.11.2020.
//

#include <iostream>
#include "Time.h"

#pragma once
#ifndef INDIVIDUAL7_BUSROUTE_H
#define INDIVIDUAL7_BUSROUTE_H

#endif //INDIVIDUAL7_BUSROUTE_H


class BusRoute {
private:
    int _route_number;
    std::string _destination_name;
    Time _arriving_time;
public:
    BusRoute();

    BusRoute(int route_number, std::string destination_name, const Time &arriving_time);

    BusRoute(BusRoute const &bus_route);

    int getRouteNumber() const;

    void setRouteNumber(int routeNumber);

    const std::string &getDestinationName() const;

    void setDestinationName(const std::string &destinationName);

    const Time &getArrivingTime() const;

    void setArrivingTime(const Time &arrivingTime);

    friend bool operator<(const BusRoute &first, const BusRoute &rhs);

    bool operator>(const BusRoute &rhs) const;

    bool operator<=(const BusRoute &rhs) const;

    bool operator>=(const BusRoute &rhs) const;

    bool operator==(const BusRoute &rhs) const;

    bool operator!=(const BusRoute &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const BusRoute &route);

    friend std::istream &operator>>(std::istream &os, BusRoute &route);

    friend BusRoute operator+(BusRoute &this_route, BusRoute &another_route);

    BusRoute operator-(BusRoute &another_route);

    BusRoute &operator++();

    BusRoute &operator--();

    friend BusRoute operator++(BusRoute &busRoute, int);

    friend BusRoute operator--(BusRoute &busRoute, int);

    BusRoute &operator=(const BusRoute &busRoute);

    virtual ~BusRoute();

};