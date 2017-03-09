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
#include<iomanip>
#include<vector>

using namespace std;





 

 
 


int main()
{
    // insert code here...
  
    product_s s;
    s.create();
    
   
    
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
 
    
    
    
    
    
    
    
    
    cout << "Hello, World!\n";
    return 0;
}
