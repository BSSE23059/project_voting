#include "Provinces.h"

Provinces *Provinces::instance = nullptr;

Provinces::Provinces() = default;

Provinces *Provinces::getInstance() {
    if(instance == nullptr){
        instance = new Provinces;
    }
    return instance;
}

void Provinces::addProvince(Province *province) {
    provinces.push_back(province);
    string filename = province->getProvinceName() + ".json";

    ofstream provinceName("provinces.txt",ios::app);
    provinceName << province->getProvinceName() << endl;
    provinceName.close();

    ofstream province1(filename);

    json provinceData;


    provinceData[province->getProvinceName()] = json::array();
    province1 << provinceData.dump(4) << endl;
    province1.close();



    string provinceSectorsFile = province->getProvinceName() + "Sectors.txt";
    ofstream provinceSectors(provinceSectorsFile,ios::app);
    provinceSectors.close();


    executeAddCities(province->getProvinceName());

}

void Provinces::addDistricts(District *district,const string& provinceName) {

    for(auto & province : provinces){
        if(province->getProvinceName() == provinceName){
            province->addDistrict(district);
        }
    }

    string filename = provinceName + ".json";
    string districtFile = district->getDistrictName() + ".json";
    ifstream provinceFile(filename);

    json provinceData;

    provinceFile >> provinceData;
    provinceFile.close();


    if(provinceData.contains(provinceName)){
        json &districtArray = provinceData[provinceName];

        for (auto &existingDistrict : districtArray) {
            if (existingDistrict["District Name"] == district->getDistrictName()) {
                cout << "District " << district->getDistrictName() << " already exists in " << provinceName << "." << endl;
            }
        }
        json districtData;

        districtData["District Name"] = district->getDistrictName();

        districtArray.push_back(districtData);

        ofstream putDistrictData(filename);
        putDistrictData << provinceData << endl;
        putDistrictData.close();


    } else {
        cout << "Province with " << provinceName << " does not exist." << endl;
    }

    ofstream putDistrictDataFile(districtFile);

    if (!putDistrictDataFile.is_open()) {
        cout << "Error: Unable to open district file: " << districtFile << endl;
    } else {
        cout << "Successfully opened district file: " << districtFile << endl;
    }
    json districtFileData;
    districtFileData[district->getDistrictName()] = json::array();

    putDistrictDataFile << districtFileData << endl;
    putDistrictDataFile.close();

    if (putDistrictDataFile.fail()) {
        cout << "Error: Failed to write to district file: " << districtFile << endl;
    } else {
        cout << "Successfully wrote to district file: " << districtFile << endl;
    }

    cout << districtFileData << endl;

    string districtSectorsFile = district->getDistrictName() + "Sectors.txt";
    ofstream districtSectors(districtSectorsFile,ios::app);
    districtSectors.close();

    addSector(district->getDistrictName(),provinceName);

}

void Provinces::addSectors(ProvisionalSector* provisionalSector, const std::string& districtName, const string& provinceName) {
    for(int i=0;i<provinces.size();i++){
        if(provinces[i]->getDistricts()[i]->getDistrictName() == districtName){
            provinces[i]->getDistricts()[i]->getSectors().push_back(provisionalSector);
        }
    }

    string filename = districtName + ".json";
    string filename2 = provinceName + ".json";

    string districtSectorsFile = districtName + "Sectors.txt";
    ofstream districtSectors(districtSectorsFile,ios::app);
    districtSectors << provisionalSector->getSectorCode() << endl;
    districtSectors.close();

    string provinceSectorsFile = provinceName + "Sectors.txt";
    ofstream provinceSectors(provinceSectorsFile,ios::app);
    provinceSectors << provisionalSector->getSectorCode() << endl;
    provinceSectors.close();

    ifstream getDistrictFile(filename);

    json districtData;
    getDistrictFile >> districtData;
    getDistrictFile.close();


    if(districtData.contains(districtName)){
        json &sectorsArray = districtData[districtName];

        json sectorData;

        sectorData[provisionalSector->getSectorCode()] = json::array();

        sectorsArray.push_back(sectorData);

        ofstream putSectorData(filename);

        putSectorData << districtData.dump(4) << endl;
        putSectorData.close();


    } else {
        cout << "District with name " << districtName << " does not exist." << endl;
    }


}

void Provinces::displayProvinces(){
    ifstream displayProvinces("provinces.txt");

    int i = 0;
    string province;
    while(getline(displayProvinces,province)){
        cout << i + 1 << ". " << province << endl;
        i++;
    }
}

void Provinces::displayDistricts(std::string &provinceName) {
    string filename = provinceName + ".json";
    ifstream displayDistricts(filename);

    json districts;
    displayDistricts >> districts;
    displayDistricts.close();

    cout << "Districts of " << provinceName << ": " << endl;
    if(districts.contains(provinceName)){
        json &districtsArray = districts[provinceName];
        int i = 1;
        for(auto &district : districtsArray){
            string districtName = district["District Name"];
            cout << i << ". "<< districtName << endl;
            i++;
        }
    }
}

void Provinces::displaySectors(std::string &districtName) {
    string filename = districtName + ".json";
    ifstream displaySectors(filename);

    json sectors;
    displaySectors >> sectors;
    displaySectors.close();

    if(sectors.contains(districtName)){
        json &sectorsArray = sectors[districtName];
        int i = 1;
        cout << "Sectors of " << districtName << ": " << endl;
        for(auto& sector : sectorsArray){
            cout << i << ". " << sector.begin().key() << endl;
            i++;
        }
    } else {
        cout << "District " << districtName << " does not exist." << endl;
    }
}