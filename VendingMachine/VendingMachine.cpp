#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <cstdlib>
using namespace std;
//==============================
const double PAYMENT = 1.00;                                   // The amount of money that needs to be put in
const double PROFIT = 0.25;                                    // Profit per can
const int DRINKS = 6;                                          // Amount of drinks the machine can hold
struct info                                                    // Struct that holds machine data
{
    string name;
    double price;
    int amount;
};
typedef info vending[DRINKS];                                  //Array of structs
//==============================
void endput(vending&);                                         //Sorts the drinks 
void getdata(vending&);                                        //Gets the drink data from file
void print(vending);                                           //Prints the machine state
//==============================
int main(){
    int drink, soldcans;                                       //variables for drink chosen and amount of cans sold
    double change, profit;                                     //Variables for change due and profit made
    string payment;                                            //Used to toggle wether or not program still runs
    vending vending;                                           //Declaring the array
    getdata(vending);                                          //calls getdata to get machine data
    print(vending);                                            //calls to print machine state
    string switc = "Yes";                                      //String that controls program loop
    while(switc == "Yes"){
        cout << "Do you want to buy a drink? Yes or No -->" ;  //Asks if user wants to order, if not ends program. in a loop
        cin >> switc;
        while(switc != "Yes" && switc != "No"){
            cout << "\nPlease answer with Yes or No -->" ;
            cin.clear();
            cin >> switc;
        } 
        if(switc == "No"){
            break;
        }
        cout << "Please Select the number of the drink you want to order. Select 6 to cancel ---->"; //user chooses drink, 6 is to cancel.
        cin >> drink;                                                                                //loops if invalid selection
        if(drink == 6){
                cout << "\nHave a nice day";
                break;
            }
        while(drink > 6 || drink < 0){
            cout << "Invalid selection. Please Select a drink. Select 6 to cancel -->";
            cin >> drink;
            if(drink == 6){
                cout << "\nHave a nice day";
                break;
            }
        }
        while(vending[drink].amount <= 0){
            cout << "This drink is sold out! Please make another selection. Select 6 to cancel -->"; //Makes the user reselect if the drink is sold out
            cin.clear();
            cin >> drink;
            if(drink == 6){
                cout << "\nHave a nice day";
                break;
            }

        }   
        cout << "\nA payment of 1.00 is required. Type in OK to accept this payment --> ";           //User accepts the payment or program ends.
        cin >> payment;
        if(payment != "ok" && payment != "OK"){
            break;
        }
        change = PAYMENT - vending[drink].price;                                                       //Calculates change due
        cout << "Please collect your " << change << "$ in change! Have a nice day!" << endl; 
        cout << "\n\n" ;
        soldcans++;
        vending[drink].amount -= 1;                                                                    //updates the drink supply
        drink = 0;          
    } 
    profit = PROFIT * soldcans;
    cout <<"\nThe machine made " << profit << "$ in profit during this run" << endl;                   //dislays profit made during the run
    cout << "\n" ;
    endput(vending);
}
//==============================
void print(vending vending){                                      // prints vending machine state
    int index = 0;
    cout << setw(19) << left << "Drink" << setw(17) << left << "Price" << setw(17) << left <<"Number" << setw(17) << left << "Supply" << endl;
    cout << "============================================================================" << endl;
    while(index < DRINKS){
        cout << setw(19) << left <<  vending[index].name << setw(17) << left << vending[index].price << setw(17) << left << index << setw(17) << left << vending[index].amount << endl;
        index++;
    }
    cout << "=============================================================================" << endl;
    cout << "\n\n\n" ;
    return;
}
//==============================
void getdata(vending& vending){
    int index = 0;
    ifstream infile;
    infile.open("machine.txt");
    while(!infile){
        cout << "Failed to retreive vending data." << endl;
        exit (EXIT_FAILURE);          //exits progam if file can not be entered                                                                                   
    }
    cout << "\n\n" << endl;
    while(infile && index < DRINKS){                                                //obtains drink information
        getline(infile, vending[index].name);
        infile >> vending[index].price;
        infile >> vending[index].amount;
        infile.ignore(50, '\n');
        index++;
    }
     while(infile && index < DRINKS){
        cout << "\n" <<  vending[index].price << endl;
        cout << vending[index].amount << endl;
        cout << vending[index].name << endl;
        index++;
     }
    infile.close();
    return;
}
//=============================
void endput(vending& vending){
    int index, selected = 0, largest;                                   //variables for selection search
    info place;
    for(index = 0; index < DRINKS; index++){
        largest = index;                                                //selection search to organize drinks by supply
        for(selected = (index + 1); selected < DRINKS; selected++){
            if(vending[selected].amount > vending[largest].amount){
                largest = selected; 
            }
        }
        if(largest != index){
            place = vending[index];
            vending[index] =  vending[largest];
            vending[largest] = place;
        }
    }
    cout << "\n\n\n" << endl;
    cout << "Machine State" << endl << endl;                  //output for machine final state
    print(vending);
    return;
}

