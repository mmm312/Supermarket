//
//  main.cpp
//  Super market  database
//
//  Created by Muhtashim Mahi on 2/9/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#include <iostream>
#include <string>
#include<fstream>
#include "product_info.hpp"
using namespace std;



fstream pfile;
product_s prod;


void save_product()           // saving product to file
{
    pfile.open("database.dat",ios::out|ios::app);
    prod.create();
    pfile.write((char*)&prod,sizeof(product_s));
    pfile.close();
    cout<<endl<<endl<<"The Product Has Been Sucessfully Created...";
    getchar();
}

void show_all_product()         //displaying product
{
    system("cls");
    cout<<endl<<"\t\t#############################";
    cout<<endl<<"\t\tDATA.";
    cout<<endl<<"\t\t#############################\n";
    pfile.open("database.dat",ios::in);
    while(pfile.read((char*)&prod,sizeof(product_s)))
    {
        prod.show_product();
        cout<<endl<<"#################################\n"<<endl;
        getchar();
    }
    pfile.close();
}

void display_record(int num)     // function to show if product exixts
{
    bool found=false;
    pfile.open("database.dat",ios::in);
    while(pfile.read((char*)&prod,sizeof(product_s)))
    {
        if(prod.getProduct()==num)     //getProduct
        {
            system("cls");
            prod.show_product();
            found=true;
        }
    }
    
    pfile.close();
    if(found == true)
        cout<<"\n\nNo data found";
    getchar();
}

void edit_product()
{
    int num;
    bool found=false;
    system("cls");
    cout<<endl<<endl<<"\tPlease Enter The Product : ";
    cin>>num;
    
    pfile.open("database.del",ios::in|ios::out);
    while(pfile.read((char*)&prod,sizeof(product)) && found==false)
    {
        if(prod.getProduct()==num)
        {
            prod.show_product();
            cout<<"\n Enter New Details of Product: "<<endl;
            prod.create();
            int pos=-1*sizeof(product_s);
            pfile.seekp(pos,ios::cur);
            pfile.write((char*)&prod,sizeof(product));
            cout<<endl<<endl<<"\t Update Successfull \n";
            found=true;
        }
    }
    pfile.close();
    if(found==false)
        cout<<endl<<endl<<"Record Not Found \n";
    getchar();
}


void delete_product()      // deleting product using temp counter to delete
{
    int num;
    system("cls");
    cout<<endl<<endl<<" Enter The product : ";
    cin>>num;
    pfile.open("database.del",ios::in|ios::out);
    fstream pfile2;
    pfile2.open("Temp.del",ios::out);
    pfile.seekg(0,ios::beg);
    while(pfile.read((char*)&prod,sizeof(product)))
    {
        if(prod.getProduct()!=num)
        {
            pfile2.write((char*)&prod,sizeof(product));
        }
    }
    pfile2.close();
    pfile.close();
    remove("database.del");
    rename("Temp.del","database.del");
    cout<<endl<<endl<<"\tRecord Deleted \n";
    getchar();
}


void menu()    // showing the product
{
    
    pfile.open("database.del",ios::in);
    
    cout<<endl<<endl<<"\t\tMENU\n\n";
    cout<<"#############################\n";
    cout<<"\t\tNAME\t\tPRICE\n";
    cout<<"##############################\n";
    while(pfile.read((char*)&prod,sizeof(product)))
    {
        cout<<prod.getProduct()<<"\t"<<prod.getName()<<"\t"<<prod.getPrice()<<endl;
    }
    pfile.close();
}

