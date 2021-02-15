#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "person.h"

class Spaceship
{
    private:
        string spname;
        vector<Person>liste;
        Planet einPlanet;

    public:
        Spaceship(const string spname, vector<Person>liste, const Planet& einPlanet = Planet::Corellia);
        bool hire(const Person&);
        friend ostream& operator<<(ostream&, const Spaceship&);

        vector<Person> expedition();
};

#endif // SPACESHIP_H
