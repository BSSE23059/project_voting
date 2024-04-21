#ifndef SECTORS_MODULE_PROVISIONALSECTOR_H
#define SECTORS_MODULE_PROVISIONALSECTOR_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Candidate.h"
#include "Sector.h"
using namespace std;

class ProvisionalSector : public Sector{
    static int ID;
    vector<Candidate*> provisionalSectorCandidates;
public:
    ProvisionalSector();
    ProvisionalSector(string &districtName, string &provinceName);
    void nominateCandidate(Candidate* candidate);
    void removeCandidate(const string& name);
};


#endif //SECTORS_MODULE_PROVISIONALSECTOR_H
