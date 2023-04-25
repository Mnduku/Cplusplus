#include <iostream>
#include <string>
#include "student.h"
using namespace std;
class course{
    public:
        course& operator=(const course& a);
        course();
        ~course();
        char* getname();
        char* getcode();
        char* getlocation();
        student* getroster();
        void printinfo();
        void add(student a);
        void remove(student a);
        void setlocation(char llocation[10]);
        void setcode(char ccode[7]);
        void setname(const char* nname);
        int findbyname(const char* search);
        int findbyid(int id);
        void rem();
        student* roster;
    private:
        char* name;
        int namsize = 10;
        char code[7];
        char location[10];
       // student* roster;
        int maxsize = 2;
        int current = 1;
        void find();
};
