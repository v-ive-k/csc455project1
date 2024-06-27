#include<bits/stdc++.h>
#include <Product.hpp>
#include<ProductMgmt.hpp>
using namespace std;
bool validateProductId(string pid)
{
    if(pid.size()>6)
        return false;
    for(int i=1;i<pid.size();i++)
    {
        if(!isdigit(pid[i]))
            return false;
    }
    return true;
}
bool Product::createProduct(void)
{
    string id,tmpid,name;
    int price,count;
    cout<<"Enter the product ID"<<endl;
    cin>>id;
    id.insert(0,"P");
    cout<<"Enter the Product name"<<endl;
    cin>>name;
    cout<<"Enter product price"<<endl;
    cin>>price;
    cout<<"Enter product count"<<endl;
    cin>>count;
    if(validateid(id))
    {
        *this=Product(id,name,price,count);
        return true;
    }
    else
    {
        return false;
    }   
}
Product:: Product()
{
    
}
Product:: Product(string pid,string pname,int pprice,int pcount)
{
    id=pid;
    name=pname;
    price=pprice;
    count=pcount;
}

bool Product::validateid(string id)
{
    ProductMgmt pm;
    if(pm.isUniqueProductId(id))
    return true;
    else
    return false;
}
string Product::getProductId(void)
{
    return id;
}
string Product:: getProductName(void)
{
    return name;
}
int Product:: getProductPrice(void)
{
    return price;
}
int Product:: getProductCount(void)
{
    return count;
}
