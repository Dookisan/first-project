#include"control.h"

void control::start()
{
    {
        int index = 0;
        team myteam;
        cout << "Wieviele teams sollen erstellt werden?" << endl;
        cin >> index;
        create creator;
        //creator.assign();
        creator.printvectors();
        teams = makeTeams(index, creator);
        manage_teams(creator);
    }
}

std::vector<team> control::makeTeams(int anzahl, create& creator)
{
	{
		int ekindex = 0;
		int personindex = 0;
		
		creator.assign();

		std::vector<person>& persons = creator.getPersons();                          //Neue idee es wird ein weiterer vector genutzt, dieser weißt jeden wert ein bool true und false zu, dieser sagt ob eine person schon verwendet wurde 
		std::vector<Ek>& einsatzkraefte = creator.getEinsatzkraefte();
		std::vector<team> teams;

		for (int y = 0; y < anzahl; y++) {
			team myTeam;
			int personAdded = 0;

			if (!einsatzkraefte.empty()) {
				myTeam.setTeamLeader(&einsatzkraefte[y]);
				//Vector mit mehreren Teams erstellen, dann sollte beides Funktionieren
			}
			while (personindex < persons.size() && personAdded < 3) {
				//if (persons[personindex].get_status() != work_state::used) {
					myTeam.addMember(&persons[personindex]);
					persons[personindex].change_state();

					personAdded++;

				//}
				personindex++;
				//std::cout << personindex << std::endl;
			}
			teams.push_back(myTeam);
            //personindex= 0;
		}
		for (int i = 0; i < teams.size(); i++) {
			std::cout << "\nTeam: " << i + 1 << "\n" << std::endl;
			teams[i].display();
		}
		return teams;

	}
    
}

void control::manage_teams(create& creator)
{
    {

        std::vector<person>& persons = creator.getPersons();
        std::vector<Ek>& ek = creator.getEinsatzkraefte();

        std::string m_replacement;
        char choice;

        std::cout << "Wolles Sie ein Team aendern? (y/n) " << std::endl;
        std::cin >> choice;

        while (choice == 'y' || choice == 'Y') {                                         //Anmerkung: "" const char ; '' normales char; vielleicht nützlich 
            std::cout << "Welches Team wollen Sie aendern? " << std::endl;
            int teamnum = 0;
            do {
                
                std::cin >> teamnum;
                if (teamnum < 1 || teamnum > teams.size()) {
                    std::cout << "Ungueltiger Teamindex" << std::endl;
                }
                
            } while (teamnum < 1 || teamnum > teams.size());
            teamnum--;

            std::cout << "Wollen sie eine Einsatzkraft oder ein Member bearbeiten (E/m)" << std::endl;

            char choicetwo;
            do{
            
            std::cin >> choicetwo;
            
            switch (choicetwo)
            {

            case 'm':{
                int memberIndex = -1;
                person* new_member = nullptr;
                person* old_member = nullptr;


                std::cout << "Welches Member soll geaender werden" << std::endl;
                std::cin >> m_replacement;
                m_replacement.erase(m_replacement.find_last_not_of(" \n\r\t") + 1);



                for (int i = 0; i < teams[teamnum].members.size(); ++i) {
                    if (teams[teamnum].members[i]->get_name() == m_replacement) {
                        memberIndex = i;
                    
                        old_member = teams[teamnum].members[i];
                        break;
                    }
                    else {
                        std::cout << "ungueltiger Name" << std::endl;
                        break;
                    }
                }

                if (old_member) {
                    int newMemberIndex = 0;

                    std::cout << "Welches newe Member soll hinzugefuegt werden: Index Eingeben" << std::endl;
                    std::cin >> newMemberIndex;
                    newMemberIndex--;
                    person* new_member = &creator.getPersons()[newMemberIndex];
                    teams[teamnum].replace_member(old_member, &creator.getPersons()[newMemberIndex], memberIndex);

                }
                else {
                    std::cout << "Memberindex nicht korrekt" << std::endl;

                }
                break; 
            }
                case 'E':{
                    int ekindex = 0;
                    Ek* new_ek = nullptr;
                    std::cout << " Zu welcher Einsatzkraft soll geaendert werden (Index)" << std::endl;
                    std::cin >> ekindex;
                    ekindex--; 
                    
                    new_ek = &creator.getEinsatzkraefte()[ekindex];
                    teams[teamnum].replace_leader(new_ek);
                    break;
               
                }
                default: {
                    std::cout << "Ungueltiger Index" << std::endl;
                   
                }
            }
            } while (choicetwo != 'E' && choice != 'm');

            for (int z = 0; z < teams.size(); z++) {
                std::cout << "\nTeam: " << z + 1 << "\n" << std::endl;
                teams[z].display();
            }
            std::cout << "Wollen Sie weiter veraendern?" << std::endl;
            std::cin >> choice;
        }


    }
}
