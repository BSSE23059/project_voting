#include "Address.h"

Address::Address(std::string districtName, std::string areaName, std::string blockCode, int street, int house) {
    district = districtName;
    area = areaName;
    block = blockCode;
    streetNum = street;
    houseNum = house;
    concatenatedAddress = district +", "+ area +", "+ block+ ", street # " + to_string(streetNum) +", house # "+ to_string(houseNum);
}

Address::Address() = default;

string Address::getConcatenatedAddress() const {
    return concatenatedAddress;
}

void Address::setConcatenatedAddress(const std::string &address) {
    concatenatedAddress = address;
}