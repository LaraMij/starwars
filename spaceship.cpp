#include "spaceship.h"

Spaceship::Spaceship(const string spname, vector<Person>liste, const Planet& einPlanet): spname{spname}, liste{liste}, einPlanet{einPlanet}
{
    if(spname.empty() || liste.empty()) throw runtime_error("Error!");

    for(size_t i = 0; i<liste.size()-1; i++)
    {
        for(size_t j = i+1; j<liste.size(); j++)
        {
            if(liste.at(i)==liste.at(j)) throw runtime_error("Error!");
        }
    }
}

bool Spaceship::hire(const Person& pe)
{
    for(size_t i = 0; i<liste.size(); i++)
    {
        if(liste.at(i)==pe)
        {
            return false;
        }
    }
    liste.push_back(pe);
    return true;
}

vector<Person> Spaceship::expedition()
{
    vector<Person>entfernt;
    for(size_t i = 0; i<liste.size(); i++)
    {
        liste.at(i).make_expedition(einPlanet);
    }
    for(size_t i = 0; i<liste.size(); i++)
    {
        if(liste.at(i).is_experienced())
        {
            entfernt.push_back(liste.at(i));
        }
    }
    return entfernt;
}

ostream& operator<<(ostream& os, const Spaceship& sp)
{
    os << "[" << sp.spname << ", Crew: {";
    for(size_t i = 0; i<sp.liste.size(); i++)
    {
        os << sp.liste.at(i);
        if(i!=sp.liste.size()-1)
        {
            os << ", ";
        }
    }
    return os << "}, " << planet_names.at(static_cast<int>(sp.einPlanet)) << "]";
}
