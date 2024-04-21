#ifndef SECTORS_MODULE_VOTER_H
#define SECTORS_MODULE_VOTER_H
#include <iostream>
#include "Person.h"
using namespace std;

class Voter : public Person{
private:
    string sector;
    bool voteStatus;
public:
    Voter();
    Voter(string voterName, string CNIC, string DOB, string gender, Address &address);
    string getVoterSector();
    bool getVoteStatus();
    void setVoterSector(string sector);
    void setVoterStatus(bool status);

};


#endif //SECTORS_MODULE_VOTER_H
