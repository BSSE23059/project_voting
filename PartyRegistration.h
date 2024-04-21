#ifndef PARTYREGISTRATION_PARTYREGISTRATION_H
#define PARTYREGISTRATION_PARTYREGISTRATION_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Party.h"
#include "PartyCandidate.h"
#include "exeAddCandidate.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

class PartyRegistration {
private:
    static PartyRegistration* instance;
    vector<Party*> parties;
    PartyRegistration();
public:
    static PartyRegistration* getInstance();
    void addParty(Party* party);
    void addCandidate(PartyCandidate* candidate,string& partyName);
    void nominatedCandidate(PartyCandidate* partyCandidate,string& provinceName, string& districtName, string& sectorCode);
    void loginAdmin(string adminName,string password);

};


#endif //PARTYREGISTRATION_PARTYREGISTRATION_H
