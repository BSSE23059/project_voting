#include "exeAddCandidate.h"

void addCandidates(string partyName,string partyRegID,string partySymbol){
    int choice;
    char stop;
    do{
        system("clear");
        cout << "Your Party Registration ID is " << partyRegID << endl;
        cout << "_______________________________________________" << endl;
        cout << "                                               " << endl;
        cout << "              Welcome to Home Screen           " << endl;
        cout << "_______________________________________________" << endl;
        cout << "1-> Add Candidates." << endl;
        cout << "2-> Nominate Candidates." << endl;
        cout << "3-> Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        Provinces *provinces = Provinces::getInstance();
        PartyRegistration *partyRegistration = PartyRegistration::getInstance();
        switch (choice) {
            case 1:{
                string canName,gender,dateOfBirth,CNIC,district,town,block;
                int house,street;
                cout << "Enter candidate name: ";
                cin >> canName;
                cout << "Enter candidate gender: ";
                cin >> gender;
                cout << "Enter candidate CNIC: ";
                cin >> CNIC;
                cout << "Enter candidate Date Of Birth: ";
                cin >> dateOfBirth;
                cout << "****** Address of Candidate ******" << endl;
                cout << "Enter candidate residential city: ";
                cin >> district;
                cout << "Enter candidate residential town: ";
                cin >> town;
                cout << "Enter candidate town's block code: ";
                cin >> block;
                cout << "Enter street number: ";
                cin >> street;
                cout << "Enter house number: ";
                cin >> house;
                Address address(district,town,block,street,house);
                auto partyCandidate = new PartyCandidate(canName,CNIC,gender,dateOfBirth,partyName,partySymbol,address);
                partyRegistration->addCandidate(partyCandidate,partyName);
                break;
            }
            case 2:{
                provinces->displayProvinces();
                string provinceName, districtName, sectorCode,candidateName,CNIC;
                cout << "Enter province Name: ";
                cin >> provinceName;
                provinces->displayDistricts(provinceName);
                cout << "Enter the district name: ";
                cin >> districtName;
                provinces->displaySectors(districtName);

                cout << "Enter the sector code on which you want to nominate your candidate: ";
                cin >> sectorCode;
                cout << "Enter the CNIC of member of your party: ";
                cin >> CNIC;
                cout << partyName << endl;
                string filename = partyName + ".json";
                ifstream getMemberData(filename);

                string name,gender,dateOfBirth,address;
                json candidates;
                getMemberData >> candidates;
                getMemberData.close();

                for(auto &candidate : candidates){
                    if(candidate.contains(CNIC)){
                        cout << "Member with CNIC " << CNIC <<" found" << endl;
                        name = candidate[CNIC]["Name"];
                        gender = candidate[CNIC]["Gender"];
                        dateOfBirth = candidate[CNIC]["Date Of Birth"];
                        address = candidate[CNIC]["Address"];

                    } else {
                        cout << "Member with CNIC " << CNIC << " does not found in your records." << endl;
                    }
                }

                Address address1;

                auto *partyCandidate = new PartyCandidate(name,CNIC,gender,dateOfBirth,partyName,partySymbol,address1);




                break;
            }
            default:{
                cout << "Invalid Input, Please enter valid input...." << endl;
                break;
            }
        }
        cout <<  "Do you want to continue(Y/N): ";
        cin >> stop;
    }while(stop == 'Y' || stop == 'y');



}