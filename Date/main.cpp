#include <iostream>
#include <string>
#include "date.h" 
using namespace std; 

int main(void)
{  Date  MyDate1;
   Date  MyDate2(2,18,2012); 
   cout <<MyDate1.GetMonth()<<endl; 
   cout <<MyDate1.GetDay()<<endl; 
   cout <<MyDate1.GetYear()<<endl;
   cout <<MyDate2.GetLongDate()<<endl; 
   cout <<MyDate2.GetShortDate()<<endl;  
   MyDate2.SetTime(5,30,'P'); 
   cout<< MyDate2.GetTime()<<endl; 
   MyDate1.SetTime(5,30,'A'); 
   cout <<MyDate1.GetTime()<<endl;
   int z;
   cin >> z;
   return 0; 
} 
