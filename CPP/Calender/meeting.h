#ifndef MEETING_H
#define MEETING_H
#include <iostream>
#include <string>
using namespace std;

class Meeting_t
{
public:
    Meeting_t(float start, float end, string msg);
    virtual ~Meeting_t() {}
    float getStart() const { return m_start; }
    float getEnd() const { return m_end; }
    string getMeetSubject() const { return m_message; }
    void printMeet()const;

private:
    Meeting_t(const Meeting_t &t) {}
    Meeting_t &operator=(const Meeting_t &t) {}
    float m_start;
    float m_end;
    string m_message;
};

#endif // !MEETING_H