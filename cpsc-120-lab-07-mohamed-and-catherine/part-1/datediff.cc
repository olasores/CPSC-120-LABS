// Oyinkansola Olayinka
// CPSC 120-10
// 2022-10-21
// oyinkansola11@csu.fullerton.edu
// @olasores
//
// Lab 07-01
// Partners: @Julianizceja
//
// This program calculates date difference between dates
//

#include <iostream>

int JulianDay(int month, int day, int year) {
  int julian_day = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 +
                   367 * (month - 2 - (month - 14) / 12 * 12) / 12 -
                   3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
  return julian_day;
}

int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {
  int start_julian_day = JulianDay(start_month, start_day, start_year);
  int end_julian_day = JulianDay(end_month, end_day, end_year);
  int date_difference = end_julian_day - start_julian_day;
  return date_difference;
}

void PrintDate(int month, int day, int year) {
  std::cout << month << "/" << day << "/" << year << "\n";
}

int main(int argc, char* argv[]) {
  int start_day = 0;
  int start_month = 0;
  int start_year = 0;
  int end_day = 0;
  int end_month = 0;
  int end_year = 0;
  std::cout << "Enter a start month: \n";
  std::cin >> start_month;
  std::cout << "Enter a start day: \n";
  std::cin >> start_day;
  std::cout << "Enter a start year: \n";
  std::cin >> start_year;
  std::cout << "Enter an end month: \n";
  std::cin >> end_month;
  std::cout << "Enter an end day: \n";
  std::cin >> end_day;
  std::cout << "Enter an end year: \n";
  std::cin >> end_year;
  int d = DateDifference(start_month, start_day, start_year, end_month, end_day,
                         end_year);
  std::cout << "The number of days between " << start_month << "/" << start_day
            << "/" << start_year << " and " << end_month << "/" << end_day
            << "/" << end_year << " is " << d << " days"
            << "\n";
  PrintDate(start_month, start_day, start_year);

  PrintDate(end_month, end_day, end_year);
  return 0;
}
