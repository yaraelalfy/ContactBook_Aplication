#include<string>
#include <iostream>
using namespace std;
#ifndef PHONENUMBER_H
#define PHONENUMBER_H
class phonenumber
{
public:
    phonenumber();
    ~phonenumber();
    phonenumber(string,string);
    void setphone(string);
    void settype(string);
    bool ismatched (string) const;
    void print()const;
private:
    string m_phone,m_type;
};
#endif // PHONENUMBER_H
