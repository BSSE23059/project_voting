#ifndef PARTYREGISTRATION_PERSON_H
#define PARTYREGISTRATION_PERSON_H
#include <iostream>
#include "Address.h"
using namespace std;

class Person {
private:
    string personName;
    string CNIC;
    string dateOfBirth;
    string Gender;
    Address personAddress;
public:
    Person();
    const string getPersonName() const;
    const string getCNIC() const;
    const string getDateOfBirth() const;
    const string getGender() const;
    const Address getPersonAddress() const;
    void setPersonName(string name);
    void setPersonCNIC(string perCNIC);
    void setDateOfBirth(string dob);
    void setPersonAddress(Address &address);
    void setPersonGender(string perGender);
    void castVote();
};


#endif //PARTYREGISTRATION_PERSON_H
