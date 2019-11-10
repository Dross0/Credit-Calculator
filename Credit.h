//
// Created by Андрей Гайдамака on 10.11.2019.
//

#ifndef MONEY_CREDIT_H
#define MONEY_CREDIT_H
#include "ICredit.h"
#include "Date.h"
#include <vector>

using uint = unsigned int;

enum class Credit_type: uint{
    ANNUITY,
    DIFFERENTIATED
};

class Credit : public ICredit{
public:
    Credit(uint sum, double percent, uint months, Credit_type type, Date credit_date);

    ~Credit() = default;

    double get_all_sum() const;

    double get_month_pay(uint month = 1) const;

    uint get_sum() const;

    double get_percent() const;

    uint get_months() const;

    Credit_type get_type() const;

    Date get_date() const;

    std::vector<std::pair<double, double>> get_list_of_payments() const;


private:
    uint sum_;
    double percent_;
    uint months_;
    Credit_type type_;
    Date credit_date_;

    double annuity_month_pay() const;
    double differentiated_month_pay(uint month) const;
};


#endif //MONEY_CREDIT_H
