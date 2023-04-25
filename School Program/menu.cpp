#include <cctype>
#include <iostream>
#include "courselist.h"
#include <cstring>
#include <string>
using namespace std;
//================
void Menu(char&);;
//=======================
int main(){
    bool keeprun = true;
    courselist fsu;
    while(keeprun == true){
    char selection;
    Menu(selection);
    switch(selection){
        case 'I': fsu.addstudent();
           break;
        case 'A': fsu.addcourse();
           break;
        case 'L': fsu.findcourse();
           break;
        case 'Y': fsu.findstudent();
           break;
        case 'R': fsu.removecourse();
           break;
        case 'U': fsu.upcourse();
           break;
        case 'S': fsu.upstudent();
           break;
        case 'D': cout << fsu;
           break;
        case 'Q': keeprun = false;
           break;
    }
    }
    return(0);
}
void Menu(char& selection){
   cout << "\n\n\t\t>>> FSU CLASS ENROLLMENT <<<";
   cout << "\n\tA \tAdd a new course to a the list";
   cout << "\n\tI \tAdd a new student into a class";
   cout << "\n\tL \tLook up a class";
   cout << "\n\tY \tLook up a student";
   cout << "\n\tR \tRemove a class from the list";
   cout << "\n\tU \tUpdate a classes info";
   cout << "\n\tS \tUpdate a students info";
   cout << "\n\tD \tDisplay all class and student info";
   cout << "\n\tQ \tQuit" << endl << endl;
   cout << "\nChoose an option --> " << endl << endl;
   cin.get(selection);
   selection = toupper(selection);
  // cin.ignore(100, '\n');
   while(selection  != 'A' && selection  != 'I' &&  selection != 'L' && selection != 'Y' && selection != 'R' && selection != 'U' && selection != 'S' && selection != 'D' && selection != 'Q'){
      cout << "\nPlease enter a valid command" << endl;
      cin.get(selection);
      selection = toupper(selection);
  //    cin.ignore(100, '\n');
   }
   return;
}
