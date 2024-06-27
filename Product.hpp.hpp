#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include<string>
using namespace std;
class Product
{
private:
    string id;
    string name;
    int price;
    int count;
public:
    bool createProduct(void);
    bool validateid(string id);
    string getProductId(void);
    string getProductName(void);
    int getProductCount(void);
    int getProductPrice(void);
    Product(string id,string name,int price,int count);
    Product();

};
#endif