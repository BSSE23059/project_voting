
#ifndef PARTYREGISTRATION_EXEADDCANDIDATE_H
#define PARTYREGISTRATION_EXEADDCANDIDATE_H
#include <iostream>
#include "Address.h"
#include "PartyCandidate.h"
#include "PartyRegistration.h"
#include <fstream>
#include "nlohmann/json.hpp"
#include "Provinces.h"
using json = nlohmann::json;
using namespace std;

void addCandidates(string partyName,string partyRegID,string partySymbol);


#endif //PARTYREGISTRATION_EXEADDCANDIDATE_H
