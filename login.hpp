//
//  login.hpp
//  Super market  database
//
//  Created by Muhtashim Mahi on 3/8/17.
//  Copyright © 2017 Muhtashim Mannan. All rights reserved.
//

#ifndef login_hpp
#define login_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Character

{
    
private:
    
    string name;
    
    string pWord;
    
    
   public:
    
    void setName(string n);
    void setpWord(string p);
    string getName();
    string getPWord();
    void sendNAME();
    
    void sendPWORD();
    
};








#endif /* login_hpp */
