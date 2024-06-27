#include<iostream>
#include<CustomerMgmt.hpp>
#include<fstream>
#include<sstream>
using namespace std;
vector<Customer> customerList;
vector<Customer> customerListTemp;
void CustomerMgmt::addUser(Customer cust){
    customerListTemp.push_back(cust);
}

bool CustomerMgmt:: removeUser(string id){
    if(customerList.empty())
        return false;
    for(int i=0;i<customerList.size();i++){
        if(customerList[i].getuserId() == id){
            customerList.erase(customerList.begin()+i);
            return true;
        }
    }
    return false;
}

void CustomerMgmt::viewUser(string id){
    for(int i=0;i<customerList.size();i++){
        if(customerList[i].getuserId() == id)
        {
            cout<<customerList[i].getfirstName()<<" "<<customerList[i].getlastName()<<endl;
            break;
        }
    }
}

bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

void CustomerMgmt::loadUserIntoFile(){
    bool file_check=is_file_exist("Customer.txt");
    if(!file_check)
    return;
    else
    {
        fstream file;
        file.open("customer.txt");
        string line, temp;
        while(!file.eof())
        {
            string userName,firstName,lastName,date,creditCardNumber,userId;
            int rewardPoints;
            getline(file,line);
            if(line.size()==0)
                return;
            stringstream ss(line);
            ss>>userName;
            ss>>firstName;
            ss>>lastName;
            ss>>date;
            ss>>creditCardNumber;
            ss>>userId;
            ss>>rewardPoints;
            Customer c(userName,firstName,lastName,date,creditCardNumber,userId,rewardPoints);
            customerList.push_back(c);
        }

        file.close();
    }
    
}
void CustomerMgmt::saveUserToFile(){
    ofstream fileout;
    fileout.open("customer.txt");
    for(int i=0;i<customerList.size();i++)
    {
        fileout<<customerList[i].getUserName()<<" "<<customerList[i].getfirstName()<<" "<<customerList[i].getlastName()<<" ";
        fileout<<customerList[i].getdate()<<" "<<customerList[i].getcreditCardNumber()<<" "<<customerList[i].getuserId()<<" "<<customerList[i].getrewardPoints()<<endl;
    }
    for(int i=0;i<customerListTemp.size();i++)
    {
        fileout<<customerListTemp[i].getUserName()<<" "<<customerListTemp[i].getfirstName()<<" "<<customerListTemp[i].getlastName()<<" ";
        fileout<<customerListTemp[i].getdate()<<" "<<customerListTemp[i].getcreditCardNumber()<<" "<<customerListTemp[i].getuserId()<<" "<<customerListTemp[i].getrewardPoints()<<endl;
    }
    fileout.close();
}
bool CustomerMgmt::isUniqueUser(string uName){ 
    for(int i=0;i<customerList.size();i++)
    {
        if(customerList[i].getUserName()==uName)
            return false;
    }
    return true;
}

CustomerMgmt::CustomerMgmt()
{
    
}

CustomerMgmt::~CustomerMgmt()
{
}
