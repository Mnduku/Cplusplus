#include <cctype>
#include <iostream>
#include "courselist.h"
#include <cstring>
#include <string>
using namespace std;
courselist::courselist(){
    courses = new course[maxsize];
}
courselist::~courselist(){
//    delete [] courses;
}
void courselist::findcourse(){
    cout << current;
    cout << courses[0].getname();
    cout << "\niuhefwihufff" << endl;
    char searchtype;
    int found = 0;
    cin.ignore(100, '\n');
    cout << "Do you want to search by name, location, or code? enter n for name, c for code, and l for location ---> " ;
        cin.get(searchtype);
        searchtype = toupper(searchtype);
        cin.ignore(100, '\n');
        while(searchtype != 'N' && searchtype != 'C' && searchtype != 'L'){
            cout << "\nPlease enter a valid command" ;
            cin.get(searchtype);
            searchtype = toupper(searchtype);
            cin.ignore(100, '\n');
        }
    switch(searchtype){
        case 'N': found = searchbyname();
            if(found != 500){
                courses[found].printinfo();
            }
            else;
            break;
        case 'C': found = searchbyl();
            if(found != 500){
                courses[found].printinfo();
            }
            else;
            break;
        case 'L': found = searchbycode();
            if(found != 500){
                courses[found].printinfo();
            }
            else;
            break;
    }
}
int courselist::searchbyl(){
    char search[10];
    cout << "\nPlease enter the location of the course ---> " ;
    cin.get(search, 10);
    cin.ignore(100, '\n');
    for(int i = 0; i < maxsize; i++){
        if(search == courses[i].getlocation()){
            cout << "\nCourse found!! " << endl << endl;
            int found = i;
            return(found);
         }
    }
    cout << "\nfailed: course with given location could not be found" << endl << endl ;
    return(500);
}
int courselist::searchbycode(){
    char search[10];
    cout << "\nPlease enter the code of the course ---> " ;
    cin.get(search,10);
    cin.ignore(100, '\n');
    for(int i = 0; i < maxsize; i++){
        if(search == courses[i].getcode()){
            cout << "Course found!! " << endl << endl;
            int found = i;
            return(found);
         }
    }
    cout << "\nSearch failed: course with given id not be found" << endl << endl ;
    return(500);
}
int courselist::searchbyname(){
    char search[100];
    cout << "\nPlease enter the name of the course ---> " ;
    cin.get(search,100);
    cin.ignore(100, '\n');
    for(int i = 0; i < maxsize; i++){
        if(search == courses[i].getname()){
            cout << "\nCourse found!!" << endl << endl ;
            int found = i;
            return(found);
         }
    }
    cout << "\nfailed: course with given name could not be found" << endl << endl;
    return(500);
}
ostream& operator<<(ostream& z, courselist x){
    for(int i = 0; i < x.getcurrent(); i++){
       x.courses[i].printinfo();
    }
    return(z);
}
void courselist::addcourse(){
      course a;
      setcourseinfo(a);
      course* temp = new course[maxsize+1];
      for(int i = 0; i <  maxsize; i++){
          temp[i] = courses[i];
      }
      temp[current] = a;
      current++;
      maxsize++;
      delete [] courses;
      courses = temp;
      cout << endl << endl << courses[current-1].getname() << "  has been added to the list! " << endl;
}
void courselist::setcourseinfo(course& a){
    cout << "\nWhat is the name of the course? --> " ;
    char* name;
    name = new char[10];
    cin >> name;
    a.setname(name);
    cin.ignore();
    cout << "\nWhat is the course code? --> " ;
    char code[7];
    cin.get(code, 7);
    a.setcode(code);
    cin.ignore();
    cout << "\nWhat is the courses location? --> " ;
    char location[10];
    cin.get(location, 10);
    a.setlocation(location);
    cin.ignore();
}
void courselist::addstudent(){
    cout << "\nWhich course do you want to add a student to?--> ";
    char search[100];
    cin >> search;
    cin.ignore(100,'\n');
    for(int i = 0; i < maxsize; i++){
        if(strcmp(search, courses[i].getname()) == 0){
            cout << "\nCourse found, enter the info for the student whom you are adding " ;
            student newstudent;
            newstudent.setinfo();
            int found = i;
            courses[i].add(newstudent);
            return;
         }
    }
    cout << "\nSearch failed: course with given name could not be found" ;
}
void courselist::removecourse(){
    cin.ignore(100, '\n');
    char* course;
    course = new char[100];
    cout << "\nWhat course are you trying to remove" ;
    cin.get(course, 100);
    int remove = 500;
    int found = 0;
    for(int i = 0; i < maxsize; i++){
        if(strcmp(course, courses[i].getname()) == 0){
            remove = i;
        }
    }
    if(remove = 500){
        cout << "Course you want to be removed cannot be found";
        return;
    }
    for (int j = remove + 1; j < maxsize; j++){
        courses[j - 1] = courses[j];
    }
    maxsize--;
    cout << "\nCourse Sucessfully removed from list";
}
void courselist::findstudent(){
    cout << "\nWould you like to search for a student by name or id, N for name D for Id ---> ";
    char search;
    cin.get(search);
    search = toupper(search);
    while(search != 'N' && search != 'D'){
        cout << "\nPlease enter either N or D ---> ";
        cin.get(search);
        search = toupper(search);
    }
    if(search == 'N'){
        int found = 500;
        char* entry;
        entry = new char[100];
        cin.ignore(200, '\n');
        cout << "\nEnter the name of the student you are searching for --> " ;
        cin.get(entry, 100);
        cin.ignore(100, '\n');
        for(int i = 0; i < maxsize; i++){
           found = courses[i].findbyname(entry);
           if(found != 500){
               int coursefound = i;
               cout << "\nStudent found, they are in " << courses[i].getname() ;
               cout << "\nStudent info: " ;
               student* newroster = new student[100];
               newroster =  courses[i].getroster();
               newroster[found].printinfo();
               cin.ignore(100, '\n');
               cin.clear();
               return;
           }
           else cout << "\n could not find student" ;
        }
    }
    else if (search == 'D'){
        int entry = 0;
        int found = 500;
        cout << "\nEnter the id you are searching for --> " ;
        cin >> entry;
        cin.ignore(100, '\n');
        for(int i = 0; i < maxsize; i++){
           found = courses[i].findbyid(entry);
           if(found != 500){
               int coursefound = i;
               cout << "\nStudent found, they are in " << courses[i].getname() ;
               cout << "\n Student info: " ;
               student* newroster = new student[100];
               newroster =  courses[i].getroster();
               newroster[found].printinfo();
               cin.ignore(100, '\n');
               cin.clear();
               return;
           }
        }
    }
    cout << "\n could not find student" ;
    cout << "\nSearch failed!!" ;
    return;
}
void courselist::upstudent(){
     cin.ignore(100, '\n');
     char* entry;
     int found = 500;
     entry = new char[100];
     cout << "\nEnter the name of the student you want to update --> " ;
     cin.get(entry, 100);
     cin.ignore(100, '\n');
     for(int i = 0; i < maxsize; i++){
         found = courses[i].findbyname(entry);
         if(found != 500){
             cout << "\nStudent found, enter the new information" << endl;
             courses[i].roster[found].setinfo();
             courses[i].roster[found].printinfo();
             return;
         }
         else cout << "\nStudent to be updated not found" << endl;
     }
}
void courselist::upcourse(){
    cin.ignore(100, '\n');
    cout << "What course are you trying to update" << endl;
    char* course;
    course = new  char[100];
    cin.get(course, 100);
    int found = 0;
    for(int i = 0; i < maxsize; i++){
        if(strcmp(course, courses[i].getname()) == 0){
            setcourseinfo(courses[found]);
            cin.ignore(100, '\n');
            cout << "\nUpdated information: " << endl;
            courses[found].printinfo();
            return;
         }
    }
    cout << "\nCourse to be updated not found";
}
int courselist::getmax(){
    return(maxsize);
}
int courselist::getcurrent(){
    return(current);
}

