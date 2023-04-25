#include <iostream>
#include <cstring>
#include "course.h"
using namespace std;
course::course(){
name = new char[namsize];
roster = new student[maxsize];
}
course::~course(){
    delete [] name;
    delete [] roster;
}
void course::add(student a){
    if(current < maxsize){
        roster[current] = a;
        current++;
        cout << "Student has been added to roster" << endl;
    }
    else if(current == maxsize){
        maxsize += 10;
        student* newroster = new student[maxsize];
        for(int i = 0; i < current; i++){
            newroster[i] = roster[i];
        }
        newroster[current] = a;
        current++;
        delete[] roster;
        roster = newroster;
        cout << "Student has been added to " << name << endl;
    }
}
void course::remove(student a){
    int remove = 666;
    for(int  i = 0; i < maxsize; i++){
        if(a.getname() == roster[i].getname()){
            remove = i;
        }
    }
    if(remove == 666){
        cout << "Student you requested to be removed was not found" << endl;
        return;
    }
    for (int j = remove + 1; j < maxsize; j++){
        roster[j - 1] = roster[j];
    }
    maxsize--;
    cout << "Student has been successfully removed from " << name << endl;
}
void course::setlocation(char llocation[10]){
    int i =0;
    int size = strlen(llocation);
    while(i <= size){
        location[i] = llocation[i];
        i++;
    }
}
void course::setcode(char ccode[7]){
    int i =0;
    int size = strlen(ccode);
    while(i <= size){
        code[i] = ccode[i];
        i++;
    }
}
char* course::getname(){
    return(name);
}
char* course::getcode(){
    return(code);
}
char* course::getlocation(){
    return(location);
}
void course::setname(const char* nname){
    int size = 0;
        while(nname[size] != '\0'){
            size++;
        }
        if(size + 1 > namsize){
            delete[] name;
            name = new char[size+1];
        }
        for(int i = 0; i < size + 1; i++){
            name[i] = nname[i];
        }
        name[size + 1] = '\0';
}
int course::findbyname(const char* search){
    for(int i = 0; i < maxsize; i++){
         if(strcmp(search, roster[i].getname()) == 0){
             int found = i;
             return(found);
         }
    }
    return(500);
}
int course::findbyid(int search){
    for(int i = 0; i < maxsize; i++){
        if(search == roster[i].getid()){
            int found = i;
            return(found);
         }
    }
    return(500);
}
void course::printinfo(){
    cout << "Name of course: " << name << endl;
    cout << "Course code: " << code << endl;
    cout << "Course Location: " << location << endl;
    if(current = 0){
        return;
    }
    for(int i = 0; i < current; i++){
        roster[i].printinfo();
    }
}
student* course::getroster(){
    return(roster);
}
course& course::operator=(const course& a){
        delete [] name;
        delete [] roster;
	int size = 0;
	while(a.name[size] != '\0'){
		size++;
        }
	size++;
	name = new char[size];
	for(int i = 0; i < size; i++) {
		name[i] = a.name[i];
        }
        roster = new student[a.maxsize];
        for(int i = 0; i < a.maxsize; i++) {
                roster[i] = a.roster[i];
        }
        int size2 = 0;
        while(a.code[size2] != '\0'){
                size2++;
        }
        size2++;
        for(int i = 0; i < size2; i++) {
                code[i] = a.code[i];
        }
        int size3 = 0;
        while(a.location[size3] != '\0'){
                size3++;
        }
        size3++;
        for(int i = 0; i < size3; i++) {
               location[i] = a.location[i];
        }
        int maxsize = a.maxsize;
        int current = a.current;
	return *this;
}
