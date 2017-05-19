//
//  main.cpp
//  2017.5.19_STL_vector
//
//  Created by MiniYoga on 2017/5/19.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> numberVect1(100);
    vector<int> numberVect2(100);
    vector<int> numberVect3(200);
    int i=1,j=0,k=0;

    
    while (argv[i] != "]") {
        if(argv[i] != "["){
            cout<<"argv:"<<i<<endl;
            numberVect1[k] = atoi(argv[i]);
            cout<<"numberVect1:"<<k<<":"<<numberVect1[k]<<endl;
            k++;
        }
        i++;
    }
    i++;
    while (argv[i] != "]") {
        if(argv[i] != "["){
            numberVect2[j] = atoi(argv[i]);
            //cout<<"numberVect2:"<<numberVect2[j]<<endl;
            j++;
        }
        i++;
    }
    
    int p = k;
    while (j>=0) {
        while (k>=0) {
            if(numberVect1[k] == numberVect2[j]){
                numberVect3.push_back(numberVect2[j]);
                break;
            }
            k--;
        }
        k = p;
        j--;
    }
    sort(numberVect3.begin(), numberVect3.end());
    copy(numberVect3.begin(), numberVect3.end(),ostream_iterator<int>(cout));
    
    return 0;
}
