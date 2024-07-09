#pragma once
#include <iostream>
#include"create.h"
#include "team.h"
using namespace std;

class control
{
private: 
    std::vector<team> teams;
public:
    control() {
        start();
    }
   
    void start();
    std::vector<team>& getTeams() {
        return teams;
    }
    std::vector<team> makeTeams(int anzahl, create& creator);
	
    void manage_teams(create& creator);
    
};

