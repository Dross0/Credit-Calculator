#include <iostream>
#include <cassert>
#include "Credit.h"
#include "CreditCsvWriter.h"

Credit get_user_input(){
    int sum = 0;
    std::cout << "Введите сумму кредита: ";
    std::cin >> sum;
    assert(sum >= 0);
    double percent = 0;
    std::cout << "Введите процентную ставку: ";
    std::cin >> percent;
    assert(percent >= 0);
    int months = 0;
    std::cout << "Введите количество месяцев: ";
    std::cin >> months;
    assert(months > 0);
    int t = 0;
    std::cout << "Введите тип платежей (1.Аннуитентный 2.Дифференцированный): ";
    std::cin >> t;
    assert(t == 2 || t == 1);
    Credit_type type = (t == 1) ? Credit_type::ANNUITY : Credit_type::DIFFERENTIATED;
    int month = 0;
    std::cout << "Введите номер месяца взятия кредита: ";
    std::cin >> month;
    assert(month > 0 && month < 13);
    int year = 0;
    std::cout << "Введите год взятия кредита: ";
    std::cin >> year;
    assert(year > 0);
    return Credit(sum, percent, months, type, Date(month, year));
}

int main() {
    Credit c = get_user_input();
    CreditCsvWriter cw("out.csv");
    cw.write(c);
    return 0;
}