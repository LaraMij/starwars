#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"person.h"
#include"spaceship.h"

using namespace std;

int main(){
  try{
    Person han{"", 90, Planet::Coruscant};
    cout << han << '\n';
  }
  catch(runtime_error& e){
    cout << "Error1" << "\n";
  }
  try{
    Person han2{"Han Solo", 100, Planet::Vulcan};
    cout << han2 << '\n';
    Person han{"Han Solo", 110, Planet::Coruscant};
    cout << han << '\n';
  }
  catch(runtime_error& e){
    cout << "Error2" << "\n";
  }
  try{
    Person han2{"Han Solo", 100, Planet::Coruscant};
    cout << han2 << '\n';
    Person han{"Han Solo", -10, Planet::Coruscant};
    cout << han << '\n';
  }
  catch(runtime_error& e){
    cout << "Error3" << "\n";
  }
  try{
    Person han{"Han Solo", 0, Planet::Corellia};
    cout << han << '\n';
    Person han2{"Han Solo", 100, Planet::Kashyyyk};
    cout << han2 << '\n';
  }
  catch(runtime_error& e){
    cout << "Error4" << "\n";
  }
  try{
    cout << Person {"Han Solo", 100} << '\n';
  }
  catch(runtime_error& e){
    cout << "Error5" << "\n";
  }

  const Person han{"Han Solo", 100,Planet::Corellia};
  const Person chewie{"Chewbacca", 90, Planet::Kashyyyk};
  const Person leia{"Leia Organa", 88};
  const Person lando{"Lando Calrissian", 65, Planet::Corellia};
  const Person boba{"Boba Fett", 44};
  const Person wedge{"Wedge Antilles",85,Planet::Corellia};
  const Person madine{"Crix Madine",78,Planet::Corellia};
  const Person dengar{"Dengar",50,Planet::Corellia};
  Person dummy{"Dengar",0};

  cout << han << '\n';
  cerr << han << '\n';

  Person han2{han};
  Person lando2{lando};
  Person chewie2{chewie};
  cout << han.is_experienced() << lando.is_experienced() << Person{"Test",76}.is_experienced() << dengar.is_experienced()
	   << Person{"Test",75}.is_experienced() << '\n';
  cout << chewie2.make_expedition(Planet::Vulcan);
  cout << chewie2.make_expedition(Planet::Kashyyyk);
  cout << chewie2.make_expedition(Planet::Vulcan);
  cout << chewie2.make_expedition(Planet::Kashyyyk);
  cout << '\n' << chewie2 << '\n';

  Person spock{"S'chn T'gai Spock",95,Planet::Vulcan};
  cout << spock.make_expedition(Planet::Corellia) << '\n';
  cout << spock << '\n';

  cout << (han == chewie) << (han == han) << (lando == han) << (han == han2) << (chewie == chewie2) << '\n';
  cout << (Person{"Han Solo", 100} == han);
  cout << (Person{"Han Soli", 100,Planet::Corellia} == han);
  cout << (Person{"Han Solo", 99,Planet::Corellia} == han) << "\n";

  try{
    Spaceship millenniumFalcon {"", {han, chewie}};
	cout << millenniumFalcon << '\n';
  }
  catch(runtime_error& e){
    cout << "Error7" << "\n";
  }
  try{
    Spaceship millenniumFalcon {"MillenniumFalcon", {han, chewie}};
	cout << millenniumFalcon << '\n';
  }
  catch(runtime_error& e){
    cout << "Error8" << "\n";
  }
  try{
    Spaceship millenniumFalcon {"MillenniumFalcon", {}};
	cout << millenniumFalcon << '\n';
  }
  catch(runtime_error& e){
    cout << "Error9" << "\n";
  }
  try{
    Spaceship millenniumFalcon {"", {}};
	cout << millenniumFalcon << '\n';
  }
  catch(runtime_error& e){
    cout << "Error10" << "\n";
  }
  try{
    Spaceship millenniumFalcon {"Doppelte", {han,leia,spock,han}};
	cout << millenniumFalcon << '\n';
  }
  catch(runtime_error& e){
    cout << "Error11" << "\n";
  }

  Spaceship millenniumFalcon {"MillenniumFalcon", {han, chewie}};
  Spaceship millenniumFalcon2 {"MillenniumFalcon2", {han2, chewie2, lando2},Planet::Coruscant};
  const Spaceship constTestSpaceship{millenniumFalcon};
  Spaceship testSpaceship{millenniumFalcon};

  cout << millenniumFalcon2 << '\n';
  cerr << millenniumFalcon2 << '\n';
  cout << constTestSpaceship << '\n';

  cout << millenniumFalcon2.hire(lando) << millenniumFalcon2.hire(boba) << millenniumFalcon.hire(dengar)
	   << millenniumFalcon2.hire(dummy) << millenniumFalcon2.hire(dummy);
  dummy.make_expedition(Planet::Vulcan);
  cout << millenniumFalcon2.hire(dummy) << millenniumFalcon2.hire(spock) << millenniumFalcon2.hire(dummy) << '\n';
  cout << millenniumFalcon2 << '\n';
}
  //Basisfunktionalitaet Ende


  //Zusatz 10 Punkte
