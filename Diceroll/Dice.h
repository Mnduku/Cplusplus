//#include "Dice.cpp"
#include <iostream>
#include <ostream>
using namespace std;

class Dice{

   public:
      Dice();
      void roll();
      void print(int d);
      void setdice();
      int getsum();

   private:
      int amount;
      int sum;
};







