#include "person.h"
#include "persons.h"

int main(){

    Persons *persons = Persons::getInstance();
    persons->loadPersonsFromJsonFile("persons_data.json");
    persons->display();
    

    while(true){
        int ch;
        cout << "\n\nMenu:\n1. Add Person \n2. Remove Person \n3. Search Person \n4. Display All People \n5. Exit ";
        cin>>ch;
        if(ch==5)
        break;
        string cnic;
        cout<<"Enter your cnic in this format  00000-0000000-0: ";
        cin>>cnic;
        cout<<persons->searchPerson(cnic)<<endl;
        
        }

    return 0;
}