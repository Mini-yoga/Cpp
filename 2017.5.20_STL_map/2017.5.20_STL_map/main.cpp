//
//  main.cpp
//  2017.5.20_STL_map
//
//  Created by MiniYoga on 2017/5/20.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include<algorithm>
using namespace std;

typedef pair<string, int> PAIR;
struct CmpByValue {
    bool operator()(const PAIR& l, const PAIR& r) {
        return l.second > r.second;
    }
};

string upper(string upStr){//大小写转换
    long int len = upStr.length();
    string compose = "";
    for(int i=0;i<len;i++){
        int integer = upStr[i];
        if(integer >=65 && integer <= 90){
            compose = compose + (char)(integer+32);
        }
        else if(integer >= 48 && integer <= 57){
            compose = compose + upStr[i];
        }
        else{
            compose = compose + upStr[i];
        }
    }
    return compose;
}



int main(int argc, const char * argv[]) {
    int i=1,k=0,p=0,m=0;
    
    map<string,int> article;
    while (i<argc) {
        string str = argv[i];
        argv[i] = upper(str).c_str();
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
    return 0;
}
