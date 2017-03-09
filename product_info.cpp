//
//  product_info.cpp
//  Super market  database
//
//  Created by Muhtashim Mahi on 3/8/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#include "product_info.hpp"
using namespace std;


void product_s::create()        // If the admin wants to create a new product ask all the info required
{
   
    cout<<endl<<"Please Enter The Name of The Product: ";
    cin>>s.name;
    cout<<endl<<"Please Enter The origin of The Product: ";
    cin>>s.origin;
    cout<<endl<<"Please Enter The shipment origin of The Product: ";
    cin>>s.ship_orgin;
    cout<<endl<<"Please Enter The Price of The Product: ";
    cin>>s.price;
    cout<<endl<<"Please Enter The Discount (%): ";
    cin>>s.discount;
    cout<<endl<<"Please enter the tax amount";
    cin>>s.tax;
    cout<<"Please enter the quantity of the product";
    cin>>s.quantity;
}

void product_s::show_product()  // Displaying the info of a product to the admin
{
    cout<<endl<<"Product Name: "<<s.name<<endl;;
    cout<<endl<<"Product Origin: "<<s.origin<<endl;;
    cout<<endl<<"Product Shipment origin: "<<s.ship_orgin<<endl;;
    
    cout<<endl<<"Product Price: "<<s.price<<endl;
    cout<<endl<<"Product Discount: "<<s.discount<<endl;
    cout<<endl<<"Product tax: "<<s.tax<<endl;;
    cout<<endl<<"Product Quantity: "<<s.quantity<<endl;;
    
}
//Getters
char* product_s::getName()
{
    return s.name;
}

char* product_s::getOrigin()
{
    return s.origin;
}

char* product_s::getShipOrigin()
{
    return s.ship_orgin;
}

double product_s::getPrice()
{
    return s.price;
}
double product_s::getDiscount()
{
    return s.discount;
}
double product_s::tax()
{
    return s.tax;
}
int product_s::getQuantity()
{
    return s.quantity;
}
