#include "Province.h"

Province::Province(std::string &name) {
    provinceName = name;
}

void Province::addDistrict(District *district) {
    provinceDistricts.push_back(district);
}

const string Province::getProvinceName() const {
    return provinceName;
}

void Province::removeDistrict(const std::string &name) {
    for(int i=0;i<provinceDistricts.size();i++){
        if(provinceDistricts[i]->getDistrictName() == name){
            provinceDistricts.erase(provinceDistricts.begin()+i);
        }
    }

}

vector<District *> &Province::getDistricts() {
    return provinceDistricts;
}

Province::~Province() {

}
