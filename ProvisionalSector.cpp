#include "ProvisionalSector.h"

int ProvisionalSector::ID = 0;

ProvisionalSector::ProvisionalSector() {}

ProvisionalSector::ProvisionalSector(std::string &districtName,string &provinceName) {

    string code;
    string provinceCode;
    if(provinceName == "Punjab"){
        ifstream punjabSectorsFile("PunjabSectors.txt");
        string punjabSectors;
        int count = 0;
        while(getline(punjabSectorsFile,punjabSectors)){
            count++;
        }
        if(count == 0){
            ID++;
        } else if(count > 0){
            ID = count + 1;
        }
        provinceCode = "PP-";
        code = provinceCode + to_string(ID);
        setSectorCode(code);
    } else if(provinceName == "Sindh"){
        ifstream SindhSectorsFile("SindhSectors.txt");
        string SindhSectors;
        int count = 0;
        while(getline(SindhSectorsFile,SindhSectors)){
            count++;
        }
        if(count == 0){
            ID++;
        } else if(count > 0){
            ID = count + 1;
        }
        provinceCode = "PS-";
        code = provinceCode + to_string(ID);
        setSectorCode(code);
    } else if(provinceName == "Baloachistan"){
        ifstream BaloachistanSectorsFile("BaloachistanSectors.txt");
        string BaloachistanSectors;
        int count = 0;
        while(getline(BaloachistanSectorsFile,BaloachistanSectors)){
            count++;
        }
        if(count == 0){
            ID++;
        } else if(count > 0){
            ID = count + 1;
        }
        provinceCode = "PB-";
        code = provinceCode + to_string(ID);
        setSectorCode(code);
    } else if(provinceName == "Khyber Pakhtunekhwa"){
        ifstream KPKSectorsFile("Khyber-PakhtunekhwaSectors.txt");
        string KPKSectors;
        int count = 0;
        while(getline(KPKSectorsFile,KPKSectors)){
            count++;
        }
        if(count == 0){
            ID++;
        } else if(count > 0){
            ID = count + 1;
        }
        provinceCode = "PK-";
        code = provinceCode + to_string(ID);
        setSectorCode(code);
    }

    setDistrict(districtName);
}

void ProvisionalSector::nominateCandidate(Candidate *candidate) {
    provisionalSectorCandidates.push_back(candidate);
}

void ProvisionalSector::removeCandidate(const std::string &name) {
    for(int i=0;i<provisionalSectorCandidates.size();i++){
        if(provisionalSectorCandidates[i]->getPersonName() == name){
            provisionalSectorCandidates.erase(provisionalSectorCandidates.begin()+i);
        }
    }
}