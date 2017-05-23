//
//  PrintBase.hpp
//  2017.5.23_DerivationAndInheritance
//
//  Created by MiniYoga on 2017/5/23.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#ifndef PrintBase_hpp
#define PrintBase_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class PrintBase {
public:
    virtual string print(string upStr) = 0;
    virtual void fetch(int argc,const char * argv[])=0;
    virtual ~PrintBase();
};
class printA : public PrintBase{
public:
    string print(string upStr);
    void fetch(int argc, const char * argv[]);
    ~printA();
};
class printB : public PrintBase{
public:
    string print(string upStr);
    void fetch(int argc, const char * argv[]);
    ~printB();
};
class printC : public PrintBase{
public:
    string print(string upStr);
    void fetch(int argc, const char * argv[]);
    ~printC();
};

#endif /* PrintBase_hpp */
