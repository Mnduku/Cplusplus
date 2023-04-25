#include <iostream>
#include <string>
using namespace std;
class student{
    public:
        student();
        ~student();
        student(const char* major_,const char* name_);
        char* getname();
        char* getmajor();
        char getclass();
        int getid();
        void printinfo();
        void setinfo();
        void setname(const char* nname);
        void setid(const int iid);
        void setclass(const char cclass);
        void setmajor(const char* mmajor);
    private:
        char classification;
        int id;
        char* major;
        char* name;
        int max = 10;
};




