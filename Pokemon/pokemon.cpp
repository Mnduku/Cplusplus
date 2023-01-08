#include <iostream>
#include <cstring>
#include "pokemon.h"
player::player(string _name){
    pokesize = 3;
    name = _name;
    inventory[0] = new coin;         //since coin is the only treasure i am implementingg
    srand(time(0));
    int poke1;
    int poke2;
    int poke3;
    poke1 = rand() % 2;                 //used to randomly generate enemies
    poke2 = rand() % 2;
    poke3 = rand() % 2;
    switch(poke1){
       case 0:
          {
          pokes[0] = new smallenemy;
          break;
          }
       case 1:
          {
          pokes[0] = new bigenemy;
          break;
          }
    }
    switch(poke2){
       case 0:
          {
          pokes[1] = new smallenemy;
          break;
          }
       case 1:
          {
          pokes[1] = new bigenemy;
          break;
          }
    }
    switch(poke3){
       case 0:
          {
          pokes[2] = new smallenemy;
          break;
          }
       case 1:
          {
          pokes[2] = new bigenemy;
          break;
          }
    }
}
player::~player(){
    for(int i = 0; i < 6; i++){
       delete [] pokes[i];
    }
}
void player::setstart(int _x, int _y){
    x = _x;
    y = _y;
}
void player::moveleft(){                 //functions for player movement
    if(y - 1 < 1){
       return;
    }
    y--;
}
void player::moveright(){
    if(y + 1 == 9){
       return;
    }
    y++;
}
void player::moveup(){
    if(x - 1 < 1){
       return;
    }
    x--;
}
void player::movedown(){
    if(x + 1 == 9){
       return;
    }
    x++;
}
string player::getname(){
    return name;
}
int player::getx(){
   return x;
}
int player::gety(){
   return y;
}
enemy** player::getpokes(){
   return pokes;
}
bigenemy::bigenemy(){                            //sets the enemies name based on a string of 2 identifying letters
    type = "B";
    health = 120;
  //  srand(time(0));
    int ttype= rand() % 3;
    switch(ttype){
        case 0: type += "F";
           break;
        case 1: type += "G";
           break;
        case 2: type += "W";
           break;
    }
    if(type == "BG"){
        name = "Venesaur";
    }
    else if(type == "BF"){
        name = "Charizard";
    }
    else if(type == "BW"){
        name = "Blastoise";
    }
    else if(type == "SF"){
        name = "Charmander";
    }
    else if(type == "SG"){
        name = "Bulbasaur";
    }
    else if(type == "SW"){
        name = "Squirtle";
    }
}
smallenemy::smallenemy(){
    type = "S";
    health = 80;
//    srand(time(0));
    int ttype= rand() % 3;
    switch(ttype){
        case 0: type += "F";
           break;
        case 1: type += "G";
           break;
        case 2: type += "W";
           break;
    }
    if(type == "BG"){
        name = "Venesaur";
    }
    else if(type == "BF"){
        name = "Charizard";
    }
    else if(type == "BW"){
        name = "Blastoise";
    }
    else if(type == "SF"){
        name = "Charmander";
    }
    else if(type == "SG"){
        name = "Bulbasaur";
    }
    else if(type == "SW"){
        name = "Squirtle";
    }
}
enemy::enemy(){
}
string smallenemy::getname(){
   return name;
}
string bigenemy::getname(){
   return name;
}
int smallenemy::getheal(){
   return health;
}
int bigenemy::getheal(){
   return health;
}
void bigenemy::takedmg(int dmg){
    health -= dmg;
}
void smallenemy::takedmg(int dmg){
    health -= dmg;
}
void smallenemy::attack(enemy*& a){
    cout << "\n" << name << " (" << health << "hp) attacked and did 5 damage!";
    a->takedmg(5);
}
void bigenemy::attack(enemy*& a){
    cout << "\n" << name <<  " (" << health << "hp) attacked and did 20 damage!";
    a->takedmg(20);
}
void bigenemy::spattack(enemy*& a){
    string typee = a->getype();
    cout << "\n" << name << " (" << health << "hp) is using a special attack!" ;
    if(type == "BG"){
       cout << "\n" << name << " used LEAF TORNADO !";
       if(typee == "SW" || typee == "BW"){                       //damage effect typing
           cout << "\n It's super effective!";
           a->takedmg(180);
       }
       else a->takedmg(90);
    }
    else if(type == "BW"){
       cout << "\n" << name << " used HYDRO CANNON !";
       if(typee == "SF" || typee == "BF"){
          cout << "\n It's super effective!";
          a->takedmg(160);
       }
       else a->takedmg(80);
    }
    else if(type == "BF"){
       cout << "\n" << name << " used OVERHEAT !";
       if(typee == "SG" || typee == "BG"){
          cout << "\n It's super effective!";
          a->takedmg(220);
       }
       else
       a->takedmg(110);
    }
}
void smallenemy::spattack(enemy*& a){
    string typee = a->getype();
    cout << "\n" << name << " (" << health << "hp) is using a special attack!" ;
    if(type == "SG"){
       cout << "\n" << name << " used GRASS KNOT !";
       if(typee == "SW" || typee == "BW"){
           cout << "\n It's super effective!";
           a->takedmg(90);
       }
       else a->takedmg(45);
    }
    else if(type == "SW"){
       cout << "\n" << name << " used AQUA PULSE !";
       if(typee == "SF" || typee == "BF"){
          cout << "\n It's super effective!";
          a->takedmg(110);
       }
       else a->takedmg(55);
    }
    else if(type == "SF"){
       cout << "\n" << name << " used EMBER !";
       if(typee == "SG" || typee == "BG"){
          cout << "\n It's super effective!";
          a->takedmg(120);
       }
       else a->takedmg(60);
    }
}
string bigenemy::getype(){
   return type;
}
string smallenemy::getype(){
   return type;
}
coin::coin(){
    count = 0;
    name = "Pokecoin" ;
}
item::item(){
}
string coin::getname(){
   return name;
}
void coin::editcount(int edit){
    count += edit;
}
void player::editcoincount(int edit){
    (*inventory[0]).editcount(edit);
}
void player::editpotioncount(int edit){ 
    (*inventory[0]).editcount(edit); //never implemented this but i had it there just in case I felt the need to
}
int player::getpokesize(){
   return pokesize;
}
