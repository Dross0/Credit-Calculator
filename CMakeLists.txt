cmake_minimum_required(VERSION 3.15)
project(CreditCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(money main.cpp ICredit.h Credit.cpp Credit.h CreditCsvWriter.cpp CreditCsvWriter.h Date.cpp Date.h)