#ifndef SECTORS_MODULE_ADDCITIES_H
#define SECTORS_MODULE_ADDCITIES_H
#include <iostream>
#include <fstream>
#include "District.h"
#include "addSectors.h"
#include "Provinces.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

void executeAddCities(const string &provinceName);

#endif //SECTORS_MODULE_ADDCITIES_H
