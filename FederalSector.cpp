#include "FederalSector.h"

int FederalSector::ID= 0;

FederalSector::FederalSector(std::string &districtName) {
    ID++;
    string code;
    code = "NA-" + to_string(ID);
    setSectorCode(code);
    setDistrict(districtName);
    provisionalSectorCount = 0;
}

void FederalSector::nominateCandidate(Candidate *candidate) {
    federalSectorCandidates.push_back(candidate);
}

void FederalSector::removeCandidate(const std::string &name) {
    for(int i=0;i<federalSectorCandidates.size();i++){
        if(federalSectorCandidates[i]->getPersonName() == name){
            federalSectorCandidates.erase(federalSectorCandidates.begin()+i);
        }
    }
}

void FederalSector::addProvisionalSector(ProvisionalSector provisionalSector1) {
    provisionalSector[provisionalSectorCount] = provisionalSector1;
    provisionalSectorCount++;
}