/** Erwartete Ausgabe
Error1
[Han Solo: 100, Vulcan]
Error2
[Han Solo: 100, Coruscant]
Error3
[Han Solo: 0, Corellia]
[Han Solo: 100, Kashyyyk]
[Han Solo: 100, Kashyyyk]
[Han Solo: 100, Corellia]
[Han Solo: 100, Corellia]
10100
1101
[Chewbacca: 99, Kashyyyk]
1
[S'chn T'gai Spock: 100, Vulcan]
01010
000
Error7
[MillenniumFalcon, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 90, Kashyyyk]}, Corellia]
Error9
Error10
Error11
[MillenniumFalcon2, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 99, Kashyyyk], [Lando Calrissian: 65, Corellia]}, Coruscant]
[MillenniumFalcon2, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 99, Kashyyyk], [Lando Calrissian: 65, Corellia]}, Coruscant]
[MillenniumFalcon, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 90, Kashyyyk]}, Corellia]
01110110
[MillenniumFalcon2, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 99, Kashyyyk], [Lando Calrissian: 65, Corellia], [Boba Fett: 44, Kashyyyk], [Dengar: 0, Kashyyyk], [Dengar: 5, Kashyyyk], [S'chn T'gai Spock: 100, Vulcan]}, Coruscant]


Zusatz fuer 10 Punkte
[MillenniumFalcon, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 90, Kashyyyk]}, Corellia]
[Test3: 76, Corellia]
[MillenniumFalcon, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 100, Kashyyyk], [Test1: 75, Kashyyyk], [Test2: 72, Corellia], [Test3: 76, Corellia]}, Corellia]
[Test1: 80, Kashyyyk]
[Test4: 79, Vulcan]
[MillenniumFalcon, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 100, Kashyyyk], [Test1: 80, Kashyyyk], [Test2: 74, Corellia], [Test3: 78, Corellia], [Test4: 79, Vulcan]}, Corellia]
[MillenniumFalcon, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 100, Kashyyyk], [Test1: 80, Kashyyyk], [Test2: 74, Corellia], [Test3: 78, Corellia], [Test4: 79, Vulcan]}, Corellia]
[MillenniumFalcon2, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 99, Kashyyyk], [Lando Calrissian: 70, Corellia], [Boba Fett: 49, Kashyyyk], [Dengar: 5, Kashyyyk], [Dengar: 10, Kashyyyk], [S'chn T'gai Spock: 100, Vulcan]}, Coruscant]


Zusatz fuer 15 Punkte
[A-Team, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 90, Kashyyyk], [Wedge Antilles: 85, Corellia]}, Coruscant]
[MC-80, Crew: {[Admiral Ackbar: 100, Kashyyyk], [Willhuff Tarkin: 100, Kashyyyk], [Talon Karrde: 100, Kashyyyk]}, Corellia]
**/
