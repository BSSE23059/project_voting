#ifndef SECTORS_MODULE_FEDERALSECTOR_H
#define SECTORS_MODULE_FEDERALSECTOR_H
#include <iostream>
#include <vector>
#include "Candidate.h"
#include "Sector.h"
#include "ProvisionalSector.h"
using namespace std;

class FederalSector : public Sector{
private:
    static int ID;
    vector<Candidate*> federalSectorCandidates;
    ProvisionalSector provisionalSector[2];
    int provisionalSectorCount;
public:
    explicit FederalSector(string &districtName);
    void nominateCandidate(Candidate* candidate) override;
    void removeCandidate(const string& name);
    void addProvisionalSector(ProvisionalSector provisionalSector1);

};


#endif //SECTORS_MODULE_FEDERALSECTOR_H
