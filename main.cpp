#include <iostream>
#include <fstream>
#include <string>
#include "BusRoute.h"
#include "Time.h"

void parse_string_to_BusRoute(std::string str, BusRoute &bus_route);

void sort_BusRoute_by_Time(BusRoute *bus_routes, int length);

int min_route_number(BusRoute const *bus_routes, int length);

void make_route_table(BusRoute *routes, int length);

int main() {
    std::string file_name;
    std::cout << "enter filename of input file\n";
    //std::cin >> file_name;
    file_name = "/home/raspberry/CLionProjects/individual7/file";
    BusRoute *bus_routes_list;
    int length;
    try {
        std::fstream file(file_name);
        std::string temp;
        getline(file, temp);
        length = std::stoi(temp);
        //std::cout << "good length\n";
        bus_routes_list = new BusRoute[length];
        for (int i = 0; i < length; ++i) {
            getline(file, temp);
            parse_string_to_BusRoute(temp, bus_routes_list[i]);
        }
        file.close();
    }
    catch (std::invalid_argument) {
        std::cout << "invalid value\n";
    }
    catch (...) {
        std::cout << "exception while reading file\n";
    }
    sort_BusRoute_by_Time(bus_routes_list, length);
    for (int i = 0; i < length; ++i) {
        std::cout << *(bus_routes_list + i) << "\n";
    }
    std::cout << "min route number " << min_route_number(bus_routes_list, length) << "\n";
    make_route_table(bus_routes_list, length);
    delete[] bus_routes_list;
    return 0;
}

int min_route_number(BusRoute const *bus_routes, int length) {
    int min_index = 0;
    for (int i = 0; i < length; ++i) {
        if (*(bus_routes + i) < *(bus_routes + min_index)) {
            min_index = i;
        }
    }
    return (bus_routes + min_index)->getRouteNumber();
}

void sort_BusRoute_by_Time(BusRoute *bus_routes, int length) {
    for (int i = 1; i < length; ++i) {
        if ((bus_routes + i - 1)->getArrivingTime() > (bus_routes + i)->getArrivingTime()) {
            //std::cout << bus_routes+i-1;
            BusRoute temp(*(bus_routes + i - 1));
            *(bus_routes + i - 1) = BusRoute(*(bus_routes + i));
            *(bus_routes + i) = BusRoute(temp);
        }
    }
}

void parse_string_to_BusRoute(std::string str, BusRoute &bus_route) {
    std::string string_style_Time;
    std::string name;
    std::string route_number;
    std::string temp;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            if (string_style_Time.empty()) {
                string_style_Time = temp;
            } else {
                name = temp;
            }
            temp = "";
        } else {
            temp += str[i];
        }
    }
    try {
        int route_number_int = std::stoi(temp);
        temp = "";
        int hours, minutes;
        for (int i = 0; i < string_style_Time.size(); ++i) {
            if (string_style_Time[i] == ':') {
                //std::cout << "hours " << temp << '\n';
                hours = std::stoi(temp);
                temp = "";
            } else {
                temp += string_style_Time[i];
            }
        }
        //std::cout<< "minutes" << temp<<"\n";
        minutes = std::stoi(temp);
        Time time(hours, minutes);
        bus_route = BusRoute(route_number_int, name, time);
    }
    catch (std::invalid_argument) {
        std::cout << "error while initialization\n"
                     "invalid argument";
        exit(1);
    }
}

void make_route_table(BusRoute *routes, int length) {
    std::ofstream table_file("/home/raspberry/CLionProjects/individual7/table");
    int max_route_number_digits = 12;
    for (int i = 0; i < length; ++i) {
        if (std::to_string((routes + i)->getRouteNumber()).size() > max_route_number_digits) {
            max_route_number_digits = std::to_string((routes + i)->getRouteNumber()).size();
        }
    }
    int first_colon_size = max_route_number_digits + 1;
    int max_names_length = 16;
    for (int i = 0; i < length; ++i) {
        if ((routes + i)->getDestinationName().size() > max_names_length) {
            max_names_length = (routes + i)->getDestinationName().size();
        }
    }
    int second_colon_size = max_names_length + 1;
    std::string temp = "";
    for (int j = 0; j < first_colon_size + second_colon_size + 5; ++j) {
        temp += "-";
    }
    table_file << temp << "\n";
    temp = "| route number" ;
    for (int j = 0; j < first_colon_size - 12; ++j) {
        temp += " ";
    }
    temp += "| destination name" ;
    for (int j = 0; j < second_colon_size - 16; ++j) {
        temp += " ";
    }
    temp += "|";
    table_file << temp << "\n";
    for (int i = 0; i < length; ++i) {
        std::string temp = "";
        for (int j = 0; j < first_colon_size + second_colon_size + 5; ++j) {
            temp += "-";
        }
        table_file << temp << "\n";
        temp = "| " + std::to_string((routes + i)->getRouteNumber());
        for (int j = 0; j < first_colon_size - std::to_string((routes + i)->getRouteNumber()).size(); ++j) {
            temp += " ";
        }
        temp += "| " + (routes + i)->getDestinationName();
        for (int j = 0; j < second_colon_size - (routes + i)->getDestinationName().size(); ++j) {
            temp += " ";
        }
        temp += "|";
        table_file << temp << "\n";
    }
    for (int j = 0; j < first_colon_size + second_colon_size + 5; ++j) {
        table_file << "-";
    }
    table_file << "\n";
}