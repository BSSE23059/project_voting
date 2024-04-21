
#include "Sector.h"

Sector::Sector() = default;

const string Sector::getDistrict() const {
    return district;
}

const string Sector::getSectorCode() const {
    return sectorCode;
}

void Sector::setDistrict(const std::string &secDistrict) {
    district = secDistrict;
}

void Sector::setSectorCode(const std::string &secCode) {
    sectorCode = secCode;
}

Sector::~Sector() {

}
