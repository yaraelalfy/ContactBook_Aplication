#include "contactbook.h"
ContactBook::ContactBook(int contact_size)
{
    m_size =contact_size;
    m_contacts =new contact[m_size];
    m_count=0;
}
ContactBook::~ContactBook()
{
    delete[] m_contacts;
}
void ContactBook:: addnewcontact()
{
    contact*new_contact = new contact();
    new_contact -> setcontact_id (m_count+1);
    new_contact -> readinput();
    m_contacts[m_count++]=*new_contact;
}
void ContactBook:: detcontact(int contact_id)
{
    if(m_count==0)
    {
        cout<<"No contact Exist ~!\n";
        return ;
    }
    bool deleted=false;
    for(int i=0; i<m_count ; ++i)
    {
        if(m_contacts[i].getcontact_id()==contact_id)
        {
//delete from array
            if(i==m_count-1)
            {
                m_count--;
            }
            else
            {
//replace deleted with last contact
                m_contacts[i]=m_contacts[m_count-1];
                m_count--;
            }
            deleted=true;
            break;
        }
    }
    if(deleted)
    {
        cout<<"contact deleted sucessfully ! \n";
    }
    else
    {
        cout<<"no contact exist \n";
    }
}
void ContactBook:: editcontact(int contact_id)
{
    if(m_count==0)
    {
        cout<<"No contact Exist ~!\n";
        return ;
    }
    bool edited=false;
    for(int i=0; i<m_count ; ++i)
    {
        if(m_contacts[i].getcontact_id()==contact_id)
        {
            m_contacts[i].readinput();
            edited=true;
            break;
        }
    }
    if(edited)
    {
        cout<<"contact edited successfully ! \n";
    }
    else
    {
        cout<<"no contact exist \n";
    }
}
void ContactBook:: print()const
{
    if(m_count==0)
    {
        cout<<"No contact found ! \n";
        return;
    }
    for(int i=0; i<m_count ; ++i)
    {
        m_contacts[i].print();
    }
}
void ContactBook:: findall(string key)const
{
    int found_counter=0;
    for(int i=0; i<m_count ; ++i)
    {
        if(m_contacts[i].findany(key))
        {
            m_contacts[i].print();
            found_counter++ ;
        }
    }
    if(found_counter==0)
    {
        cout<<"No contact founded!\n";
    }
    else
    {
        cout<<found_counter<<"fonded!\n";
    }
}
