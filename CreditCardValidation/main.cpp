//
//  main.cpp
//  CreditCardValidation
//
//  Created by Vaishali Bisht on 6/23/18.
//  Copyright © 2018 Vaishali Bisht. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


bool isvalidcc(const string &cardNum)
{
    int length = (int)cardNum.size();
    int total=0;
    
   // cout <<  "No:";
    
    for(int i = length-2; i>=0; i=i-2)
    {
        int  num = stoi(cardNum.substr(i, 1))*2;

       // cout <<  "," << num;
        
        if(num>9)
        {
            int n1 =0;
            int n2 = 0;
            
            n1 = num%10;
            num /= 10;
            n2 = num%10;
            num = n1+n2;
        }
        total += num ;
        
    }
    //cout << "  total:" << total;
    
    

  //  cout <<  "   odd:" ;
    int sum = 0;
   
    for(int i = length-1; i>=0 ; i=i-2){
        int  odd = stoi(cardNum.substr(i, 1));
        cout <<  "," << odd;
        sum += odd;
    }
    //cout <<  "    sum:" << sum;
    
    
    int finalsum = total + sum;
   // cout <<  "  ,Finalsum:" << finalsum;
    
    if (finalsum%10 != 0) {
        return false;
    }

    return true;
}



int main()
{
    vector<string> cardnumbers = {
        "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
        "4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
        "5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
        "4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
        "5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
        "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
        "4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
        "5556551555555557", "6011316011016011"
    };
    
    int i;
    vector<string>::iterator itr;
    
    for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++){
        cout << setw(2)  << i << " "
        << setw(17) << *itr
        << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
    }
    
    return 0;
}
