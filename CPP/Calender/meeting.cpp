#include "meeting.h"


Meeting_t::Meeting_t(float start, float end, string msg)
{
    if (start >= 24 || start < 0)
    {
        throw string("Not invalid start hour");
    }
    if (end >= 24 || end < 0)
    {
        throw string("Not invalid end hour");
    }
    if (end < start)
    {
        throw string("cant end before start");
    }
    m_start=start;
    m_end=end;
    m_message=msg;
}
void Meeting_t::printMeet()const
{
    cout<<m_start<<" ";
    cout<<m_end<<" ";
    cout<<m_message<<endl;
}