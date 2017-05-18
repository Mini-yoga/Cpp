//
//  algorithms.cpp
//  algorithm
//
//  Created by MiniYoga on 2017/5/15.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include "algorithms.hpp"
#include <iostream>
using namespace std;
int * algorithm::MPPX(int *number,int lens){
    
    for(int i=0;i<lens;i++){
        for(int j=0;j<lens-1-i;j++){
            if(*(number+j) > *(number+j+1)){
                swap(number+j,number+j+1);
            }
        }
    }

    return number;
}

int * algorithm::CRPX(int *number, int lens){
    for(int i=0;i<lens-1;i++){
        int temp;
        int max = i;
        //temp = *(number+i);
        for(int j=i;j<lens;j++){
            if(*(number+j) < *(number+max)){
                //temp = *(number+j);
                max = j;
            }
        }
        swap(number+i,number+max);
    }
    
    return number;
}


void algorithm::swap(int *a, int *b){
    int p;
    p = *a;
    *a = *b;
    *b = p;
}
