#include <iostream>
using namespace std;
#include "battlebot.h"
int main(){
battlebot bee(0, 0, 'N');
battlebot optimus(5, 0, 'S');
bee.setname("bee");
optimus.setname("optimus");
cout << bee;
cout << optimus;
bee.turn('R');
cout << bee;
optimus.turn('R');
cout << optimus;

bee.rightkick(optimus);
cout << bee;
optimus.leftpunch(bee);
cout << optimus;
bee.move();
cout << bee;
optimus.move();
cout << optimus;
bee.move();
cout << bee;
optimus.move();
cout << optimus;
bee.leftpunch(optimus);
cout << bee;
optimus.rightkick(bee);
cout << optimus;
bee.shoot(optimus);
cout << bee;
optimus.shoot(bee);
cout << optimus;
winner(optimus, bee);
}
