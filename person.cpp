#include "person.h"

vector<string>planet_names{"Kashyyyk", "Coruscant", "Corellia", "Vulcan"};

Person::Person(const string name, const int erfahrungswert, const Planet planet): name{name}, erfahrungswert{erfahrungswert}, planet{planet}
{
    if(name.empty() || erfahrungswert<0 || erfahrungswert>100) throw runtime_error("Error!");
}

bool Person::make_expedition(Planet p)
{
    if(p==planet)
    {
        if(erfahrungswert+2<=100)
        {
            erfahrungswert+=2;
            return 1;
        }
        return 0;
    }
    else
    {
        if(erfahrungswert+5<=100)
        {
            erfahrungswert+=5;
            return 1;
        }
        return 0;
    }
}

bool Person::is_experienced() const
{
    return(erfahrungswert>75);
}

bool Person::operator==(const Person& pla) const
{
    return(pla.name==name && pla.erfahrungswert==erfahrungswert && pla.planet==planet);
}

ostream& operator<<(ostream& o, const Person& pers)
{
    return o << "[" << pers.name << ": " << pers.erfahrungswert << ", " << planet_names.at(static_cast<int>(pers.planet)) << "]";
}
