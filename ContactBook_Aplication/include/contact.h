#include <ctime>
#include <string>
#include <iostream>
#include"phonenumber.h"
using namespace std;
#ifndef CONTACT_H
#define CONTACT_H
class contact
{
public:
    contact();
    virtual ~contact();
    void print()const;
    void readinput();
    void setcontact_id(int);
    void setfirstname(string);
    void setlastname(string);
    void setage(int);
    void setgender(int);
    void setcity(string);
    void setNote(string);
    int getcontact_id()const;
    bool findany(string) const;
private:
    int m_id;
    string m_fname,m_lname,m_city,m_note;
    int m_age;
    int m_gender; //0-male 1-female
    time_t m_added;
    phonenumber *m_phones;
    int m_phone_size;
    int m_phone_count;
};
#endif // CONTACT_H
