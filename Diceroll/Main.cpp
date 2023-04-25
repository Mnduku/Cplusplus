#include "Dice.h"
#include <iostream>
bool goagain();

int main(){
   bool keeprun = true;
   while( keeprun == true){            //will keep repeating dice throw until user says otherwise;
      Dice begin;
      begin.setdice();
      begin.roll();
      keeprun = goagain();
   }

   return 0;
}

bool goagain(){
   cout << "Would you like to go again? (Y/N)" ;
   char c;
   cin >> c;
   while(c != 'y' && c != 'Y' && c != 'n' && c != 'N'){
      cout << "Please answer Y or N -->" << endl;
      cin >> c;
   }
   cout << "\n";
   if(c == 'n' || c == 'N') return false;
   else return true;
}
