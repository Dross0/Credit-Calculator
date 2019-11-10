//
// Created by Андрей Гайдамака on 10.11.2019.
//

#include "Date.h"

Date::Date(unsigned int month, unsigned int year) : month_(month - 1), year_(year)
{
    year_ += (month_ / 12) ? month_ / 12 : 0;
    month_ %= 12;
}

void Date::add_month(const unsigned int inc) {
    month_ += inc;
    year_ += (month_ / 12) ? month_ / 12 : 0;
    month_ %= 12;
}

void Date::add_year(const unsigned int inc) {
    year_ += inc;
}

unsigned int Date::get_year() const {
    return year_;
}

unsigned int Date::get_month() const {
    return month_ + 1;
}

std::string Date::get_month_name() const {
    const char * MONTHS[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                                "Июль",  "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    return MONTHS[month_];
}