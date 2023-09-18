#include"contact.h"
#include <string>
#include <iostream>
using namespace std;
#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
class ContactBook
{
public:
    ContactBook(int);
    virtual ~ContactBook();
    void addnewcontact();
    void detcontact(int);
    void editcontact(int);
    void print()const;
    void findall(string)const;
private:
    int m_count;
    int m_size;
    contact *m_contacts;
};
#endif // CONTACTBOOK_H
