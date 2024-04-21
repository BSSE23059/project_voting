#ifndef PARTYREGISTRATION_PARTY_H
#define PARTYREGISTRATION_PARTY_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Candidate.h"
using namespace std;

class Party {
private:
    string registrationID;
    static int ID;
    string partyName;
    string adminName;
    string password;
    string partySymbol;
    vector<Candidate*> partyCandidates;
public:
    Party(string parName, string parAdmin, string parPassword, string partySymbol);
    const string getPartyName() const;
    const string getAdminName() const;
    const string getPassword() const;
    const string getRegistrationID() const;
    const string getPartySymbol() const;
    void setPartyName(string &name);
    void setAdminName(string &admin);
    void setPassword(string& pass);
    void setPartySymbol(string& symbol);
    void addCandidates(Candidate* candidate);


};


#endif //PARTYREGISTRATION_PARTY_H
