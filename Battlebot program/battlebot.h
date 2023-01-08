#include <iostream>
#include <string>
using namespace  std;

class roboleg{
    public:
       roboleg();
       void step();
       void kick();
    private:
        void liftleg();
        void swing();
        void lowerleg();
        bool israised;
         char position;
};
class roboarm{
    public:
        roboarm();
        void punch();
    private:
        void drawback();
        void thrust();
        bool isdrawnback;
        bool isthrust;
};
class projlaunch{
    public:
        projlaunch();
        void load();
        void fire();
    private:
        bool checkloaded();
        bool isloaded;
};
class battlebot{
       friend ostream& operator<<(ostream& z, battlebot a);
       friend void winner(battlebot& a, battlebot& b);
    public:
        battlebot();
        battlebot(float xx, float yy, char direc);
        void move();
        void turn(char d);
        void hit(int d, battlebot& b);
        void rightpunch(battlebot& a);
        void rightkick(battlebot& a);
        void leftkick(battlebot& a);
        void leftpunch(battlebot& a);
        void shoot(battlebot& a);
        int detecthit(battlebot b);
        int gethealth();
        int getdirec();
        float getx();
        void setname(string h);
        float gety();
    private:
        int dist(battlebot c); // function used to calculate distance between bots
        roboarm left, right;
        roboleg leftleg, rightleg;
        projlaunch launcher;
        float x, y;
        string name;
        char direction;
        int health;

};
