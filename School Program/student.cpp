#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;
student::student(){
major = new char[max];
name = new char[max];
}
student::~student(){
    delete [] major;
    delete [] name;
}
void student::setinfo(){
     char* nname;
     nname = new char[100];
     char* mmajor;
     mmajor = new char[100];
     int idd;
     char classi;
     cout << "\nEnter the name of the student ---> ";
     cin.get(name,100);
     setname(nname);
     cin.ignore();
     cout << "\nEnter the id of the student ---> ";
     cin >> idd;
     setid(idd);
     cin.ignore();
     cout << "\nEnter the major of the student ---> ";
     cin.get(mmajor, 100);
     setmajor(mmajor);
     cin.ignore();
     cout << "\nEnter the classification of the student ---> ";
     cin.get(classi);
     setclass(classi);
     cin.ignore();
     cout << "\nInformation set successfullu" << endl << endl;
}
void student::printinfo(){
     cout << "\nStudent name: " << name;
     cout << "\nStudent major: " << major;
     cout << "\nStudent id" << id;
     cout << "\nStudent classification: " << classification;
}
void student::setname(const char* nname){
    int size = 0;
    while(nname[size] != '\0'){
        size++;
    }
    if(size + 1 > max){
        delete[] name;
        name = new char[size+1];
    }
    for(int i = 0; i < size + 1; i++){
        name[i] = nname[i];
    }
    name[size + 1] = '\0';
}
void student::setmajor(const char* mmajor){
    int size = 0;
    while(mmajor[size] != '\0'){
        size++;
    }
    if(size + 1 > max){
        delete[] major;
        major = new char[size+1];
    }
    for(int i = 0; i < size + 1; i++){
        major[i] = mmajor[i];
    }
    major[size + 1] = '\0';
}
void student::setid(const int iid){
    id = iid;
}
void student::setclass(const char cclass){
    classification = cclass;
}
char* student::getname(){
    return(name);
}
int student::getid(){
    return(id);
}
char* student::getmajor(){
    return(major);
}
char student::getclass(){
    return(classification);
}
