#ifndef PARTYREGISTRATION_PARTYCANDIDATE_H
#define PARTYREGISTRATION_PARTYCANDIDATE_H
#include <iostream>
#include "Candidate.h"
using namespace std;

class PartyCandidate : public Candidate{
private:
    string candidateParty;
    string candidateSymbol;
public:
    PartyCandidate();
    PartyCandidate( string canName, string canCNIC, string canGender, string canDOB,string canParty,string canSymbol,Address& address );
    const string getCandidateParty() const;
    const string getCandidateSymbol() const;
    void setCandidateParty(string canParty);
    void setCandidateSymbol(const string& canSymbol);
    void nominateOnSector(const string& secName);
};


#endif //PARTYREGISTRATION_PARTYCANDIDATE_H
