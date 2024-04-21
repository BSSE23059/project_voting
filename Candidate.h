
#ifndef PARTYREGISTRATION_CANDIDATE_H
#define PARTYREGISTRATION_CANDIDATE_H
#include <iostream>
#include "Person.h"
#include <vector>
#include "Voter.h"
using namespace std;

class Candidate : public Voter{
private:
    vector<string> nominatedSectors;
    bool isWon;
    int voteCount;
    int position;
public:
    Candidate();
    int getPosition();
    const int getVoteCount() const;
    bool getWonStatus();
    void setVoteCount(int count);
    void setWonStatus(bool status);
    void setPosition(int canPos);
    virtual void nominateOnSector(const string &sectorName) = 0;
};


#endif //PARTYREGISTRATION_CANDIDATE_H
