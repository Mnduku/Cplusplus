
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;
int main() {

    //Define Constants
     const int MIN = 0;
     const int MAX = 26;
     const int LOWERMIN = 97;
     const int UPPERMIN = 65;
  
    // Define Variables
    string nameoffile;
    int number1, number2, number3, count, currentdeckey ;
    count = 0; 
    char charencrypt;
    char redo = 'Y';     
    char readchar;
    
while(redo == 'Y'){                                                                //loop that lets the program rerun if user wants to decode again  
    //  Program Introduction
    cout << "______________________________________" << endl;
    cout << "Welcome to the FBI spy decoding system" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Enter the name of the file you are trying to decode" << endl;
    cin >> nameoffile ;
    ifstream infile(nameoffile.c_str() ); 
    while(!infile){                                                                //checks if it can enter the file, if not repeats the question
        cout << "File not found. Please input valid file name" << endl;
        cin >> nameoffile ; 
        infile.open(nameoffile.c_str() );
        }
        infile.close();
    cout << "File acessed. Next, input the 3 decryption codes " << endl;
    cout << "\nFirst integer -->  " ;                                              //User inputs number, loops if incorrect
    cin >> number1;         
    while (number1 < MIN ||  number1 > MAX) {
        cout << "Invald number. Please enter digit between 0 and 26 --> ";
        cin >> number1 ;
        cin.ignore(); 
    }
    cout << "\nSecond integer -->  " ;                                             //User inputs number, loops if incorrect
    cin >> number2 ;
    while(number2 < MIN  || number2 > MAX){
        cout << "Invald number. Please enter digit between 0 and 26 --> " ;
        cin >> number2 ;
        cin.ignore();
    } 
    cout << "\nThird integer --> " ;                                                //User inputs number, loops if incorrect
    cin >> number3 ;
    while(number3 < MIN  || number3 > MAX){
        cout << "Invald number. Please enter digit between 0 and 26 --> " ;
        cin >> number3 ;
        cin.ignore();
    }  
    cout << "\nDecrypting message using the numbers " << number1 << ", " << number2 << ", and " << number3 << endl << endl;
    infile.open(nameoffile.c_str() ); 
        while(infile){
            switch(count){                                                          //used to process which encryption key will be appllied
                case 0: currentdeckey = number1;                      
                    break;  
                case 1: currentdeckey = number2;
                    break;
                case 2: currentdeckey = number3;
                    break;  
            }
            infile.get(readchar);                                                  //reads 1 char from the file
            if(isupper(readchar)){                                                 //checks if it is an uppercase letter
                charencrypt = static_cast<int>(readchar);                          //make a second char variable that applies the encrypion and will be used for output
                charencrypt = charencrypt - currentdeckey;  
                    if(static_cast<int>(charencrypt) <  UPPERMIN){
                         charencrypt = static_cast<char>(charencrypt + MAX);       //if the number goes below the minimum, adds 26 to make it wrap around
                         cout << charencrypt; 
                         count = (count+1)%3;                                      // the count modulus rotates encryption key
                    }     
                    else{
                         cout << charencrypt;
                         count = (count+1)%3;
                    } 
            }
            else if(islower(readchar)){                                            //checks if it is lowercase
                 charencrypt = static_cast<int>(readchar);                         //make a second char variable that applies the encrypion and will be used for output
                 charencrypt = charencrypt - currentdeckey;      
                 if(static_cast<int>(charencrypt) < LOWERMIN){
                     charencrypt = static_cast<char>(charencrypt + MAX);           //if the number goes below the minimum, adds 26 to make it wrap around
                     cout << charencrypt;
                     count = (count+1)%3;
                 }  
                 else{
                     cout <<static_cast<char>(charencrypt);
                     count = (count+1)%3;
                 }
            }
            else{                                                                  //if the char is neither uppercase or lowercase it prints it out without applying the key
                 cout << readchar;
                 count = (count+1)%3;
            }                                       
        }  
    cout << "\nWould you like to decrypt another file? Y or N --> " ;
    cin >> redo;
        while(redo != 'N' &&  redo != 'Y'){                                        //Loops program is user chooses Y, ends if user selects N
            cout << "\nInvalid Answer. Please respond with Y or N --> " ;
            cin >> redo; 
        } 
    }
    cout << "\nEncryption program terminated" << endl;
    return(0);                                                                    //terminates program
}      

