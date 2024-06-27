#include<string>
using namespace std;
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <string>
using namespace std;
class Customer{
    private:
        string userName;
        string firstName;
        string lastName;
        string date;
        string creditCardNumber;
        string userId;
        int rewardPoints;
    public:
        bool createCustomer(void);
        bool validateUserName(string name);
        Customer();
        Customer(string userName,string firstName,string lastName,string date,string creditCardNumber,string userId,int rewardPoints);
        string getUserName(void);
        string getfirstName(void);
        string getlastName(void);
        string getdate(void);
        string getcreditCardNumber(void);
        string getuserId(void);
        int getrewardPoints(void);
};
#endif