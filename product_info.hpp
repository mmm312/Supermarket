//
//  product_info.hpp
//  Super market  database
//
//  Created by Muhtashim Mahi on 3/8/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#ifndef product_info_hpp
#define product_info_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

struct product       // The details of a particular product will be store here
{
    char name[100], origin[100], ship_orgin[100];
    int quantity, number;
    double price, discount, tax;
    
    
};

class product_s         // class that deals with the functions that can edit information about a product
{
private:
    product s;
    
    
public:
    
    void create();
    void show_product();
    char* getName();
    char* getOrigin();
    char* getShipOrigin();
    double getPrice();
    double getDiscount();
    double tax();
    int getQuantity();
    int getProduct();
};





#endif /* product_info_hpp */
