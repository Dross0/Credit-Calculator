//
// Created by Андрей Гайдамака on 10.11.2019.
//

#include "Credit.h"
#include <cmath>

Credit::Credit(uint sum, double percent, uint months, Credit_type type, Date credit_date) : sum_(sum), percent_(percent * 0.01),
months_(months), type_(type), credit_date_(credit_date)
{}

double Credit::get_month_pay(uint month) const {
    double month_pay = 0;
    if (type_ == Credit_type::ANNUITY){
        month_pay = annuity_month_pay();
    }
    else if (type_ == Credit_type::DIFFERENTIATED){
        month_pay = differentiated_month_pay(month);
    }
    return month_pay;
}

double Credit::get_all_sum() const {
    double result = 0;
    if (type_ == Credit_type::ANNUITY){
        result = annuity_month_pay() * months_;
    }
    else if (type_ == Credit_type::DIFFERENTIATED){
        for (uint i = 1; i <= months_; ++i){
            result += differentiated_month_pay(i);
        }
    }
    return result;
}

double Credit::differentiated_month_pay(const uint month) const {
    double base = static_cast<double>(sum_) / months_;
    double Sn = base + (sum_ - (base * (month - 1))) * (percent_ / 12);
    return Sn;
}

double Credit::annuity_month_pay() const {
    double month_percent = percent_ / 12;
    double tmp = pow(month_percent + 1, months_);
    double k = (month_percent * tmp) / (tmp - 1);
    return sum_ * k;
}

uint Credit::get_sum() const{
    return sum_;
}

double Credit::get_percent() const{
    return percent_;
}

uint Credit::get_months() const{
    return months_;
}

Credit_type Credit::get_type() const{
    return type_;
}

Date Credit::get_date() const {
    return credit_date_;
}

std::vector<std::pair<double, double>> Credit::get_list_of_payments() const{
    std::vector<std::pair<double, double>> list_of_payments;
    std::pair<double, double> payment = {0, 0};
    double last_sum = sum_;
    double month_percent = percent_ / 12;
    double month_pay = get_month_pay();
    double main_part = 0;
    double percent_part = 0;
    for (uint i = 0; i < months_; ++i){
        if (type_ == Credit_type::ANNUITY) {
            percent_part = last_sum * month_percent;
            main_part = month_pay - percent_part;
            last_sum -= main_part;
        }
        else if (type_ == Credit_type::DIFFERENTIATED){
            month_pay = get_month_pay(i + 1);
            percent_part = month_pay - static_cast<double>(sum_) / months_;
            main_part = static_cast<double>(sum_) / months_;
        }
        payment = {main_part, percent_part};
        list_of_payments.push_back(payment);
    }
    return list_of_payments;
}