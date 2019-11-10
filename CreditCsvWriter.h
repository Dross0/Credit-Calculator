//
// Created by Андрей Гайдамака on 10.11.2019.
//

#ifndef MONEY_CREDITCSVWRITER_H
#define MONEY_CREDITCSVWRITER_H
#include <fstream>
#include <string>
#include "Credit.h"

class CreditCsvWriter {
public:
    explicit CreditCsvWriter(const std::string & path = "out.csv");

    ~CreditCsvWriter();

    void write(const Credit & credit);
private:
    std::ofstream csv_file_;
};


#endif //MONEY_CREDITCSVWRITER_H
