
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
    if (!is_correct_time()) {
        throw std::invalid_argument("but values of time");
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
    return (_hours >= 0 && _hours <= 24) && (_minutes >= 0 && _minutes < 60);
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
    os << time._hours << ":";
    if (time._minutes / 10 == 0) {
        os << "0";
    }
    os << time._minutes;
    return os;
}

Time &Time::operator=(const Time &time) {
    _hours = time._hours;
    _minutes = time._minutes;
    return *this;
}


std::istream &operator>>(std::istream &os, Time &time) {
    os >> time._hours >> time._minutes;
    return os;
}

Time &operator+(const Time &left, const Time &right) {
    Time new_time = Time();
    new_time._hours = left._hours + right._hours;
    new_time._minutes = left._minutes + right._minutes;
    new_time.rebuild_time();
    return new_time;
}

Time &Time::operator-(const Time &right) {
    Time new_time = Time();
    new_time._hours = (*this)._hours - right._hours;
    new_time._minutes = (*this)._minutes - right._minutes;
    new_time.rebuild_time();
    return new_time;
}

void Time::rebuild_time() {
    if (this->_minutes >= 60) {
        this->_hours++;
        this->_minutes -= 60;
    }
    if (this->_minutes < 0) {
        this->_minutes = 60 + this->_minutes;
        _hours--;
    }
    if (this->_hours >= 24) {
        this->_hours -= 24;
    }
    if (this->_hours < 0) {
        this->_hours = 24 - this->_hours;
    }
}


