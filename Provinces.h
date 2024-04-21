#ifndef SECTORS_MODULE_PROVINCES_H
#define SECTORS_MODULE_PROVINCES_H
#include <iostream>
#include "Province.h"
#include "Sector.h"
#include <fstream>
#include "nlohmann/json.hpp"
#include "addCities.h"
#include "addSectors.h"
using json = nlohmann::json;
using namespace std;

class Provinces {
private:
    static Provinces* instance;
    vector<Province*> provinces;
    Provinces();
public:
    static Provinces* getInstance();
    void addProvince(Province* province);
    void addDistricts(District* district,const string& provinceName);
    void addSectors(ProvisionalSector* provisionalSector, const string& districtName, const string& provinceName);
    void displayProvinces();
    void displayDistricts(string& provinceName);
    void displaySectors(string& districtName);
};




#endif //SECTORS_MODULE_PROVINCES_H
