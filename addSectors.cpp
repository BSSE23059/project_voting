#include "addSectors.h"

void addSector(string cityName,string provinceName){
    char stop;
    do{

        cout << "__________________________________________________" << endl;
        cout << "                                         " << endl;
        cout << "  Add sectors in " << cityName << " of " << provinceName << endl;
        cout << "__________________________________________________" << endl;


        string city = cityName;
        string province = provinceName;
        Provinces *provinces = Provinces::getInstance();

        auto *provisionalSector = new ProvisionalSector(city,province);

        cout << "Sector with sector code " << provisionalSector->getSectorCode() << " has been created." << endl;
        provinces->addSectors(provisionalSector,provisionalSector->getDistrict(),province);

        cout << "Do you want to continue(Y/N): ";
        cin >> stop;
    }while(stop=='y' || stop=='Y');

}