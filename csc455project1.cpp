#include <iostream>
#include <CustomerMgmt.cpp>
#include <Customer.cpp>
#include <ProductMgmt.cpp>
#include <Product.cpp>
using namespace std;
void displayMenu() {
    cout << "Enter 1 for Customer registration." << endl;
    cout << "Enter 2 for Customer Removal." << endl;
    cout << "Enter 3 for Product addition" << endl;
    cout << "Enter 4 for Product removal" << endl;
    cout << "Enter 5 for shopping" << endl;
    cout << "Enter 6 to view customer using customer ID." << endl;
    cout << "Enter 7 to redeem rewards" << endl;
}
int main() {
    bool repeat = false;
    do {
        displayMenu();
        int option;
        cin >> option;
        CustomerMgmt custMgmt;
        custMgmt.loadUserIntoFile();
        ProductMgmt prodMgmt;
        prodMgmt.loadProductFromFile();
        switch (option) {
        case 1:
        {
            Customer c;
            if (c.createCustomer())
            {
                custMgmt.addUser(c);
            }
            else
                cout << "Incorrect customer details" << endl;
            break;
        }
        case 2:
        {
            string custId;
            cout << "Enter Customer Id to be deleted: ";
            cin >> custId;
            if (custMgmt.removeUser(custId))
                cout << "Suceesfully deleted" << endl;
            else
                cout << "Customer not found" << endl;
            break;
        }
        case 3:
        {
            Product p;
            if (p.createProduct()) {
                prodMgmt.addProduct(p);
            }
            else
            {
                cout << "Incorrect product details" << endl;
            }
            break;
        }
        case 4:
        {
            string prodId;
            cout << "Enter Product id to be deleted: ";
            cin >> prodId;
            if (prodMgmt.removeProduct(prodId))
                cout << "Suceesfully deleted" << endl;
            else
                cout << "Product not found" << endl;
            break;
        }
        case 5:
        {
            prodMgmt.viewProduct();
            break;
        }
        case 6:
        {
            string id;
            cout << "Enter Customer Id to view details: ";
            cin >> id;
            custMgmt.viewUser(id);
            break;
        }
        default:
        {
            custMgmt.saveUserToFile();
            prodMgmt.saveProductToFile();
            cout << "Exiting... ";
        }
        }
        cout << "Do you want to repeat (Y/N): ";
        char rep;
        cin >> rep;
        if (rep == 'Y') {
            repeat = true;
        }
        else {
            repeat = false;
            custMgmt.saveUserToFile();
            prodMgmt.saveProductToFile();
        }
    } while (repeat == true);

    return 0;
}