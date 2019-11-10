//
// Created by Андрей Гайдамака on 10.11.2019.
//

#ifndef MONEY_ICREDIT_H
#define MONEY_ICREDIT_H


class ICredit {
public:
    virtual double get_all_sum() const = 0;
    virtual double get_month_pay(unsigned int month) const = 0;
    virtual ~ICredit() = default;
};


#endif //MONEY_ICREDIT_H
