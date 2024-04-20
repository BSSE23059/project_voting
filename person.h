#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
class Person{
    private:
    string name;
    int DOB;
    string cnic;
    bool is_alive;
    bool has_voted;
    string sector;
    char  gender;
    string addr;

    public:
    Person();
    Person(string name,int dob,string cnic,bool is_alive,string sector,char gender,string address);
    string getSector() const;
    int getDOB() const;
    string getCnic() const;
    char getGender() const;
    bool getHasVoted() const;
    bool getIsAlive() const;
    void setHasVoted(bool ) ;
    virtual void display()const ;
    
};





#endif