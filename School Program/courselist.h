#include <cctype>
#include <iostream>
#include "course.h"
#include <cstring>
#include <string>
using namespace std;
class courselist{
        friend ostream& operator<<(ostream& z, courselist x);
    public:
        ~courselist();
        void createinfo();
        courselist();
        int getmax();
        int getcurrent();
        void addcourse();
        void addstudent();
        void removecourse();
        void findcourse();
        void findstudent();
        void upstudent();
        void upcourse();
        void setcourseinfo(course& a);
        int searchbyl();
        int searchbycode();
        int searchbyname();
    private:
        course* courses;
        int maxsize = 2;
        int current = 0;
};
