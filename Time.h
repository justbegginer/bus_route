//
// Created by raspberry on 20.11.2020.
//
#include <iostream>

#pragma once
#ifndef INDIVIDUAL7_TIME_H
#define INDIVIDUAL7_TIME_H

#endif //INDIVIDUAL7_TIME_H

class Time {
private:
    int _minutes;
    int _hours;

    bool is_correct_time() const;

    void rebuild_time();

public:
    Time();

    Time(int hours, int minutes);

    Time(Time const &time);

    int getMinutes() const;

    int getHours() const;

    void setMinutes(int minutes);

    void setHours(int hours);

    bool operator<(const Time &rhs) const;

    bool operator>(const Time &rhs) const;

    bool operator<=(const Time &rhs) const;

    bool operator>=(const Time &rhs) const;

    bool operator==(const Time &rhs) const;

    bool operator!=(const Time &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Time &time);

    friend std::istream &operator>>(std::istream &os, Time &time);

    Time &operator=(const Time &time);

    friend Time &operator+(const Time &left, const Time &right);

    Time &operator-(const Time &right);
};