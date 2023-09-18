
#include"phonenumber.h"
#include "contact.h"
contact::contact()
{
    m_phone_size=5;
    m_phones= new phonenumber[m_phone_size];
    m_phone_count=0;
    m_added=time(0);
    m_gender=0;
    m_age=0;
}
contact::~contact()
{
    delete[]m_phones;
}
void contact:: print()const
{
    cout<<"-------------------------------------------\n";
    cout<<"ID : "<<m_id<<"\tNAME : "<<m_fname<<" "<<m_lname<<"\t| city : "<<m_city;
    if(m_age>0)
        cout<<"\t\t| AGE : "<<m_age<<"\n";
    cout<<"\tNote : "<<m_note<<"\t";
    cout<<(m_gender==0?"\n\tMALE":"\n\tFEMALE")<<endl;
    if(m_phone_count>0)
    {
        cout<<"\tPHONE LIST : \n";
        for(int i=0; i<m_phone_count; ++i)
        {
            cout<<"\t"<<i+1<<" - ";
            m_phones[i].print();
        }
    }
    cout<<endl;
}
void contact:: readinput()
{
    cout<<"Enter User Information :-\n";
    cout<<"First Name : ";
    cin.ignore();
    getline(cin,m_fname);
    cout<<"last name : ";
    getline(cin,m_lname);
    cout<<"city : ";
    getline(cin,m_city);
    cout<<"Note : ";
    getline(cin,m_note);
    cout<<"Age : ";
    cin>>m_age;
    cout<<"Gender (0-male,1-female) :";
    cin>>m_gender;
    int n=0;
    cout<<"How many phones (0-"<<m_phone_size<<")?";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; ++i)
    {
        cout<<"-------------------------------\n";
        string data,type,desc;
        cout<<"phone number ("<<i+1<<") : ";
        getline(cin,data);
        cout<<"type : ";
        getline(cin,type);
        //create new phone object
        phonenumber * new_phone = new phonenumber(data,type);
        m_phones[m_phone_count++]=*new_phone;
    }
}
void contact:: setcontact_id(int id)
{
    m_id=id;
}
void contact:: setfirstname(string firstname)
{
    m_fname=firstname;
}
void contact:: setlastname(string lastname)
{
    m_lname=lastname;
}
void contact:: setcity(string city)
{
    m_city=city;
}
void contact:: setNote(string note)
{
    m_note=note;
}
void contact:: setage(int age)
{
    m_age=age;
}
void contact:: setgender(int gender)
{
    m_gender=gender;
}
int contact:: getcontact_id()const
{
    return m_id;
}
bool contact:: findany(string key) const
{
    if(m_fname.compare(key)==0||m_lname.compare(key)==0)
    {
        return true;
    }
    if(m_phone_count>0)
    {
        //search in phones
        for(int i=0; i<m_phone_count; ++i)
        {
            if(m_phones[i].ismatched(key))
                return true;
        }
    }
    return false;
}
