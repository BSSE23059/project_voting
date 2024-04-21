#ifndef SECTORS_MODULE_PROVINCE_H
#define SECTORS_MODULE_PROVINCE_H
#include <iostream>
#include "District.h"
#include <vector>
using namespace std;

class Province {
private:
    string provinceName;
    vector<District*> provinceDistricts;
public:
    explicit Province(string &name);
    const string getProvinceName() const;
    void addDistrict(District* district);
    void removeDistrict(const string &name);
    vector<District*>& getDistricts();
    virtual ~Province();

};


#endif //SECTORS_MODULE_PROVINCE_H