void employee()         //employee menu
{
    int oArray[50],quantity[50],c=0;
    float amt,damt,total=0;
    char ch='Y';
    menu();
    cout<<"\n##########################";
    cout<<"\n PLACE YOUR ORDER";
    cout<<"\n##########################\n";
    do{
        cout<<"\n\nEnter The Product : ";
        cin>>oArray[c];
        cout<<"\nQuantity: ";
        cin>>quantity[c];
        c++;
        cout<<"\nDo You Want To Order Another Product ?";
        cin>>ch;
    }while(ch=='y' ||ch=='Y');
    cout<<"\n\nThank You";
    getchar();
    system("cls");
    cout<<"\n\n#################################################\n";
    cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
    for(int x=0;x<=c;x++)
    {
        pfile.open("database.del",ios::in);
        pfile.read((char*)&prod,sizeof(product));
        while(!pfile.eof())
        {
            if(prod.getProduct()==oArray[x])
            {
                amt=prod.getPrice()*quantity[x];
                damt=amt-(amt*prod.getDiscount()/100);
                cout<<"\n"<<oArray[x]<<"\t"<<prod.getName()<<"\t"<<quantity[x]<<"\t\t"<<prod.getPrice()<<"\t"<<amt<<"\t\t"<<damt;
                total+=damt;
            }
            pfile.read((char*)&prod,sizeof(product));
        }
        pfile.close();
    }
    cout<<"\n\n\t\tTOTAL= "<<total;
    getchar();
}



void admin_menu()     // admin functionality
{
    
    int option;
    cout<<"\t################################";
    cout<<"\n\tPress 1 to CREATE ";
    cout<<"\n\tPress 2 to DISPLAY";
    cout<<"\n\tPress 3 to QUERY";
    cout<<"\n\tPress 4 to MODIFY ";
    cout<<"\n\tPress 5 to DELETE ";
    cout<<"\n\tPress 6 to GO BACK TO MAIN MENU";
    cout<<"\n\t###############################";
    
    cout<<"\n\n\tOption: ";
    cin>>option;
    switch(option)
    {
        case 1: system("cls");
            save_product();
            break;
            
        case 2: show_all_product();
            break;
            
        case 3:
            int num;
            system("cls");
            cout<<"\n\n\tPlease Enter The Product Number: ";
            cin>>num;
            display_record(num);
            break;
            
        case 4: edit_product();
            break;
            
        case 5: delete_product();
            break;
            
        case 6: system("cls");
            break;
            
        default:admin_menu();
    }
}

int main()
{
    // insert code here...
  
   // product_s// s;
   // s.create();
    
   
    
    //Future implementation
    
    /* // reading in file and writing in file for login username and password
    ifstream read("loginFile.txt");
    ofstream write("loginFile.txt", ios::app);
    Character char_Info;
    
    do
    {
        int option = start_menu();
        cout << endl;
        
        if(option == 1)
        {
            string username;
            string password;
            string temp;
            string temp1;
            
            
            if(read.is_open())
            {
                cout << "Enter User Name: ";
                cin >> username;
                cout << "Enter User Password: ";
                cin >> password;
                cout << endl;
                read >> temp;
                
                
                
                //checking if user name and user Password matches data in file
                if(username == temp)
                {
                    cout << "\nUsername found" << endl;
                    read>>temp1;
                    
                    if(password == temp1)
                    {
                        cout << "Welcome " << username << "!" << endl;
                        break;
                    }
                }else       // If not foend throws an error
                {
                    cout << "Invalid Username or Password." << endl;
                }
                
                read.close();
            }
        }// end of file read in algorithm
        
        //if new user create a new username and Password
        if(option == 2)
        {
            char_Info.sendNAME();
            cout << endl;
            char_Info.sendPWORD();
            cout << endl;
            
            if (write.is_open())
                
            {
                write << char_Info.setName() << endl;
                write << char_Info.pWord << endl;
                write.close();
                
            }else
            {
                cout << "Unable to open file";
            }
            
        }
        
    }while(1);
    
    return 0;
*/
 
    
   
    int option;
    
    for(;;)
    {
        
        cout<<"\n\t##########################################";
        cout<<"\n\t1. CUSTOMER";
        cout<<"\n\t2. ADMINISTRATOR";
        cout<<"\n\t3. EXIT";
        cout<<"\n\t##########################################";
        
        cout<<"\n\tOption: ";
        cin>>option;
        
        switch(option)
        {
            case 1: system("cls");
                employee();
                getchar();
                break;
                
            case 2: admin_menu();      // login info here...
                break;
                
            case 3:
                cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout<<"\n\tGood Bye!";
                cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                exit(0);
                
            default :cout<<"Invalid Input...\n";
        }
        
    }
    
    
    
    
    
    
   
    return 0;
}
