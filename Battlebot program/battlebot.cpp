

#include <iostream>
#include <cmath>
using namespace std;
#include "battlebot.h"

roboleg::roboleg(){
    position = 'U'; // u is under, f is forward, b is behind for leg positions
    israised = false;
}
void battlebot::setname(string h){            // i added this to make the output less confusing
    name = h;
}
void roboleg::liftleg(){
    israised = true;
    cout << "The robot is raising its leg! " << endl;
    position = 'F';
}
void roboleg::swing(){
    if(israised = true){
        cout << "The robot is swinging its leg" << endl;
        position = 'B';
    }
    else cout << "Leg must be raised to swing" << endl;
}
void roboleg::lowerleg(){   // i am assuming this function is the opposite of raise leg and  returns a raised leg back to  normal
    israised = false;
    position = 'U';
}
void roboleg::step(){
    liftleg();
    lowerleg();
    cout << "The robot has taken a step " << endl;
}
void roboleg::kick(){
    liftleg();
    swing();
}
roboarm::roboarm(){
}
void roboarm::punch(){
    drawback();
    thrust();
    if(isthrust = false){
        cout << " Punch failed" << endl;                          //if the arm is not thrusting the punch will not initiate
        return;
    }
    isthrust = false;
}
void roboarm::drawback(){
    isdrawnback = true;
    cout << "The robot is drawing back its arm" << endl;
}
void roboarm::thrust(){
    if(isdrawnback = false){
        cout <<"arm cannot be thrust until drawn back" << endl;
        isthrust = false;
    }
    else if(isdrawnback = true){
        cout << "The robot is thrusting its arm" << endl;
        isdrawnback = false;
        isthrust = true;
}
}
projlaunch::projlaunch(){
    isloaded = false;
}
void projlaunch::load(){
    isloaded = true;
}
void projlaunch::fire(){
    if(isloaded = true){
        isloaded = false;
    }
    else if(isloaded = false){
        cout << "Must be loaded first to fire" << endl;
      return;
    }
}
bool projlaunch::checkloaded(){
    if(isloaded = true){
        return(true);
    }
    else return(false);
}
battlebot::battlebot(){
    health = 100;
    x = 0;
    y = 0;
    direction = 'N';
}
battlebot::battlebot(float xx, float yy, char direc){
    direction = direc;
    health = 100;
    x = xx;
    y = yy;
}
void battlebot::move(){
    rightleg.step();
    leftleg.step();
    switch(direction){
        case 'N' : y++;                //adds to the x or y coordinate depending on the direction the move is going towards
           break;
        case 'S' : y--;
           break;
        case 'E' : x++;
           break;
        case 'W' : x--;
           break;
        default:  cout << "Cannot move without direction" << endl;
        cout << " The robot has taken a step " << direction << endl;
}
}
void battlebot::turn(char d){
    char turn = d;
    int degrees;
    switch(direction){
        case 'N' : degrees = 2;
            break;
        case 'S' : degrees = 4;             //i turned the direction into an integer and made it 1-4, i used the modulus operator so that it loops around from 1-4 back to 1 since theres no set direction for 5
            break;
        case 'E' : degrees = 1;
            break;
        case 'W' : degrees = 3;
            break;
}
    if(turn == 'L'){
        degrees = (degrees + 1) % 4;
        cout << name << " has turned 90 degrees counterclockwise" << endl;
    }
    else if(turn == 'R'){
        degrees = (degrees - 1) % 4;
        cout << name << " has turned 90 degrees clockwise" << endl; 
    }
    switch(degrees){
        case 1 : direction = 'E';
            break;
        case 2 : direction = 'N';
            break;
        case 3 : direction = 'W';
            break;
        case 4 : direction = 'S';
            break;
}
}
int battlebot::dist(battlebot c){   //this function will return the distance between battle bot, uses distance formula
    return(sqrt(pow(c.x - x, 2) + pow(c.y - y, 2) * 1.0));
}
void battlebot::rightpunch(battlebot& a){
    right.punch();
    int distance = dist(a);
    int didhit =detecthit(a);
    if(didhit = 1){
        if(distance = 2){
             hit(3, a);
             cout << name << " lands a right punch dealing 3 damage !" << endl;
        }
        else if(distance == 1 || distance == 0){                                      //calls detecthit to see if the attack hits, if it does it then detecrts the bots distance
             hit(5, a);
             cout << name << "lands a right punch dealing 5 damage !" << endl;
        }
        else cout << name << " landed a right punch but missed !" << endl;
    }
    else cout << "Attack missed! " << name << " is not facing the right direction" << endl;
}
void battlebot::leftpunch(battlebot& a){
    left.punch();
    int distance = dist(a);
    int didhit =detecthit(a);
    if(didhit = 1){
       if(distance == 2){
          hit(3, a);
          cout << name << " lands a left punch dealing 3 damage !" << endl;
       }
       else if(distance == 1 || distance == 0){
          hit(5, a);
           cout << name << " lands a left punch dealing 5 damage !" << endl;
       }
       else cout << name << " landed a left punch but missed !" << endl;
    }
    else cout << "Attack missed! " << name << " is not facing the right direction" << endl;
}
void battlebot::leftkick(battlebot& a){
    int distance = dist(a);
    int didhit =detecthit(a);
    leftleg.kick();
    if(didhit = 1){
        if(distance == 1 || distance == 0){
            hit(3, a);
            cout << name << " lands a left kick dealing 3 damage !" << endl;
        }
        else cout << name << " landed a left kick but missed !" << endl;
    }
    else cout << "Attack missed! " << name << " is not facing the right direction" << endl;
}
void battlebot::rightkick(battlebot& a){
    int distance = dist(a);
    int didhit =detecthit(a);
    rightleg.kick();
    if(didhit = 1){
        if(distance == 1 || distance == 0){
            hit(3, a);
            cout << name << " lands a right kick dealing 3 damage !" << endl;
        }
        else cout << name << " landed a right kick but missed !" << endl;
    }
    else cout << "Attack missed! " << name << " is not facing the right direction" << endl;
}
void battlebot::shoot(battlebot& a){
    launcher.fire();
    int distance = dist(a);
    int didhit =detecthit(a);
    if(didhit = 1){
        switch(distance){
            case 3:
                hit(3, a);
                cout << name << "fires and hits the other robot for 3 damage! " << endl;
                break;
            case 2:
                hit(4, a);
                cout << name << " fires and hits the other robot for 4 damage! " << endl; //every time an attack is sucessful the hit function is called which lowers the targeted bots health
                break;
            case 1:
                 hit(5, a);
                 cout << name << " fires and hits the other robot for 5 damage! " << endl;
                break;
            case 0:
                 hit(10, a);
                 cout << name << " fires and hits the other robot for 10 damage! " << endl;
                break;
            default: cout << name << " fires, but the attack misses! Target bot is too far." << endl;
         }
     }
     else cout << name << " fires, but the attack misses, robot is not facing the right direction! "<< endl;
}
int battlebot::detecthit(battlebot b){
    int var1, var2;
    var1 = getx() - b.getx();
    var2 = gety() - b.gety();
    if( getx() == b.getx() || gety() == b.gety()){
       if(var1 > 0){
           if(direction = 'W'){
               return(1);
           }
           else return(2);
       }
       else if(var1 < 0){
           if(direction = 'E'){
               return(1);
           }
           else return(2);
       }
       else if(var2 > 0){              // logic determening if an attack will hit or not. Finds the differences between x and y variables and then decides if the robot is facing the right direction to reach the target coordinates. returns 1 for a hit and 2 for a miss
           if(direction = 'S'){
               return(1);
           }
           else return(2);
       }
       else if(var2 < 0){
           if(direction = 'N'){
               return(1);
           }
           else return(2);
       }
    }
    else return(1);
    return(1);

}
int battlebot::gethealth(){
    return(health);
}
void battlebot::hit(int d, battlebot& b){
    int loss = b.health  - d;
    b.health = loss;
}
float battlebot::getx(){
    return(x);
}
float battlebot::gety(){
    return(y);
}
ostream& operator<<(ostream& z, battlebot a){
    z << a.name << " has " << a.health << " health remaining, and is located at (" << a.getx() << "," << a.gety() << ") facing "<< a.direction << endl;
    return(z);
}
void winner(battlebot& a, battlebot& b){
    if(a.health > b.health){
        cout << "The winner is " << a.name << endl;
        cout << a.name << " has " << a.health << " health remaining, and is located at (" << a.getx() << "," << a.gety() << ")" << endl;
    }
    else if (a.health < b.health){
        cout << "The winner is "<< b.name << endl;
        cout << b.name << " has " << b.health << " health remaining, and is located at (" << b.getx() << "," << b.gety() << ")" << endl;
    }
}
