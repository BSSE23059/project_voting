#include "persons.h"
#include "nlohmann/json.hpp" 
#include <fstream>
#include <algorithm>
using json = nlohmann::json;

Persons* Persons::instance = nullptr;

void Persons::addPersons(const Person &per) {
        persons.push_back(per);
    }

void Persons::loadPersonsFromJsonFile(const string filename) {
        ifstream file(filename);
        if (file.is_open()) {
            json data;
            file >> data;
            file.close();

            
        for (const auto& personEntry : data["Persons"]) {
            for (const auto& personData : personEntry.items()) {
                const auto& personDetails = personData.value()[0];
                string name = personDetails["NAME"];
                int dob = stoi(personDetails["DOB"].get<std::string>());
                string cnic = personData.key();
                bool is_alive = personDetails["Isalive"] == "True";
                string sector = personDetails["Sector"];
                string genderStr = personDetails["Gender"];
                char gender = genderStr.empty() ? ' ' : genderStr[0];
                string address = ""; 
                Person person(name, dob, cnic, is_alive, sector, gender, address);
                addPersons(person);
                }
            }
        } else {
            cerr << "Failed to open file: " << filename << std::endl;
        }
    }

void Persons::display() const {
        cout << " Persons Informations : " << endl;
        for (const auto &per : persons) {
            per.display();
        }
    }
string Persons::searchPerson(string cnic){
    auto it = find_if(persons.begin(), persons.end(), [cnic](const Person &per) {
            return per.getCnic() == cnic;
        });

        if (it != persons.end()) {
            
            int dob=it->getDOB();
            if(2024-dob < 18){
                cout << "This person is not 18 yet :)"<<endl;
                return  "Not";
            }
            bool has_voted=it->getHasVoted();
            if(has_voted){
            cout<<"Already voted :<"<<endl;
            return  "Not";}
            bool is_alive=it->getIsAlive();
            if(is_alive==false)
            {
                cout<<"Ho woah!!!! He/She is no longer alive!"<<endl;
                return  "Not";
                }
            return it->getSector();

        } else {
            cerr<< "Person with ID " << cnic << " not found." << endl;
            return "Not";
        }
}

/*

void Organization::updateEmployee(int id, string name) {
        
    }

*/