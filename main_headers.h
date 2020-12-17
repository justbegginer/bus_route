//
// Created by user.v2.0 on 16.12.2020.
//

#ifndef INDIVIDUAL7_MAIN_HEADERS_H
#define INDIVIDUAL7_MAIN_HEADERS_H
#include "Vector.h"
#include "BusRoute.h"
void parse_string_to_BusRoute(std::string str, Vector<BusRoute> &bus_route);

void sort_BusRoute_by_Time(Vector<BusRoute> &bus_routes);

int min_route_number(Vector<BusRoute> bus_routes);

void make_route_table(Vector<BusRoute> routes);

void check_name_correct(std::string name);

void check_route_number_correct(std::string route_number);

#endif //INDIVIDUAL7_MAIN_HEADERS_H
