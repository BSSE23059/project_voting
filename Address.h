#ifndef PARTYREGISTRATION_ADDRESS_H
#define PARTYREGISTRATION_ADDRESS_H
#include <iostream>
using namespace std;

class Address {
private:
    string district;
    string area;
    string block;
    int streetNum;
    int houseNum;
    string concatenatedAddress;
public:
    Address();
    Address(string districtName, string areaName, string blockCode, int street, int house);
    string getConcatenatedAddress() const;
    void setConcatenatedAddress(const string &address);
};


#endif //PARTYREGISTRATION_ADDRESS_H
