using namespace std;
#include <iostream>
#include "date.h"

using namespace std;
const string MONTHS[] {" ","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep",
                       "Oct","Nov","Dec"};
int DaysInMonths[] {0,31,28,31,30,31,30,31,31,30,31,30,31};

int days_from_civil(int y, unsigned m, unsigned d) noexcept
{

    y -= m <= 2;
    const int era = (y >= 0 ? y : y-399) / 400;
    const unsigned yoe = static_cast<unsigned>(y - era * 400);      // [0, 399]
    const unsigned doy = (153*(m > 2 ? m-3 : m+9) + 2)/5 + d-1;  // [0, 365]
    const unsigned doe = yoe * 365 + yoe/4 - yoe/100 + doy;         // [0, 146096]
    return era * 146097 + static_cast<int>(doe) - 719468;
}

void civil_from_days(int z,int & m, int & d, int & y) 
{

    z += 719468;
    const int era = (z >= 0 ? z : z - 146096) / 146097;
    const unsigned doe = static_cast<unsigned>(z - era * 146097);          // [0, 146096]
    const unsigned yoe = (doe - doe/1460 + doe/36524 - doe/146096) / 365;  // [0, 399]
    y = static_cast<int>(yoe) + era * 400;
    const unsigned doy = doe - (365*yoe + yoe/4 - yoe/100);                // [0, 365]
    const unsigned mp = (5*doy + 2)/153;                                   // [0, 11]
    d = doy - (153*mp+2)/5 + 1;                             // [1, 31]
    m = mp < 10 ? mp+3 : mp-9;                            // [1, 12]
    y=y+(m<=2);

}

Date::Date(){ //default constructor
   intdate = days_from_civil(2000,1,1);       //sets time and calls function to get days from 1970
   inttime = 1;
}

Date::Date(const int M, const int d, const int y){ //parametized constructor
   if(days_from_civil(2000,1,1) < 0){
      intdate = days_from_civil(2000,1,1);
   }                                           ////if it was before civil sets to default
   else intdate = days_from_civil(y,M,d);
   inttime = 1;
}

void Date::SetDate(const int M, const int d, const int y){  //setter
   if(days_from_civil(2000,1,1) < 0){
      intdate = days_from_civil(2000,1,1);
   }
                                      //if it was before civil sets to default
   else intdate = days_from_civil(y,M,d);
   inttime = 1;
}

//getter functions that call the civil from days
//function and return the resulting month/day/year respectively

int Date::GetMonth(){ //getter
   int y = 0;
   int m = 0;
   int d = 0;
   civil_from_days(intdate, m, d, y);
   return m;
}

int Date::GetDay(){ //getter
   int y = 0;
   int m = 0;
   int d = 0;
   civil_from_days(intdate, m, d, y);
   return d;
}

int Date::GetYear(){  //getter
   int y = 0;
   int m = 0;
   int d = 0;
   civil_from_days(intdate, m, d, y);
   return y;
}

string & Date::GetShortDate(){
   int y = 0;
   int m = 0;
   int d = 0;                       //Concatenation
   civil_from_days(intdate, m, d, y);
   shortd += to_string(m);
   shortd += "/";
   shortd += to_string(d);
   shortd += "/";
   shortd += to_string(y);
   return shortd;
}

string & Date::GetLongDate(){
   int y = 0;
   int m = 0;
   int d = 0;                     //Concatenation
   civil_from_days(intdate, m, d, y);
   longd += MONTHS[m];
   longd += to_string(d);
   longd += ", ";
   longd += to_string(y);
   return longd;
}

void Date::SetTime(const int h, const int m, const char AMPM){
   int thetime;
   char pm = 'P';
   if(AMPM == pm){
     thetime += 720;        //if in the afternoon adds all the minutes up till the afternoon
   }
   thetime += (h * 60);
   thetime += m;
   inttime = thetime;
}

string & Date::GetTime(){ //getter
   string ampm;
   if (inttime < 720) ampm = "am";       //checks if its am or pm by half the amount of mins in a day
   else ampm = "pm";
   int hour = inttime / 60;        //how many full hours
   if(hour > 12) hour = hour-12;
   int minute = inttime % 60;       //remainder will be the minutes;
   time += to_string(hour);
   time += ":";              //concatentation
   time += to_string(minute);
   time += ampm;
   return time;
}
