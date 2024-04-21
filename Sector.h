#ifndef SECTORS_MODULE_SECTOR_H
#define SECTORS_MODULE_SECTOR_H
#include <iostream>
#include "Candidate.h"
using namespace std;

class Sector {
private:
    string district;
    string sectorCode;
public:
    Sector();
    const string getDistrict() const;
    const string getSectorCode() const;
    void setDistrict(const string& secDistrict);
    void setSectorCode(const string& secCode);
    virtual void nominateCandidate(Candidate *candidate) = 0;
    virtual ~Sector();
};


#endif //SECTORS_MODULE_SECTOR_H
