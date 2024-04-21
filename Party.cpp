#include "Party.h"

int Party::ID = 0;

Party::Party(std::string parName, std::string parAdmin, std::string parPassword, string partySymbol) {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    string currentYear = to_string(localTime->tm_year + 1900);
    ifstream getPartyID("partyRegistrationIDs.txt");
    string IDs;
    int count = 0;
    while(getline(getPartyID,IDs)){
        count++;
    }
    if(count == 0){
        ID++;
    } else if(count > 0){
        ID = count + 1;
    }

    registrationID = "PAR-" + currentYear + "-" + to_string(ID);
    partyName = parName;
    adminName = parAdmin;
    password = parPassword;
    this -> partySymbol = partySymbol;

}

const string Party::getPartyName() const {
    return partyName;
}

const string Party::getAdminName() const {
    return adminName;
}

const string Party::getPassword() const {
    return password;

}

const string Party::getRegistrationID() const {
    return registrationID;
}

void Party::setPartyName(std::string &name) {
    partyName = name;
}

void Party::setAdminName(std::string &admin) {
    adminName = admin;
}


void Party::setPassword(std::string &pass) {
    password = pass;
}

void Party::addCandidates(Candidate *candidate) {
    partyCandidates.push_back(candidate);
}

const string Party::getPartySymbol() const {
    return partySymbol;
}


void Party::setPartySymbol(std::string &symbol) {
    partySymbol = symbol;
}