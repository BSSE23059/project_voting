#include "District.h"


District::District(const std::string &name) {
    districtName = name;

}

const string District::getDistrictName() const {
    return districtName;
}

void District::setDistrictName(const std::string &name) {
    districtName = name;
}

vector<Sector *> &District::getSectors() {
    return districtSectors;
}