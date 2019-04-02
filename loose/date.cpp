#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   Date();
   Date(unsigned m, unsigned d, unsigned y);
   Date(const string &mn, unsigned d, unsigned y);
   void printNumeric() const;
   void printAlpha() const;
 private:
   bool isLeap(unsigned y) const;
   unsigned daysPerMonth(unsigned m, unsigned y) const;
   string name(unsigned m) const;
   unsigned number(const string &mn) const;
};

Date getDate();

int main() {

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}

Date::Date(){

   monthName = "January";
   month = 1;
   day = 1;
   year = 2000;

   return;
}

Date::Date(unsigned m, unsigned d, unsigned y){
   bool validDay = true;
   bool validMonth = true; 

   if(m < 1){
      m = 1;
      validMonth = false;
   } else if(m > 12){
      m = 12;
      validMonth = false;
   } 
   unsigned goodDay = daysPerMonth(m, y);

   if(d < 1){
      d = 1;
      validDay = false;
   } else if(d > goodDay){
      d = goodDay;
      validDay = false;
   }
   month = m;
   day = d;
   year = y;
   monthName = name(month);

   if(validDay != true || validMonth != true){
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }

   return;
}

Date::Date(const string &mn, unsigned d, unsigned y){
   bool validDay = true;
   bool validMonth = false;
   unsigned m = number(mn);
   unsigned goodDay = daysPerMonth(number(mn), y);

   vector<string> nameMonths(24);
   nameMonths.at(0) = "January";
   nameMonths.at(1) = "February";
   nameMonths.at(2) = "March";
   nameMonths.at(3) = "April";
   nameMonths.at(4) = "May";
   nameMonths.at(5) = "June";
   nameMonths.at(6) = "July";
   nameMonths.at(7) = "August";
   nameMonths.at(8) = "September";
   nameMonths.at(9) = "October";
   nameMonths.at(10) = "November";
   nameMonths.at(11) = "December";
   nameMonths.at(12) = "january";
   nameMonths.at(13) = "february";
   nameMonths.at(14) = "march";
   nameMonths.at(15) = "april";
   nameMonths.at(16) = "may";
   nameMonths.at(17) = "june";
   nameMonths.at(18) = "july";
   nameMonths.at(19) = "august";
   nameMonths.at(20) = "september";
   nameMonths.at(21) = "october";
   nameMonths.at(22) = "november";
   nameMonths.at(23) = "december";

   for(unsigned int i = 0; i < nameMonths.size(); i++){
      if(mn == nameMonths.at(i)){
         validMonth = true;
      }
   }

   if(d < 1){
      d = 1;
      validDay = false;
   } else if(d > goodDay){
      d = goodDay;
      validDay = false;
   }

   month = m;
   monthName = name(month);
   day = d;
   year = y;

   if(validMonth != true){
      day = 1;
      month = 1;
      monthName = "January";
      year = 2000;
      cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << "." << endl;
   } else if(validDay != true){
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }

   return;
}
void Date::printNumeric() const{
   cout << month << "/" << day << "/" << year;
}
void Date::printAlpha() const{
   cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const{
   if(y % 4 == 0){
      if(y % 400 == 0 || y % 100 != 0){
         return true;
      }
   }
   return false;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
   unsigned daysAllowed;

   if(m % 2 != 0){
      if(m >= 1 && m <= 7){
         daysAllowed = 31;
      } else if(m >= 8 && m <= 12){
         daysAllowed = 30;
      }
   } else if(m % 2 == 0){
      if(m >= 1 && m <= 7){
         daysAllowed = 30;
      } else if(m >= 8 && m <= 12){
         daysAllowed = 31;
      }
   } if(m == 2){
      if(Date::isLeap(y) != false){
         daysAllowed = 29;
      } else{
         daysAllowed = 28;
      }
   }

   return daysAllowed;
}

string Date::name(unsigned m) const{
   string monthName;
   if(m == 1){
      monthName = "January";
   } else if(m == 2){
      monthName = "February";
   } else if(m == 3){
      monthName = "March";
   } else if(m == 4){
      monthName = "April";
   } else if(m == 5){
      monthName = "May";
   } else if(m == 6){
      monthName = "June";
   } else if(m == 7){
      monthName = "July";
   } else if(m == 8){
      monthName = "August";
   } else if(m == 9){
      monthName = "September";
   } else if(m == 10){
      monthName = "October";
   } else if(m == 11){
      monthName = "November";
   } else if(m == 12){
      monthName = "December";
   }

   return monthName;
}

unsigned Date::number(const string &mn) const{
   unsigned month = 1; 

   if(mn == "January" || mn == "january"){
      month = 1;
   } else if(mn == "February" || mn == "february"){
      month = 2;
   } else if(mn == "March" || mn == "march"){
      month = 3;
   } else if(mn == "April" || mn == "april"){
      month = 4;
   } else if(mn == "May" || mn == "may"){
      month = 5;
   } else if(mn == "June" || mn == "june"){
      month = 6;
   } else if(mn == "July" || mn == "july"){
      month = 7;
   } else if(mn == "August" || mn == "august"){
      month = 8;
   } else if(mn == "September" || mn == "september"){
      month = 9;
   } else if(mn == "October" || mn == "october"){
      month = 10;
   } else if(mn == "November" || mn == "november"){
      month = 11;
   } else if(mn == "December" || mn == "december"){
      month = 12;
   }

   return month;
}




