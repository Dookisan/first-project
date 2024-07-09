#pragma once
#include<iostream>
#include"person.h"
#include"Ek.h"
#include<algorithm>
#include<vector>
#include"create.h"


class team 
{
private: 
    
	Ek* leader; 
    int anzahl; 

public: 
    team() = default;
			                                                                        //Was ist wenn ein team member asugetausscht werden soll
   
    std::vector<person*> members;
    int get_anzahl() { return anzahl; }
    void addMember(person* member); 
    void setTeamLeader(Ek* newleader); 
    void display() const;
                                                                                          //Fürs nächste mal immer setters und getters einbauen
    void replace_member(person* oldMember, person* newMember, int memberIndex);
    void replace_leader(Ek* newleader);
    
    
};

