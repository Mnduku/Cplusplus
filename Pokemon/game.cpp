
#include<iostream>
#include<cstdlib>
#include "map.h"
using namespace std;
//=============================================
void move(map& a, player& b);
char checkvalid(char a);
int checkvalid2(int a);
void battle(map& a, player& b);
void enemyattack(player& a, enemy*& b , int c);
void physattack(player& a, enemy*& b , int c);
void spattack(player& a, enemy*& b , int c);
bool battleend(player& a, enemy*& b , int& c);
bool selectpoke(player& a, int& c);
//=============================================
int main(){
    map pokeworld(10);
    cout << pokeworld << endl;
    cout << "\nWELCOME TO POKEWORLD! DEFEAT ALL ENEMIES AND COLLECT ALL LOOT TO WIN";
    cout << "\nNAME YOUR CHARACTER --> ";
    string name;
    cin >> name;
    player p(name);
    p.setstart(pokeworld.getx(), pokeworld.gety());
    bool play = true;
    while(play == true){
        move(pokeworld, p);
        pokeworld.updateplayer(p);
        cout << pokeworld;
    }
    cout << "\n\n\nCongragulations! you beat the game!";
//    cout << "\nYou collected a total of " << p.inventory[0]->count ;
    int dz;
    cin >> dz;
    return(0);
}
void move(map& a, player& b){
    cout << endl;
    cout << "---Choose an option, " << b.getname() << "---";
    cout << "\n Press W then enter to move UP";
    cout << "\n Press A then enter to move LEFT";
    cout << "\n Press S then enter to move DOWN";
    cout << "\n Press D then enter to move RIGHT";
    cout << endl;
    char choice;
//    cin.clear();
    cin.ignore(100, '\n');
    cin.get(choice);
    choice = toupper(choice);
    checkvalid(choice);
//    cin.clear();
  //  cin.ignore();
    switch(choice){
        case 'W':
        {
           char** temp = a.getstate();
           if(temp[b.getx() - 1][b.gety()] == 'T'){
               cout << "\n You found a coin!" ;
               b.inventory[0]->editcount(1);
           }
           else if(temp[b.getx() - 1][b.gety()] == 'M'){
               cout << "Monster has been encountered!" ;          //detects if you approached an M after each 
                                                                  //movement in any direction
                battle(a, b);
           }
           b.moveup();
           cout << "\n" << b.getname() << " has moved up " ;
           cout << endl << endl;
           return;
           break;
        }
        case 'D':
        {
           char** temp = a.getstate();
           if(temp[b.getx()][b.gety()+1] == 'T'){
               cout << "\n You found a coin!" ;
               b.inventory[0]->editcount(1);
           }
           else if(temp[b.getx()][b.gety()+1] == 'M'){
               cout << "Monster has been encountered!" ;
               battle(a, b);
           }
           b.moveright();
           cout << "\n" << b.getname() << " has moved right " ;
           cout << endl << endl;
           return;
           break;
        }
        case 'S':
        {
           char** temp = a.getstate();
           if(temp[b.getx() + 1][b.gety()] == 'T'){
               cout << "\n You found a coin !!" ;
               b.inventory[0]->editcount(1);
           }
           else if(temp[b.getx() + 1][b.gety()] == 'M'){
               cout << "Monster has been encountered!" ;
               battle(a, b);
           }
           b.movedown();
           cout << "\n" << b.getname() << " has moved down " ;
           cout << endl << endl;
           return;
           break;
        }
        case 'A':
        {
           char** temp = a.getstate();
           if(temp[b.getx()][b.gety() - 1] == 'T'){
                cout << "\n You found a coin!" ;
                b.inventory[0]->editcount(1);
           }
           else if(temp[b.getx()][b.gety() - 1] == 'M'){
                cout << "Monster has been encountered!" ;
                battle(a, b);
           }
           b.moveleft();
           cout << "\n" << b.getname() << " has moved left " ;
           cout << endl << endl;
           return;
           break;
        }
    }
}
char checkvalid(char a){
    while(a != 'W' && a != 'A' && a != 'S' && a != 'D'){
        cout << "\nPlease enter either W A S D --> " ;
        cin >> a;                             //checks input validity
        cin.ignore(10, '\n');
        a = toupper(a);
    }
    return a;
}
void battle(map& a, player& b){
    srand(time(0));
    int encounter = rand() % 2;
    enemy* c;
    if(encounter == 0){                  //randomly encountered pokemon
       c = new smallenemy;
       cout << "\nYou have encountered a "<<  c->getname() << " (" << c->getheal() << "HP)";
    }
    else if(encounter == 1){
        c = new bigenemy;
        cout << "\nYou have encountered a "<< c->getname() << " (" << c->getheal() << "HP)";
    }
    enemy** pokemon = b.getpokes();
    cout << "\n" << b.getname() << ": Go, " << pokemon[0]->getname() << "!"  ;
    int pokechoice = 0;
    bool keeprun = true;
    while(keeprun == true){
       cout << "\n\n----Choose an option----";
       cout << "\nEnter 1 to run";
       cout << "\nEnter 2 to use physical attack";
       cout << "\nEnter 3 to use special attack";
       cout << "\nEnter 4 to wait" ;
       cout << "\n";
       cout << "\nYour pokemon:";
       for(int i = 0; i < b.getpokesize(); i++){
           cout << "\n" << pokemon[i]->getname() << " (" << pokemon[i]->getheal() << "HP)" << endl;
       }
       int choice;
       cin >> choice;
       checkvalid2(choice);
       switch(choice){
           case 1:
           {
              cout << "\n" << b.getname() << " ran!";
              keeprun = false;
              break;
           }
           case 2:                                //battle options, keeprun used to detect if enemy or player dies
           {
              physattack(b, c, pokechoice);
              keeprun = battleend(b, c, choice);
              if(keeprun == false){
                  break;
              }
              enemyattack(b, c, pokechoice);
              keeprun = battleend(b, c, choice);
              if(keeprun == false){
                  break;
              }
              break;
           }
           case 3:
           {
              spattack(b, c, pokechoice);
         //     keeprun = battleend(b, c, choice);
              if(keeprun == false){
                  break;
              }
              enemyattack(b, c, pokechoice);
         //     keeprun = battleend(b, c, choice);
              if(keeprun == false){
                  break;
              }
              break;
           }
           case 4:
           {
          //    keeprun = battleend(b, c, choice);
              if(keeprun == false){
                  break;
              }
              cout << "\n" << b.getname() << "waits patiently and does nothing!";
              enemyattack(b, c, pokechoice);
              keeprun = battleend(b, c, choice);
              if(keeprun == false){
                  break;
              }
              break;
           }
       }
   }
}
int checkvalid2(int a){
    while(a != 1 && a != 2 && a != 3 && a != 4){
        cout << "\nChoose a valid option";
        cin >> a;
    }
    return a;
}
void enemyattack(player& a, enemy*& b, int c){
   int attacktype;
   attacktype = rand() % 5;
   if(attacktype == 3){
      b->spattack(a.pokes[c]);
   }
   else{
      b->attack(a.pokes[c]);
   }
}
void physattack(player& a, enemy*& b, int c){;
   a.pokes[c]->attack(b);
}
void spattack(player& a, enemy*& b, int c){
   a.pokes[c]->spattack(b);
}
bool battleend(player& a, enemy*& b , int& c){
   if(a.pokes[c]->getheal() <=  0){
      cout << "\nYour " << a.pokes[c]->getname() << " has been defeated";
      cout << "\nPlease choose another pokemon to fight";
      bool keeprun = selectpoke(a, c);
      if(keeprun == true){
          return true;
      }
      else if(keeprun == false){
          return false;
          //EXIT PROGRAM HERE/
      }
   }
   if(b->getheal() <= 0){                            //detects if enemy is dead, sends true or false which ends 
       cout << "\nEnemy has been defeated! ";        //or continues the battle loop
       return false;
   }
   return true;
}
bool selectpoke(player& a, int& c){
    int totalhealth;
    for(int i = 0; i < a.getpokesize(); i++){                    //called if the players starting pokemon dies
        totalhealth += a.pokes[i]->getheal();
    }
    if(totalhealth <= 0){
        cout << "\nAll your pokemon have died! Game over. ";
        return false;
    }
    cout << "\nSelect a pokemon to fight";
       for(int i = 0; i < a.getpokesize(); i++){
           cout << "\n" << i <<": " << a.pokes[i]->getname() << " (" << a.pokes[i]->getheal() << "HP)" << endl;
       }
    int selection;
    cin >> selection;
    if(selection > a.getpokesize() || selection < 0){
        cout << "\nChoose a valid pokemon ->";
        cin >> selection;
    }
    if(a.pokes[selection]->getheal() <= 0){
        cout << "\nThis pokemon is dead! Select another ->";
        cin >> selection;
    }
    c = selection;
    cout << "\n" << a.getname() << ": Go, " << a.pokes[c]->getname() << " !";
    return true;
}
