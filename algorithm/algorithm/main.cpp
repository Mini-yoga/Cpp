//
//  main.cpp
//  algorithm
//
//  Created by MiniYoga on 2017/5/15.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "algorithms.hpp"
using namespace std;

int main() {
    int *number = new int(100);
    int choose = 1;
    int i = 0;
    int order = 1;
    int *sort;
    algorithm A;
    
    
    
//     使用sstream类课判断字符串是否结束并且只读入数字
//    string inputStr;
//    getline(cin,inputStr);
//    istringstream iss(inputStr);
//    int temp,idx = 0;
//    while (iss>>temp) {
//        number[idx++] = temp;
//    }
//    
//    
    cout<<"Enter number:"<<endl;
    cin>>*(number+i);
    
    while (*(number+i) != -1) {//不能判断cin读入最后一个是回车键，只能设置结束为-1；不能判断读入是否为数字
        i++;
        cin>>*(number+i);
    }
    
    cout<<"Choose Bubble Sort alorithm 1:"<<endl;
    cout<<"Choose Insertion Sort alorithm 2:"<<endl;
    cin>>choose;

    switch (choose){
        case 1:
            sort = A.MPPX(number,i);
            break;
        case 2:
            sort = A.CRPX(number,i);
            break;
        default:
            cout<<"None"<<endl;
            break;
    }
    
    cout<<"Choose Descending  1:"<<endl;
    cout<<"Choose Ascending  2:"<<endl;
    cin>>order;
    
    if(order == 1){
        for(int b=i-1;b>=0;b--){
            cout<<*(sort+b)<<" ";
        }
    }
    
    if(order == 2){
        for(int b=0;b<i;b++){
            cout<<*(sort+b)<<" ";
        }
    }
    
}

