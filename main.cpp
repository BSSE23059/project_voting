#include <iostream>
#include "registrationRunner.h"
#include "sectorModuleRunner.h"
using namespace std;

int main(){
    int choice;
    char stop;

    do{
        system("clear");
        cout << "_______________________________________________________" << endl;
        cout << "                                                       " << endl;
        cout << "        Welcome to Electoral Voting System             " << endl;
        cout << "_______________________________________________________" << endl;
        cout << "1-> Party Registration." << endl;
        cout << "2-> Sector Module." << endl;
        cout << "3-> Person Registration." << endl;
        cout << "4-> Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:{
                partyRegistration();
                break;
            }
            case 2:{
                string adminPass;
                cout << "Enter admin pass word: ";
                cin >> adminPass;
                if(adminPass == "1234"){
                    executeSectorModule();
                }
                break;
            }
            default:{
                cout << "Invalid Input, Please enter a valid input....." << endl;
                break;
            }
        }
        cout << "Do you want to continue(Y/N): ";
        cin >> stop;
    }while(stop == 'Y' || stop == 'y');

    return 0;
}