#include "PartyRegistration.h"

PartyRegistration *PartyRegistration::instance = nullptr;

PartyRegistration::PartyRegistration() {

}

PartyRegistration *PartyRegistration::getInstance() {
    if (instance == nullptr) {
        instance = new PartyRegistration;
    }
    return instance;
}


void PartyRegistration::addParty(Party *party) {
    parties.push_back(party);

    string partNameFile = party->getPartyName() + ".json";
    json partyData;
    ofstream partyFile(partNameFile);
    partyFile << partyData << endl;
    partyFile.close();

    ofstream putAmins("partyAdmins.txt", ios::app);
    putAmins << party->getAdminName() << endl;
    putAmins.close();

    ofstream partyRegIDS("partyRegistrationIDs.txt", ios::app);
    partyRegIDS << party->getRegistrationID() << endl;
    partyRegIDS.close();

    string passwordFile = party->getAdminName() + ".json";
    ofstream partyPassword(passwordFile);


    json admin;
    admin[party->getAdminName()] = {
            {"Password",     party->getPassword()},
            {"Party ID",     party->getRegistrationID()},
            {"Party Name",   party->getPartyName()},
            {"Party Symbol", party->getPartySymbol()}
    };


    partyPassword << admin << endl;

}

void PartyRegistration::addCandidate(PartyCandidate *candidate, std::string &partyName) {
    for (int i = 0; i < parties.size(); i++) {
        if (parties[i]->getPartyName() == partyName) {
            parties[i]->addCandidates(candidate);
        }
    }
    string filename = partyName + ".json";
    ifstream partyFile(filename);

    json partyData;
    partyFile >> partyData;
    partyFile.close();

    json candidateData;
    candidateData[candidate->getCNIC()] = {
            {"Name",          candidate->getPersonName()},
            {"Gender",        candidate->getGender()},
            {"Date Of Birth", candidate->getDateOfBirth()},
            {"Address",       candidate->getPersonAddress().getConcatenatedAddress()}

    };

    partyData.push_back(candidateData);

    ofstream putPartyCandidates(filename);
    putPartyCandidates << partyData.dump(4);
    putPartyCandidates.close();

}

void PartyRegistration::loginAdmin(std::string admin, std::string password) {
    string adminFile = admin + ".json";
    string admins;
    ifstream checkAdmin("partyAdmins.txt");
    while (getline(checkAdmin, admins)) {
        if (admins == admin) {
            ifstream loginAdmin(adminFile);

            json adminData;
            loginAdmin >> adminData;
            loginAdmin.close();

            if (adminData.contains(admin)) {
                json adminInfo = adminData[admin];


                if (adminInfo["Password"] == password) {
                    string partyName = adminInfo["Party Name"];
                    string registrationID = adminInfo["Party ID"];
                    string partySymbol = adminInfo["Party Symbol"];
                    addCandidates(partyName, registrationID, partySymbol);
                    return;
                } else {
                    std::cout << "Incorrect password. Please try again." << std::endl;
                    return;
                }
            } else {
                cout << "Admin username not found." << std::endl;
                return;
            }


        }
    }

}

void PartyRegistration::nominatedCandidate(PartyCandidate *partyCandidate,
                                           std::string &districtName, std::string &sectorCode) {


}