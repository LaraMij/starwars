#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Planet{Kashyyyk, Coruscant, Corellia, Vulcan};
extern vector<string>planet_names;

class Person
{
    private:
        string name;
        int erfahrungswert;
        Planet planet;

    public:
        Person(const string name, const int erfahrungswert, const Planet planet = Planet::Kashyyyk);
        bool make_expedition(Planet p);
        bool is_experienced() const;
        bool operator==(const Person&) const;
        friend ostream& operator<<(ostream&, const Person&);
};

#endif // PERSON_H
