#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct adress {
    string street;
    unsigned short int house;
    unsigned short int flat;
};

struct vilager {
    string surname;
    string name;
    string fam;
    adress adr;
    string gen;
    unsigned short int age;
};

istream& operator>>(istream & in, adress & a) {
    in >> a.street >> a.house >> a.flat;
    return in;
};

istream& operator>>(istream & in, vilager & a) {
    in >> a.surname >> a.name >> a.fam >> a.adr >> a.gen >> a.age;
    transform(a.gen.begin(), a.gen.end(), a.gen.begin(), ::tolower);
    return in;
}

ostream& operator<<(ostream & out, const adress & a) {
    out << a.street << " street, house №" << a.house << ", flat №" << a.flat;
    return out;
};

ostream& operator<<(ostream & out, const vilager & a) {
    out << "FIO: " << a.surname << " " << a.name << " " << a.fam << "\nAdress: " << a.adr << "\nGender: " << a.gen << "\nAge: " << a.age;
    return out;
};

ostream& operator<<(ostream & out, const vector<vilager> & a) {
    for (vilager i : a){
        out << i.surname << " " << i.name << " " << i.fam << " " << i.adr.street << " " << i.adr.house << " " << i.adr.flat << " " << i.gen << " " << i.age << "\n";
    }
    return out;
};

bool operator<(const vilager a, vilager b){
    for (int i = 0; i<min(a.surname.size(),b.surname.size());i++){
        if (a.surname[i]<b.surname[i]) return 1;
        if (a.surname[i]>b.surname[i]) return 0;
    }
    for (int i = 0; i<min(a.name.size(),b.name.size());i++){
        if (a.name[i]<b.name[i]) return 1;
        if (a.name[i]>b.name[i]) return 0;
    }
    for (int i = 0; i<min(a.name.size(),b.name.size());i++){
        if (a.name[i]<b.name[i]) return 1;
        if (a.name[i]>b.name[i]) return 0;
    }
    return 0;
}



int main() {



    vector<vilager> baza;

    ifstream inFile("/home/ram/pcb04/CLionProjects/untitled/base.txt");
    vilager creature;

    while (inFile >> creature) {
        baza.push_back(creature);
    }


    sort(baza.begin(),baza.end());

    int sum=0;

    for (vilager man : baza){
        if  (man.gen == "male" && man.age <= 60 && man.age >= 18)
        {
            cout << man << endl << endl;
            sum++;
        }
    }

    cout << "Man between 18 and 60 years: " << sum << endl;




    ofstream outFile("/home/ram/pcb04/CLionProjects/untitled/base.txt");
    outFile << baza;

    inFile.close();
    outFile.close();
    return 0;
}
