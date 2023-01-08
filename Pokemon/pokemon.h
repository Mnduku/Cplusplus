#include <iostream>
#include <string>
using namespace std;
class enemy{
    public:
        virtual string getype() = 0;
        virtual string getname() = 0;
        virtual int getheal() = 0;
        enemy();
        virtual void takedmg(int a) = 0;
        virtual void attack(enemy*& a) = 0;
        virtual void spattack(enemy*& a) = 0;
    private:
    protected:
};

class bigenemy: public enemy {
    public:
        string getype();
        void spattack(enemy*& a);
        void attack(enemy*& a);
        bigenemy();
        string getname();
        int getheal();
        void takedmg(int a);
    private:
        string name;
        string type;
        int health;
};

class smallenemy: public enemy {
    public:
        string getype();
        void attack(enemy*& a);
        void spattack(enemy*& a);
        smallenemy();
        string getname();
        int getheal();
        void takedmg(int a);
    private:
        string name;
        string type;
        int health;
};
class item{
   public:
      virtual void editcount(int edit) = 0;
      virtual string getname() = 0;
      item();
   private:
};
class coin: public item {
    public:
       string getname();
       coin();
       void editcount(int edit);
       int count;
    private:
       string name;
};
class player{
    public:
         player(string name_);
         ~player();
         enemy** getpokes();
         string getname();
         int getpokesize();
         int getx();
         int gety();
         enemy *pokes[6];
         void setstart(int _x, int _y);
         void moveleft();
         void moveright();
         void moveup();
         void movedown();
         void editcoincount(int edit);
         void editpotioncount(int edit);
         item *inventory[2];            //other possible items can be stored in the list if i were to add to the program 
    private:
         int pokesize;
         string name;
         int x;
         int y;
};
