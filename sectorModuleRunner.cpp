#include "sectorModuleRunner.h"
#include "Sector.h"
#include "FederalSector.h"
#include "ProvisionalSector.h"
#include "Province.h"
#include "Provinces.h"
#include "Address.h"
#include "Person.h"
#include "Candidate.h"
#include "Voter.h"
#include "addCities.h"
#include "addSectors.h"
#include "District.h"

void executeSectorModule(){
    int choice;
    char stop;

    do{
        system("clear");
        cout << "_________________________________________________________" << endl;
        cout << "                                                         " << endl;
        cout << "               Welcome to Sector Management              " << endl;
        cout << "_________________________________________________________" << endl;
        cout << "1. Add provinces." << endl;
        cout << "2. Add District." << endl;
        cout << "3. Add Sectors." << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        Provinces *provinces = Provinces::getInstance();
        switch (choice) {
            case 1:{
                int numOfProvinces;
                string provinceName;
                cout << "Enter number of provinces you want to add: ";
                cin >> numOfProvinces;
                for(int i=0;i<numOfProvinces;i++){
                    cout << "Enter province Name: ";
                    cin >> provinceName;
                    ifstream checkProvince("provinces.txt");
                    string provinceNames;
                    while(getline(checkProvince,provinceNames)){
                        if(provinceNames == provinceName){
                            cout << "The province with this name already exists. Please enter a different Province :";
                            cin >> provinceName;

                            checkProvince.clear();
                            checkProvince.seekg(0, ios::beg);
                        }
                    }
                    auto *province = new Province(provinceName);
                    provinces->addProvince(province);
                }
                break;

            }
            case 2:{

                string provinceName;
                cout << "Enter the province Name: ";
                cin >> provinceName;
                executeAddCities(provinceName);
                break;
            }
            case 3:{
                string provinceName,districtName;
                cout << "Enter the province Name: ";
                cin >> provinceName;
                cout << "Enter the name of District: ";
                cin >> districtName;
                addSector(districtName,provinceName);
                break;
            }
            case 4:{
                exit(0);
            }

            default:{
                cout << "Invalid Input. Please enter a valid input." << endl;
            }
        }
        cout << "Do you want to continue(Y/N): ";
        cin >> stop;
    }while(stop == 'Y' || stop == 'y');

}