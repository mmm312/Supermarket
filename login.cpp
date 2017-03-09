//
//  login.cpp
//  Super market  database
//
//  Created by Muhtashim Mahi on 3/8/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#include "login.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void Character::setName(string n)    //setter
{
    name=n;
}


void Character::setpWord(string p)    //setter
{
    pWord=p;
}


void Character::sendNAME()  // User login// name from external file

{
    cout << "Enter your desired username(max 16 characters): ";
    cin >> name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
};



void Character::sendPWORD()   //User login // Password from external file

{
    cout << "Enter your password(max 10 characters): ";
    cin >> pWord;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
};

int start_menu()  //Intial user interface with login options and registering options

{
    
    int options;
    cout << "Welcome to the login menu for the system database." << endl;
    cout << "\tPress '1' to continue login." << endl;
    cout << "\tor"<<endl;
    cout << "\tPress '2' to continue register." << endl;
    cout << "You choose: ";
    cin >> options;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return options;
    
    };


int main()

{
    // reading in file and writing in file for login username and password
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
    
        }
