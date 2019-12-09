#include "calender.h"
#include <map>

/*Calender_t::~Calender_t()
{
    iter it;
    Meeting_t *meet;
    it = CalenderCont.begin();
    while (it != CalenderCont.end())
    {
        meet = it->second;
        CalenderCont.erase(it);
        it++;
        delete meet;
    }
}*/
bool Calender_t::insertMeeting(Meeting_t *meet)
{
    iter it;
    if (CalenderCont.begin() == CalenderCont.end())
    {
        CalenderCont[meet->getStart()] = meet;
        return true;
    }
    it = CalenderCont.begin();
    Meeting_t *M = it->second;
    if (meet->getEnd() < M->getStart())
    {
        CalenderCont[meet->getStart()] = meet;
        return true;
    }
    it = CalenderCont.end();
    it--;
    M = it->second;
    if (meet->getStart() > M->getEnd())
    {
        CalenderCont[meet->getStart()] = meet;
        return true;
    }
    it = CalenderCont.begin();
    M = it->second;
    it++;
    Meeting_t *NM = it->second;
    while (it != CalenderCont.end())
    {
        if (meet->getStart() > M->getEnd() && meet->getEnd() < NM->getStart())
        {
            CalenderCont[meet->getStart()] = meet;
            return true;
        }
        it++;
        M = it->second;
        NM = it->second;
    }
    return false;
}
bool Calender_t::deleteMeeting(float startMeet)
{
    iter it;
    try
    {
        it = CalenderCont.find(startMeet);
        CalenderCont.erase(it);
        return true;
    }
    catch (...)
    {
        return false;
    }
}
Meeting_t *Calender_t::findMeeting(float start_hour)
{
    iter it;
    if (start_hour != 0)
    {
        it = CalenderCont.find(start_hour);
        if(it!=CalenderCont.end())
        {
        return it->second;
        }
    }
    return NULL;
}
void Calender_t::cleanCalender()
{
    CalenderCont.clear();
}
void Calender_t::printCalender()
{
    iter it = CalenderCont.begin();
    while (it != CalenderCont.end())
    {
        it->second->printMeet();
        it++;
    }
}
