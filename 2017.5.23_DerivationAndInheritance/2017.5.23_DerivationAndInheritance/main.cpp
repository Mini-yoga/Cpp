//
//  main.cpp
//  2017.5.23_DerivationAndInheritance
//
//  Created by MiniYoga on 2017/5/23.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "PrintBase.hpp"
//#include "config.h"
int main(int argc, const char * argv[]) {
    auto i=0;
    PrintBase * A;
    cout<<"Enter Alorithem Number 1,2,3:"<<endl;
    cin>>i;
    if(i==1){
    A = new printA();
        A->fetch(argc,argv);}
    else if (i==2){

    A = new printB();
    A->fetch(argc,argv);
    }
    else if(i==3){
    
    A = new printC();
        A->fetch(argc,argv);
    }
    else{
        cout<<"Wrong Alorithem Number!"<<endl;
    }

    return 0;
    
    
    
    
    
//#ifdef USE1
//        A = new printA();
//        A->fetch(argc,argv);
//#endif
//#ifdef USE2
//    A = new printB();
//    A->fetch(argc,argv);
//#endif
//#ifdef USE3
//    A = new printC();
//    A->fetch(argc,argv);
//#endif
//    return 0;
//    
    
}
