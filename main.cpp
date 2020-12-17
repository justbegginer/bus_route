#include <iostream>
#include <fstream>
#include <string>
#include "Time.h"
#include "main_headers.h"


int main() {
    std::string file_name;
    std::cout << "enter filename of input file\n";
    std::cin >> file_name;
    file_name = "C:\\Users\\user.v2.0\\CLionProjects\\bus_route\\" + file_name;
    Vector<BusRoute> bus_routes_list = Vector<BusRoute>();
    std::fstream file(file_name);
    std::string temp;
    for (int i = 0; i < 10; ++i) {
        getline(file, temp);
        if (temp == "")
            break;
        parse_string_to_BusRoute(temp, bus_routes_list);
    }
    for (int i = 0; i < bus_routes_list.size(); ++i) {
        for (int j = i + 1; j < bus_routes_list.size(); ++j) {
            if (bus_routes_list[i].getRouteNumber() == bus_routes_list[j].getRouteNumber())
                throw std::invalid_argument("route_number repeats");
        }
    }
    file.close();
    sort_BusRoute_by_Time(bus_routes_list);
    std::fstream sorted("C:\\Users\\user.v2.0\\CLionProjects\\bus_route\\sorted");
    for (int i = 0; i < bus_routes_list.size(); ++i) {
        sorted << bus_routes_list[i] << "\n";
    }
    std::cout << "min route number " << min_route_number(bus_routes_list) << "\n";
    make_route_table(bus_routes_list);
    return 0;
}

int min_route_number(Vector<BusRoute> bus_routes) {
    int min_index = 0;
    for (int i = 0; i < bus_routes.size(); ++i) {
        if (bus_routes[i] < bus_routes[min_index]) {
            min_index = i;
        }
    }
    return bus_routes[min_index].getRouteNumber();
}

void sort_BusRoute_by_Time(Vector<BusRoute> &bus_routes) {
    for (int i = 0; i < bus_routes.size() - 1; ++i) {
        Time min(bus_routes[i].getArrivingTime());
        int index_of_min = i + 1;
        bool change = false;
        for (int j = i + 1; j < bus_routes.size(); ++j) {
            if (min > bus_routes[j].getArrivingTime()) {
                min = bus_routes[j].getArrivingTime();
                index_of_min = j;
                change = true;
            }
        }
        if (change) {
            BusRoute temp(bus_routes[index_of_min]);
            bus_routes[index_of_min] = bus_routes[i];
            bus_routes[i] = temp;

        }
    }
}

void parse_string_to_BusRoute(std::string str, Vector<BusRoute> &bus_routes) {
    std::string string_style_Time = "";
    std::string name = "";
    std::string route_number = "";
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
    std::cout << route_number;
    if (temp.empty() || name.empty() || string_style_Time.empty())
        throw std::invalid_argument("missed argument");
    check_name_correct(name);
    check_route_number_correct(temp);
        int route_number_int = std::stoi(temp);
        temp = "";
        int hours, minutes;
        for (int i = 0; i < string_style_Time.size(); ++i) {
            if (string_style_Time[i] == ':') {
                hours = std::stoi(temp);
                temp = "";
            } else {
                temp += string_style_Time[i];
            }
        }
        minutes = std::stoi(temp);
        Time time(hours, minutes);
        BusRoute new_bus_route = BusRoute(route_number_int, name, time);
        bus_routes.push(new_bus_route);

}

void make_route_table(Vector<BusRoute> routes) {
    std::ofstream table_file(R"(C:\Users\user.v2.0\CLionProjects\bus_route\table.txt)");
    int max_route_number_digits = 12;
    for (int i = 0; i < routes.size(); ++i) {
        if (std::to_string((routes[i]).getRouteNumber()).size() > max_route_number_digits) {
            max_route_number_digits = std::to_string((routes[i]).getRouteNumber()).size();
        }
    }
    int first_colon_size = max_route_number_digits + 1;
    int max_names_length = 16;
    for (int i = 0; i < routes.size(); ++i) {
        if ((routes[i]).getDestinationName().size() > max_names_length) {
            max_names_length = (routes[i]).getDestinationName().size();
        }
    }
    int second_colon_size = max_names_length + 1;
    std::string temp = "";
    for (int j = 0; j < first_colon_size + second_colon_size + 5; ++j) {
        temp += "-";
    }
    table_file << temp << "\n";
    temp = "| route number";
    for (int j = 0; j < first_colon_size - 12; ++j) {
        temp += " ";
    }
    temp += "| destination name";
    for (int j = 0; j < second_colon_size - 16; ++j) {
        temp += " ";
    }
    temp += "|";
    table_file << temp << "\n";
    for (int i = 0; i < routes.size(); ++i) {
        std::string temp = "";
        for (int j = 0; j < first_colon_size + second_colon_size + 5; ++j) {
            temp += "-";
        }
        table_file << temp << "\n";
        temp = "| " + std::to_string((routes[i]).getRouteNumber());
        for (int j = 0; j < first_colon_size - std::to_string((routes[i]).getRouteNumber()).size(); ++j) {
            temp += " ";
        }
        temp += "| " + (routes[i]).getDestinationName();
        for (int j = 0; j < second_colon_size - (routes[i]).getDestinationName().size(); ++j) {
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

void check_name_correct(std::string name) {
    if (name[0] == '-' || name[name.size() - 1] == '-')
        throw std::invalid_argument("incorrect name");
    for (int i = 0; i < name.size(); ++i) {
        if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == '-'))
            continue;
        else
            throw std::invalid_argument("incorrect name");
    }
}

void check_route_number_correct(std::string route_number) {
    try {
        std::stoi(route_number);
    }
    catch (...) {
        throw std::invalid_argument("route number is not a number");
    }
    if (std::stoi(route_number) < 1 || std::stoi(route_number) > 250) {
        throw std::invalid_argument("invalid route number ");
    }
}