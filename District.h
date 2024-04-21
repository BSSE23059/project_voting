#ifndef SECTORS_MODULE_DISTRICT_H
#define SECTORS_MODULE_DISTRICT_H
#include <iostream>
#include <vector>
#include "Sector.h"
using namespace std;

class District {
private:
    string districtName;
    vector<Sector*> districtSectors;
public:
    explicit District(const string &name);
    const string getDistrictName() const;
    void setDistrictName(const string &name);
    vector<Sector*>& getSectors();

};


#endif //SECTORS_MODULE_DISTRICT_H
