#ifndef PRODUCT_MGMT_HPP
#define PRODUCT_MGMT_HPP
#include <Product.hpp>
#include<string>
#include <vector>
using namespace std;
class ProductMgmt
{
private:
    string productFile;
public:
    ProductMgmt();
    ~ProductMgmt();
    void loadProductFromFile();
    void addProduct(Product c);
    bool removeProduct(string id);
    bool isUniqueProductId(string id);
    void viewProduct();
    void saveProductToFile();
};
#endif