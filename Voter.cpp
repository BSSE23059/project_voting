#include "Voter.h"

Voter::Voter(std::string voterName, std::string CNIC, std::string DOB, std::string gender, Address &address) {
    setPersonName(voterName);
    setPersonCNIC(CNIC);
    setPersonGender(gender);
    setPersonAddress(address);
    setDateOfBirth(DOB);
    sector = "";
    voteStatus = false;
}

Voter::Voter() {
    setPersonName("");
    setPersonCNIC("");
    setPersonGender("");
    setDateOfBirth("");
    sector = "";
    voteStatus = false;
}

bool Voter::getVoteStatus() {
    return voteStatus;
}

string Voter::getVoterSector() {
    return sector;
}

void Voter::setVoterStatus(bool status) {
    voteStatus = status;
}

void Voter::setVoterSector(std::string voterSector) {
    sector = voterSector;
}

