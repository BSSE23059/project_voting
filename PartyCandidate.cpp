

#include "PartyCandidate.h"

PartyCandidate::PartyCandidate() {}

PartyCandidate::PartyCandidate(std::string canName, std::string canCNIC, std::string canGender, std::string canDOB,
                               std::string canParty,string canSymbol, Address &address) {
    setPersonName(canName);
    setPersonCNIC(canCNIC);
    setDateOfBirth(canDOB);
    setPersonGender(canGender);
    setPersonAddress(address);
    candidateParty = canParty;
    candidateSymbol = canSymbol;
    setWonStatus(false);
    setPosition(0);
    setVoteCount(0);

}

const string PartyCandidate::getCandidateParty() const {
    return candidateParty;
}

void PartyCandidate::setCandidateParty(std::string canParty) {
    candidateParty = canParty;
}

void PartyCandidate::nominateOnSector(const string &secName) {

}

const string PartyCandidate::getCandidateSymbol() const {
    return candidateSymbol;
}

void PartyCandidate::setCandidateSymbol(const std::string &canSymbol) {
    candidateSymbol = canSymbol;
}
