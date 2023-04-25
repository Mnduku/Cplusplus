#include <ctime>
#include "Dice.h"
using namespace std;

Dice::Dice()
{                                     //default const
   amount = 0;
   sum = 0;
}

void Dice::roll()
{                                     //rolls dice
   for(int i = 0; i < amount; i++)
   {
      int v = (rand() % 6) + 1;
          //gens number 1-6
      print(v);                       //prints a dice based on the random number
      sum = sum + v;                       //adds the total of the roll to the total sum
      cout << "TESTING ADDED V " << v << endl;
   }
   cout << "The total throw for this dice is " << sum << endl;
}

void Dice::print(int number)
{                                     //prints dice

  for(int i = 0; i < 8; i++){
     cout << "_" ;
  }
  cout << endl;
  switch(number){                      //switch statement to determine which print to use
      case 1:
         cout << "|";
         for(int i = 0; i < 6; i++){
           cout << " " ;
         }
         cout << "|" << endl;
         cout << "|";
         for(int i = 0; i < 3; i++){
           cout << " " ;
         }
         cout << "O";
         for(int i = 0; i < 2; i++){
           cout << " " ;
         }
         cout << "|" << "  1" << endl;
         cout << "|";
         for(int i = 0; i < 6; i++){
           cout << " " ;
         }
         cout << "|" << endl;
         for(int i = 0; i < 8; i++){
            cout << "_" ;
         }
         cout << endl;
      break;
      case 2:
         cout << "|";
         cout << "O";
         for(int i = 0; i < 5; i++){
           cout << " " ;
         }
         cout << "|" << endl;
         cout << "|";
         for(int i = 0; i < 6; i++){
           cout << " " ;
         }
         cout << "|" << "  2" << endl;
         cout << "|";
         for(int i = 0; i < 5; i++){
           cout << " " ;
         }
         cout << "O";
         cout << "|" << endl;
         for(int i = 0; i < 8; i++){
            cout << "_" ;
         }
         cout << endl;
      break;
      case 3:
         cout << "|";
         cout << "O";
         for(int i = 0; i < 5; i++){
           cout << " " ;
         }
         cout << "|" << endl;
         cout << "|";
         for(int i = 0; i < 3; i++){
           cout << " " ;
         }
         cout << "O";
         for(int i = 0; i < 2; i++){
           cout << " " ;
         }
         cout << "|" << "  3" << endl;
         cout << "|";
         for(int i = 0; i < 5; i++){
           cout << " " ;
         }
         cout << "O";
         cout << "|" << endl;
         for(int i = 0; i < 8; i++){
            cout << "_" ;
         }
         cout << endl;
      break;
      case 4:
         cout << "|";
         cout << "O";
         for(int i = 0; i < 4; i++){
           cout << " " ;
         }
         cout << "O";
         cout << "|" << endl;
         cout << "|";
         for(int i = 0; i < 6; i++){
           cout << " " ;
         }
         cout << "|" << "  4" << endl;
         cout << "|" << "O";
         for(int i = 0; i < 4; i++){
           cout << " " ;
         }
         cout << "O";
         cout << "|" << endl;
         for(int i = 0; i < 8; i++){
            cout << "_" ;
         }
         cout << endl;
      break;
      case 5:
         cout << "|";
         cout << "O";
         for(int i = 0; i < 4; i++){
           cout << " " ;
         }
         cout << "O";
         cout << "|" << endl;
         cout << "|";
         for(int i = 0; i < 3; i++){
           cout << " " ;
         }
         cout << "O";
         for(int i = 0; i < 2; i++){
           cout << " " ;
         }
         cout << "|" << "  5" << endl;
         cout << "|" << "O";
         for(int i = 0; i < 4; i++){
           cout << " " ;
         }
         cout << "O";
         cout << "|" << endl;
         for(int i = 0; i < 8; i++){
            cout << "_" ;
         }
         cout << endl;
      break;
      case 6:
         cout << "|";
         cout << "O";
         for(int i = 0; i < 4; i++){
           cout << " " ;
         }
         cout << "O";
         cout << "|" << endl;
         cout << "|";
         cout << "O";
         for(int i = 0; i < 4; i++){
           cout << " " ;
         }
         cout << "O";
         cout << "|" << "  6" << endl;
         cout << "|" << "O";
         for(int i = 0; i < 4; i++){
           cout << " " ;
         }
         cout << "O";
         cout << "|" << endl;
         for(int i = 0; i < 8; i++){
            cout << "_" ;
         }
         cout << endl;
      break;
      }
}

void Dice::setdice(){
   cout << "Enter the number of dice you want to be thrown between 2 and 7" << endl;
   int d;                             //choose how many dice will be thrown
   cin >> d;

   while( d < 2 || d > 7)
   {
     cout << "Please choose a number between 2 and 7" << endl;
     cin >> d;                       //will keep asking for input if number not 2-7
   }
   amount = d;
}

int Dice::getsum(){                   //returns the total sum for the throws
  return sum;
}
