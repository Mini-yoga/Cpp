//
//  PrintBase.cpp
//  2017.5.23_DerivationAndInheritance
//
//  Created by MiniYoga on 2017/5/23.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include "PrintBase.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

typedef pair<string, int> PAIR;
struct CmpByValue {
    bool operator()(const PAIR& l, const PAIR& r) {
        return l.second > r.second;
    }
};

//fetch一个字符串后，能够以全部大写的形式打印出来；
string printA::print(string upStr){
    long int len = upStr.length();
    string compose = "";
    for(int i=0;i<len;i++){
        int integer = upStr[i];
        if(integer >=97 && integer <= 122){
            compose.push_back((char)(integer-32));
        }
        else if(integer >= 48 && integer <= 57){
            compose.push_back(upStr[i]);
        }
        else{
            compose.push_back(upStr[i]);
        }
    }
    return compose;

}

void printA::fetch(int argc, const char * argv[]){
    for(int i=1;i<argc;i++){
    cout<<print(argv[i])<<" ";
    }

}


//fetch一个字符串后，能够以全部小写的形式打印出来；
string printB::print(string upStr){
    long int len = upStr.length();
    string compose = "";
    for(int i=0;i<len;i++){
        int integer = upStr[i];
        if(integer >=65 && integer <= 90){
            compose.push_back((char)(integer+32));
        }
        else if(integer >= 48 && integer <= 57){
            compose.push_back(upStr[i]);
        }
        else{
            compose.push_back(upStr[i]);
        }
    }
    return compose;
    
}

void printB::fetch(int argc, const char * argv[]){
    for(int i=1;i<argc;i++){
        cout<<print(argv[i])<<" ";
    }
}



//fetch一个字符串后，能够统计并打印出词频最高的5个单词以及他们各自的频数
string printC::print(string upStr){
    long int len = upStr.length();
    string compose = "";
    for(int i=0;i<len;i++){
        int integer = upStr[i];
        if(integer >=97 && integer <= 122){
            compose.push_back((char)(integer-32));
        }
        else if(integer >= 48 && integer <= 57){
            compose.push_back(upStr[i]);
        }
        else{
            compose.push_back(upStr[i]);
        }
    }
    return compose;
    
}

void printC::fetch(int argc, const char * argv[]){
    int i=1,k=0,p=0,m=0;
    map<string,int> article;
    while (i<argc) {
        string str = argv[i];
        argv[i] = print(str).c_str();
        if(article.find(argv[i]) != article.end()){
            article[argv[i]] = article[argv[i]] + 1;
        }
        else{
            article[argv[i]] = 1;
            k++;
        }
        i++;
    }
    vector<PAIR> aricleVector(article.begin(),article.end());
    sort(aricleVector.begin(), aricleVector.end(),CmpByValue());
    while (m<10 && p<article.size()) {
        if(aricleVector[p].first != "." && aricleVector[p].first != "," && aricleVector[p].first != "?" && aricleVector[p].first != "!" && aricleVector[p].first != "、"){
            cout<<aricleVector[p].first<<":"<<aricleVector[p].second<<endl;
            m++;
        }
        p++;
    }
}

PrintBase::~PrintBase(){};
printA::~printA(){};
printB::~printB(){};
printC::~printC(){};




