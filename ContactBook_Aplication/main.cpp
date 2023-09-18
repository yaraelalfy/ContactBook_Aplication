#include <iostream>
#include"contactbook.h"
using namespace std;
int main()
{
    cout<<"\t\t\t\t\t\t\tWelcome !\n";
    int c=-1;
//create contact object
    ContactBook cont(100);//100 users
    while(c!=0)
    {

        cout<<"\n_______________________________________________________"

            <<"_______________________________________________________\n"
            <<"1.print all users\n"
            <<"2.add new user\n"
            <<"3.search\n"
            <<"4.edit existing user\n"
            <<"5.delete existing user\n"
            <<"0.quit\n"
            <<"enter your choice:";
        cin>>c;

        cout<<"_______________________________________________________"

            <<"_______________________________________________________\n";
        switch(c)
        {
        case 1:
            //print all users;
            cont.print();
            break;
        case 2:
            //add new users;
            cont.addnewcontact();
            break;
        case 3:
            //search for a user / users
        {
            string key;
            cout<<"Enter your keyword to find : ";
            cin.ignore();
            getline(cin,key);
            cont.findall(key);
        }
        break;
        case 4:
            //edit user
        {
            int edit_id=0;
            cout<<"Enter contact id to edit : \n";
            cin>>edit_id;
            cont.editcontact(edit_id);
        }
        break;
        case 5:
            //delete user
            int del_id=0;
            cout<<"Enter contact id to delete : \n";
            cin>>del_id;
            cont.detcontact(del_id);
            break;
        }
    }
    cout<<"\n\n\t\t\t\t\t\t\tThanks \03!";
    return 0;
}
