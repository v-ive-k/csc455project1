#ifndef CUSTOMER_MGMT_HPP
#define CUSTOMER_MGMT_HPP
#include <Customer.hpp>
#include <vector>
#include<string>
using namespace std;
class CustomerMgmt
{
private:
    string customerFile;
    // vector<Customer> customerList;
public:
    CustomerMgmt();
    ~CustomerMgmt();
    void loadUserIntoFile();
    void addUser(Customer c);
    bool removeUser(string id);
    void viewUser(string id);
    void saveUserToFile();
    bool isUniqueUser(string uName);
    string getUserName(string uName);
};
#endif