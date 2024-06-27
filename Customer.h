#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <cstring>
#include <regex>
#include <fstream>
#include <ctime>
#include "CustomerClass.h"

/*
Looping through customers.txt file to ensure username is unique
line - string used to loop through file
count - int used to determine if there is a match to the input string
myfile - ifstream variable used to hold reference to customer text file
*/
bool unique(std::string input)
{
    std::string line;
    int count = 0;
    std::ifstream myfile("customers.txt");

    while (getline(myfile, line))
    {
        if (line.find(input) != std::string::npos)
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    myfile.close();

    if (count > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
/*
Function used to check to see if a credit card number is already in the creditcard text file
line - string used to loop through the credit card text file
count - used to determine in if the input credit card number is in the text file
myfile - used to hold reference to the credit card text file
*/

bool uniqueCC(std::string input)
{
    std::string line;
    int count = 0;
    std::ifstream myfile("creditcard.txt");

    while (getline(myfile, line))
    {
        if (line.find(input) != std::string::npos)
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    myfile.close();

    if (count > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*
Function used to generate a random Customer ID
CID - string used to hold the first three letters of the ID
*/
std::string GenID()
{
    std::string CID = "CID";
    srand((unsigned)time(0));
    for (int t = 0; t <= 9; t++)
    {
        int RandNum = rand() % 10;
        CID += std::to_string(RandNum);
    }
    return CID;
}


/* 
This Function Checks if Username is in Correct Format
ulCheck - regex variable used to hold the format for checking a user name 
*/
bool userCheck(std::string c)
{

    std::regex uCheck("^[a-zA-Z]{8,}[0-9]{3}$"); // Regex expression for username format
    if (regex_match(c, uCheck))                  // Checks if user input matches regex expression
    {
        if (unique(c) == true)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

/* 
This Function Loops through until it recieves a Valid Username
User - string used for the input of the user
*/
std::string createUser()
{
    std::string User;
    std::cout << "Enter Username: ";
    std::cin >> User;
    userCheck(User);
    // while (userCheck(User) && unique(User) == false)
    while (userCheck(User) == false)
    {
        std::cout << "Please Enter Valid Username: ";
        std::cin >> User;
        userCheck(User);
    }
    return User;
}

/* 
This Function Checks if Username is in Correct Format
fnCheck - regex variable used to hold the regex name format
*/
bool nameCheck(std::string c)
{
    std::regex fnCheck("^[a-zA-Z]{1,15}"); 
    if (regex_match(c, fnCheck))           
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 
This Function Loops through until it recieves a Valid First Name
Fname - string used to hold the user input
*/
std::string createFname()
{
    std::string Fname;
    std::cout << "Enter First Name: ";
    std::cin >> Fname;
    nameCheck(Fname);
    while (nameCheck(Fname) == false)
    {
        std::cout << "Please Enter Valid First Name: ";
        std::cin >> Fname;
        nameCheck(Fname);
    }
    return Fname;
}

/*
This Function Loops through until it recieves a Valid Last Name
Lname - string used to hold the user input
 */
std::string createLname()
{
    std::string Lname;
    std::cout << "Enter Last Name: ";
    std::cin >> Lname;
    nameCheck(Lname);
    while (nameCheck(Lname) == false)
    {
        std::cout << "Please Enter Valid Last Name: ";
        std::cin >> Lname;
        nameCheck(Lname);
    }
    return Lname;
}

/* 
This Function Checks if Birthday is in Correct Format
BirthCheck - regex variable used to hold the regext expression for checking date of birth
*/
bool dobCheck(std::string c)
{
    std::regex BirthCheck("^(1[0-2]|0[1-9])-(3[01]|[12][0-9]|0[1-9])-[0-9]{4}$"); 
    if (regex_match(c, BirthCheck))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 
This Function Loops through until it recieves a Valid Birthday
Bday - string used to hold user input for Birthday
*/
std::string createBday()
{
    std::string Bday;
    std::cout << "Enter Date of birth: ";
    std::cin >> Bday;
    dobCheck(Bday);
    while (dobCheck(Bday) == false)
    {
        std::cout << "Please Enter Valid Birthday: ";
        std::cin >> Bday;
        dobCheck(Bday);
    }
    return Bday;
}

/*
This Function Checks if Credit Card is in correct format
CheckCredit - regex variable used to compare the credit card number format
*/
bool ccCheck(std::string c)
{
    std::regex CheckCredit("[0-9]{4}-[0-9]{4}-[0-9]{4}");
    if (regex_match(c, CheckCredit))
    {
        if (uniqueCC(c) == true)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

/* 
This Function Loops through until it recieves a Valid CreditCard number
CCnum - string used to hold credit card number input by user
*/
std::string createCC()
{
    std::string CCnum;
    std::cout << "Enter Credit Card: ";
    std::cin >> CCnum;
    ccCheck(CCnum);
    while (ccCheck(CCnum) == false)
    {
        std::cout << "Please Enter Valid Credit Card Number: ";
        std::cin >> CCnum;
        ccCheck(CCnum);
    }
    return CCnum;
}

/* 
This Function Checks if point is positive integer
CheckPoints - regex variable used for checking the points input are in the right format
*/
bool pCheck(std::string c)
{
    std::regex CheckPoints("[1-9][0-9]*");
    if (regex_match(c, CheckPoints))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
This Function Loops through until it recieves a Valid # for Points
point - variable used for holdeing the user input
*/
std::string createPoint()
{
    std::string point;
    std::cout << "Enter Customer Total Points: ";
    std::cin >> point;
    pCheck(point);
    while (pCheck(point) == false)
    {
        std::cout << "Please Enter Valid Point Number: ";
        std::cin >> point;
        pCheck(point);
    }
    return point;
}

// This Function Puts All Parts Of Customer Registration Together.
//cFile - ofstream variable that holds the write file reference for customers.txt
//creditFile - ofstream variable that holds the write file reference for creditcard.txt
void CreateCustomer()
{
    std::ofstream cFile("customers.txt", std::ios::app);
    std::ofstream creditFile("creditcard.txt", std::ios::app);

    cFile << GenID() << "\n";
    cFile << createUser() << "\n";
    cFile << createFname() << "\n";
    cFile << createLname() << "\n";
    cFile << createBday() << "\n";
    creditFile << createCC() << "\n";
    cFile << createPoint() << "\n";
    cFile << "\n";
    cFile.close();
}

//Function used for getting the customer ID from the user
//CustID - variable used for holding the user input
std::string GetCustID()
{
    std::string CustID;

    std::cout << "Please enter Customer ID" << std::endl;

    while (true)
    {
        std::cout << "Enter: ";
        while (!(std::cin >> CustID))
        {
            // std::cin.clear();
            // std::cin.ignore(123, '\n');
            std::cout << "Enter: ";
        }

        if (!(regex_match(CustID, std::regex("CID[0-9]{10}"))))
        {
            std::cout << "Please enter a valid Customer ID" << std::endl;
            continue;
        }
        else
        {
            break;
        }
    }

    return CustID;
}

//Function used for deleting a customer from the customer text file
//CustID - string used for storing the customer ID
//CustFile - ifstream variable used for holding the read reference to customers.txt
//Tempo - ofstream variable used for holding the write reference to temp.txt
//line - string used to loop through the text file
//found - boolean used to determine if the customer is found in the text file
//Dec - int used to depricate to determince the place in the specific customer within the file
//rx - variable used to hold the regex of the customer ID
void DeleteCustomer()
{

    std::string CustID = GetCustID();

    // Open files for reading and writing
    std::ifstream CustFile("customers.txt");
    std::ofstream Temp("temp.txt");

    // Decalre variables
    std::string line;
    bool found;
    int Dec = 0;
    std::regex rx(CustID);

    // Loops through file looking for id to delete info
    while (getline(CustFile, line))
    {
        if (regex_search(line, rx))
        {
            found = true;
        }
        else
        {
            found = false;
        }

        if (!found && Dec <= 0)
        {
            Temp << line << "\n";
        }
        else
        {
            switch (Dec)
            {
            case 0:
            {
                Dec = 6;
                break;
            }

            default:
            {
                --Dec;
                break;
            }
            }
        }
    }

    // closes and renames files
    CustFile.close();
    Temp.close();
    std::remove("customers.txt");
    std::rename("temp.txt", "customers.txt");
}

//Function used to print out customer information
void CustomerProfile()
{
    Customer Cust(GetCustID());
    std::cout << "\n";
    std::cout << "Customer Profile: "
              << "\n";
    std::cout << "  ID: " << Cust.ID << "\n";
    std::cout << "  Username: " << Cust.Username << "\n";
    std::cout << "  First Name: " << Cust.FirstName << "\n";
    std::cout << "  Last Name: " << Cust.LastName << "\n";
    std::cout << "  Birthday: " << Cust.DoB << "\n";
    std::cout << "  Total Points: " << Cust.Points << "\n";
    std::cout << "\n";
}

// Function Purpose:     Removes saved customer's information from the customers.txt text file
// Return value:         void
// Parameters:           CustID                  string                  ID of customer to be deleted
void RemoveCustomer()
{
    // Opens files for reading and writing
    std::ifstream Prizes("customers.txt");
    std::ofstream Temp("temp.txt", std::ofstream::ate);

    // Declare variables
    std::string line;
    int Dec = 0;
    std::string CustID;

    // Loops through file, once it finds the designated customer the function doesn't transfer it over to the new file, removing it
    while (getline(Prizes, line))
    {
        if (line != CustID && Dec <= 0)
        {
            Temp << line << "\n";
        }

        else
        {
            switch (Dec)
            {
            case 0:
            {
                Dec = 6;
                break;
            }
            default:
            {
                --Dec;
                break;
            }
            }
        }
    }

    Prizes.close();
    Temp.close();

    std::remove("customers.txt");
    std::rename("temp.txt", "customers.txt");
}

#endif
