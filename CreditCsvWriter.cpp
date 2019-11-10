//
// Created by Андрей Гайдамака on 10.11.2019.
//

#include "CreditCsvWriter.h"

CreditCsvWriter::CreditCsvWriter(const std::string &path) {
    csv_file_.open(path);
    if (!csv_file_.is_open()){
        throw std::runtime_error("Cant open " + path);
    }
}

CreditCsvWriter::~CreditCsvWriter() {
    csv_file_.close();
}

void CreditCsvWriter::write(const Credit & credit) {
    csv_file_.setf(std::ios_base::fixed);
    uint sum = credit.get_sum();
    Credit_type type = credit.get_type();
    uint months = credit.get_months();
    std::vector<std::pair<double, double>> list_of_payments = credit.get_list_of_payments();
    Date date = credit.get_date();
    csv_file_ << "Номер платежа, Дата платежа,Сумма платежа, Основной долг, Начисленные проценты, Остаток задолженности" << std::endl;
    double month_pay = credit.get_month_pay();
    double last_sum = sum;
    for (uint i = 0; i < months; ++i){
        month_pay = (type == Credit_type::ANNUITY) ? month_pay : credit.get_month_pay(i+1);
        last_sum -= list_of_payments[i].first;
        last_sum = (last_sum < 0.00001) ? 0 : last_sum;
        csv_file_ << std::setprecision(2) <<i + 1 << "," << date.get_month_name() << " " << date.get_year() << "," << month_pay << ","
                << list_of_payments[i].first << "," << list_of_payments[i].second << "," << last_sum << std::endl;
        date.add_month();
    }
    double all_sum = credit.get_all_sum();
    csv_file_ << std::setprecision(2) <<", " << "Итог:, " << all_sum << "," << sum << "," << all_sum - sum << std::endl;
}