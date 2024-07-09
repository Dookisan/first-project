#include "team.h"

void team::addMember(person* member)
{
	members.push_back(member);
}

void team::setTeamLeader(Ek* newleader)
{
	leader = newleader;
}

void team::display() const
{
    std::cout << "Team Members:" << std::endl;
    for (auto& member : members) {
        member->print();
    }
    if (leader) {
        std::cout << "Team Leader:" << std::endl;
        leader->print();
    }
}


void team::replace_member(person*oldMember, person* newMember, int memberIndex)
{
    if (memberIndex < 0 || memberIndex >= members.size()) {
        std::cout << "Ungültiger Teamindex" << std::endl;
        return;
    }
    std::cout << "Mitglied ersetzt: " << newMember->get_name() << " an Position " << memberIndex << std::endl;
    members[memberIndex] = newMember;
    
}

void team::replace_leader(Ek* newleader)
{

    leader = newleader;
}




