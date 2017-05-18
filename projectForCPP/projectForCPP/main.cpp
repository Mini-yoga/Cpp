//
//  main.cpp
//  projectForCPP
//
//  Created by MiniYoga on 2017/5/12.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    do {
        cout<< "Enter:" <<endl;
        getline(cin,str);
        int len = str.length();
        for(int i=0;i<len;i++){
            int integer = str[i];
            if(integer>=97 && integer<=122){
                cout<<(char)(integer-32);
            }
            else if(integer == 32){
                cout<<" ";
            }
            else{
                cout<<str[i];
            }
        }
        cout<<endl;
    }while (str != "end");
    
    return 0;
}
