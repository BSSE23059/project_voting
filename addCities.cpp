#include "addCities.h"

void executeAddCities(const string &provinceName){

    char stop;
    do{
        cout << "______________________________________________________" << endl;
        cout << "                                                      " << endl;
        cout << "        Add Districts in " << provinceName <<endl;
        cout << "______________________________________________________" << endl;
        Provinces *provinces = Provinces::getInstance();
        string districtName;

        cout << "Enter name of district :";
        cin >> districtName;

        auto *district = new District(districtName);
        provinces->addDistricts(district,provinceName);

        cout << "Do you want to continue(Y/N): ";
        cin >> stop;
    }while(stop=='y' || stop=='Y');


}