#include<bits/stdc++.h>
#include <ProductMgmt.hpp>
#include<fstream>
#include<sstream>
using namespace std;
vector<Product>  productList;
vector<Product> productListTemp;
void ProductMgmt::addProduct(Product pro){
    productListTemp.push_back(pro);
}

bool ProductMgmt::removeProduct(string id){
     if(productList.empty())
        return false;
    for(int i=0;i<productList.size();i++){
        if(productList[i].getProductId() == id){
            productList.erase(productList.begin()+i);
            return true;
        }
    }
    return false;
}

bool ProductMgmt::isUniqueProductId(string id){ 
    for(int i=0;i<productList.size();i++)
    {
        if(productList[i].getProductId()==id)
            return false;
    }
    return true;
}

void ProductMgmt::viewProduct(){
    cout<<"Following products are available for shopping"<<endl;
    for(int i=0;i<productList.size();i++){
            cout<<"Product Name "<<productList[i].getProductName()<<endl;
        }
    for(int i=0;i<productListTemp.size();i++){
            cout<<"Product Name "<<productListTemp[i].getProductName()<<endl;
        }
}
bool is_file_exists(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
void ProductMgmt::loadProductFromFile(){
    bool file_check=is_file_exists("product.txt");
    if(!file_check)
    return;
    else
    {
        fstream file;
        file.open("product.txt");
        // file.seekg(0);
        string line, temp;
        while(!file.eof())
        {
            string id,name;
            int price,count;
            getline(file,line);
            if(line.size()==0)
                return;
            // cout<<line<<endl;
            stringstream ss(line);
            ss>>id;
            ss>>name;
            ss>>price;
            ss>>count;
            // cout<<"Existing usename is "<<userName<<endl;
            Product p(id,name,price,count);
            productList.push_back(p);
        }

        file.close();
    }
}

void ProductMgmt::saveProductToFile(){
    ofstream fileout;
    fileout.open("product.txt");
    for(int i=0;i<productList.size();i++)
    {
        fileout<<productList[i].getProductId()<<" "<<productList[i].getProductName()<<" "<<productList[i].getProductPrice()<<" ";
        fileout<<productList[i].getProductCount()<<endl;
    }
    for(int i=0;i<productListTemp.size();i++)
    {
        fileout<<productListTemp[i].getProductId()<<" "<<productListTemp[i].getProductName()<<" "<<productListTemp[i].getProductPrice()<<" ";
        fileout<<productListTemp[i].getProductCount()<<endl;
    }
    fileout.close();
}

ProductMgmt::ProductMgmt()
{
    
}

ProductMgmt::~ProductMgmt()
{
}
