#include "phonenumber.h"
phonenumber::phonenumber()
{
}
phonenumber::phonenumber(string phone_num,string Type_num)
{
    setphone(phone_num);
    settype(Type_num);
}
phonenumber::~phonenumber()
{
}
void phonenumber:: setphone(string phone_num)
{
    m_phone=phone_num;
}
void phonenumber:: settype(string Type_num)
{
    m_type=Type_num;
}
bool phonenumber:: ismatched (string key) const
{
    return (m_phone.compare(key)==0);
}
void phonenumber:: print()const
{
    cout<<"Phone : "<<m_phone<<"\t |"<<m_type<<endl;
}
