#include "person.h"
Person::Person(){
        this->name="";
        this->DOB=0;
        this->cnic="";
        this->is_alive=false;
        this->has_voted=false;
        this->sector="";
        this->gender=' ';
        this->addr="";
    }

Person::Person(string name,int dob,string cnic,bool is_alive,string sector,char gender,string address){
        this->name=name;
        this->DOB=dob;
        this->cnic=cnic;
        this->is_alive=is_alive;
        this->has_voted=false;
        this->sector=sector;
        this->gender=gender;
        this->addr=address;
    }

string Person::getSector() const{
    return  this->sector;
}
int Person::getDOB() const{
    return this->DOB;
}
string Person::getCnic() const{
    return this->cnic;
}
char Person::getGender() const{
    return this->gender;
}
void Person::setHasVoted(bool has_voted){
    this->has_voted=has_voted;
}
void Person::display() const {
    cout<<"Name: "<<name<<" DOB: "<<DOB<<" CNIC: "<<cnic<<" Is alive: "<< is_alive<<endl;
}
bool Person::getHasVoted() const{return has_voted;};
bool Person::getIsAlive() const{return is_alive;};