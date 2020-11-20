//
// Created by raspberry on 20.11.2020.
//

#include <iostream>
#include "Time.h"

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

    BusRoute(int route_number, std::string destination_name, const Time& arriving_time);

    BusRoute(BusRoute const &bus_route);

    int getRouteNumber() const;

    void setRouteNumber(int routeNumber);

    const std::string &getDestinationName() const;

    void setDestinationName(const std::string &destinationName);

    const Time &getArrivingTime() const;

    void setArrivingTime(const Time &arrivingTime);

    bool operator<(const BusRoute &rhs) const;

    bool operator>(const BusRoute &rhs) const;

    bool operator<=(const BusRoute &rhs) const;

    bool operator>=(const BusRoute &rhs) const;

    bool operator==(const BusRoute &rhs) const;

    bool operator!=(const BusRoute &rhs) const;
};