#include "person.h"

work_state person::change_state() 
{
	ws =  work_state::used;
	return ws;
}
