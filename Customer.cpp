#include <bits/stdc++.h>
#include<Customer.hpp>
#include<CustomerMgmt.hpp>
using namespace std;

bool isValidUserName(string uName){
    if(uName.length()>11)
        return false;
    else
    {
        int countAlpha=0, countDigit=0;
        for(int i=0;i<uName.length();i++)
        {
            if(!(isalpha(uName[i])))
                return false;
            else
            {
                countAlpha++;
                if(countAlpha>8)
                    return false;
            }
        }
       reverse(uName.begin(),uName.end());
       for(int i=0;i<uName.length();i++)
       {
            if(isdigit(uName[i]))
            {
                countDigit++;
                if(countDigit>3)
                    return false;
            }
       }
       return true;

    }
}
bool isValidName(string name)
{
    if(name.length()>15)
        return false;
    else
    {
        for(int i=0;i<name.length();i++)
        {
            if(!isalpha(name[i]))
            {
                return false;
            }
        }
        return true;
    }
}
Customer:: Customer(string uName,string fName,string lName,string dte,string credN,string uId,int rPoints)
{
    userName=uName;
    firstName=fName;
    lastName=lName;
    date=dte;
    creditCardNumber=credN;
    userId=uId;
    rewardPoints=rPoints;
}
Customer:: Customer()
{
    
}
bool Customer:: validateUserName(string name)
{
    CustomerMgmt cm;
    if(isValidUserName(name) && cm.isUniqueUser(name))
    return true;
    else
    return false;
}

 bool Customer::createCustomer(void){
    string Uname,fName,lName,date,credit_card_number,id;
    int reward_point;
    cout<<"Enter User Name "<<endl;
    cin>>Uname;
    bool validateUName = validateUserName(Uname);
    cout<<"Enter firstName"<<endl;
    cin>>fName;
    bool validateFName = isValidName(fName);
    cout<<"Enter last Name"<<endl;
    cin>>lName;
    bool validateLName = isValidName(lName);
    cout<<"Enter date of birth"<<endl;
    cin>>date;
    cout<<"Enter credit Card Number"<<endl;
    cin>>credit_card_number;
    cout<<"Enter user id"<<endl;
    cin>>id;
    id.insert(0,"CID");
    cout<<"Enter reward point"<<endl;
    cin>>reward_point;
    if(validateUName && validateFName && validateLName )
    {
        *this = Customer(Uname,fName,lName,date,credit_card_number,id,reward_point);
        return true;
    }
    else
    return false;
}

string Customer:: getuserId(void){
    return userId;
}
string Customer:: getUserName(void){
    return userName;
}
string Customer:: getfirstName(void){
    return firstName;
}
string Customer:: getlastName(void){
    return lastName;
}
string Customer:: getdate(void){
    return date;
}
string Customer:: getcreditCardNumber(void){
    return creditCardNumber;
}
int Customer:: getrewardPoints(void){
    return rewardPoints;
}
