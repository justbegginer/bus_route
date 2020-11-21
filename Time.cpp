
//
// Created by raspberry on 20.11.2020.
//

#include "Time.h"


Time::Time() {
    _minutes = 0;
    _hours = 9;
}

Time::Time(int hours, int minutes) {
    _hours = hours;
    _minutes = minutes;
    if (!is_correct_time()){
        std::cout <<"time ish't correct\n"
                    "auto time generation :\n"
                    "hours = 9\n"
                    "minutes = 0\n";
        _hours = 9;
        _minutes = 0;
    }
}

Time::Time(const Time &time) {
    _hours = time.getHours();
    _minutes = time.getMinutes();
}

int Time::getMinutes() const {
    return _minutes;
}

int Time::getHours() const {
    return _hours;
}

void Time::setMinutes(int minutes) {
    _minutes = minutes;
}

void Time::setHours(int hours) {
    _hours = hours;
}

bool Time::is_correct_time() const {
    return (_hours >= 0 && _hours <= 24) && (_minutes>=0 && _minutes < 60);
}

bool Time::operator<(const Time &rhs) const {
    return (_hours < rhs._hours || (_hours == rhs._hours && _minutes < rhs._minutes));
}

bool Time::operator>(const Time &rhs) const {
    return (_hours > rhs._hours || (_hours == rhs._hours && _minutes > rhs._minutes));
}

bool Time::operator<=(const Time &rhs) const {
    return (rhs < *this || rhs == *this);
}

bool Time::operator>=(const Time &rhs) const {
    return !(*this > rhs || rhs == *this);
}

bool Time::operator==(const Time &rhs) const {
    return _minutes == rhs._minutes &&
           _hours == rhs._hours;
}

bool Time::operator!=(const Time &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Time &time) {
    os <<  time._hours << ":" << time._minutes;
    return os;
}

Time &Time::operator=(const Time &time) {
    _hours = time._hours;
    _minutes = time._minutes;
    return *this;
}
