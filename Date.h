//
// Created by Андрей Гайдамака on 10.11.2019.
//

#ifndef MONEY_DATE_H
#define MONEY_DATE_H
#include <string>

class Date {
public:
    Date(unsigned int month, unsigned int year);

    void add_month(unsigned int inc = 1);

    void add_year(unsigned int inc = 1);

    unsigned int get_month() const;

    unsigned int get_year() const;

    std::string get_month_name() const;
private:
    unsigned int month_;
    unsigned int year_;
};


#endif //MONEY_DATE_H
