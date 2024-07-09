#include "create.h"
#include<fstream>

std::vector<std::string> create::get_names()
{
	std::ifstream import ("E:Uni/Informatik/Projekte/members.txt"); 
	if (!import.fail()) {
		while (std::getline(import, line)) {				//lese eine Line nach der anderen ein und speicher sie in einen vector
			names.push_back(line); 
		}
		import.close(); 
	}
	else
	{
		std::cerr << "Die Datei konnte nicht ge�ffnet werden" << std::endl; 
		exit(-1);											//Wird auch immer als standart R�ckgabe gegeben mir war grad danach :)
	}
	return names;
}														//kein �bereinstimmendes Token ist meistens ne Fehlende Klammer 


std::vector<int> create::availability()
{
	int number = 0; 

	std::srand(std::time(NULL));						//ctime gibt einen Zeiger zur�ck 

	for ( int j = 0; j < 20; j++)
	{
		number = std::rand() % (6);					// if rand == 0 work_state::available 
		dienstzahl.push_back(number);
	}
	return dienstzahl; 
		
}

void create::Person(int index, std::vector<person>& persons)
{																			//Vector auf zeiger welche verschiedene Objecte speichern
	names = get_names();
	dienstzahl = availability();
	persons.push_back(person(names[index], dienstzahl[index]));			//persons.push_back(new Ek(names[i], dienstzahl[i], work_state::ek));
		
}

void create::Einsatzkraft(int index, std::vector<Ek>& einsatzkraefte)
{
	names = get_names();
	dienstzahl = availability(); 
	einsatzkraefte.push_back(Ek(names[index], dienstzahl[index], work_state::ek));
}

void create::assign()
{
	for (int i = 0; i < 20; i++) {
		if (((i + 1) % 4 == 0)) {
			Einsatzkraft(i, einsatzkraefte);							//EK
		}
		else {
			Person(i, persons); 									//Person 
		}
	}
}
std::vector<person>& create::getPersons()
{
	std::sort(persons.begin(), persons.end(), [](person& a, person& b) {
		return a.get_dienst() < b.get_dienst();
		});
	return persons;
}
std::vector<Ek>& create::getEinsatzkraefte()
{
	std::sort(einsatzkraefte.begin(), einsatzkraefte.end(), [](Ek& a, Ek& b) {
		return a.get_dienst() < b.get_dienst();
		});
	return einsatzkraefte;
}

void create::printvectors() const {
	// Ausgabe der Vektoren zur �berpr�fung

	std::cout << "Persons:" << std::endl;
	for (const auto& person : persons) {
		person.print();
	}

	std::cout << "Einsatzkraefte:" << std::endl;
	for (const auto& ek : einsatzkraefte) {
		ek.print();
	}
}
