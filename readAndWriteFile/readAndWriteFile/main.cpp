//
//  main.cpp
//  readAndWriteFile
//
//  Created by MiniYoga on 2017/5/17.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstring>
using namespace std;

int findNameOfFile(string &str){//路径字符串截取
    long int indexS = str.find_last_of("/");
    long int indexE = str.find_last_of(".");
    str = str.substr(indexS+1,indexE-indexS-1);
    return indexS;
}

void addZero(bool &isNumber,bool &isCountStart,int num,int count,string &compose){
    if(isNumber == true){
        if(isCountStart == true){//已经存在小数
            if(num>count){
                int addNum = num - count;
                for(int j=0;j<addNum;j++){
                    compose = compose + "0";
                }
            }
        }
        else{//没有小数
            compose = compose + ".";
            for(int j=0;j<num;j++){
                compose = compose + "0";
            }
        }
    }
}

string upper(string upStr, char * n){//大小写转换，数字添加小数
    long int len = upStr.length();
    string compose = "";
    int num = atoi(n);
    bool isNumber = false;
    bool isCountStart = false;
    int count = 0;
    
    for(int i=0;i<len;i++){
        int integer = upStr[i];
        if(integer >=97 && integer <= 122){
            addZero(isNumber,isCountStart,num,count,compose);
            compose = compose + (char)(integer-32);
            count = 0;
            isCountStart = false;
            isNumber = false;
        }
        else if(integer >= 48 && integer <= 57){
            isNumber = true;
            if( isCountStart == true){
                if(count<num){
                    compose = compose + upStr[i];
                }
                count++;//小数点后位计数
            }
            else{
                compose = compose + upStr[i];
            }
            
        }
        else if(integer == 46){
            if(isNumber == true){//小数点前一位为数字
                isCountStart = true;
            }
            compose = compose + upStr[i];
        }
        else{
            addZero(isNumber,isCountStart,num,count,compose);
            compose = compose + upStr[i];
            count = 0;
            isCountStart = false;
            isNumber = false;
        }
        
    }
    addZero(isNumber,isCountStart,num,count,compose);
    return compose;
}



int main(int argc, char *argv[]) {
    ifstream file;
    ofstream newFile;
    string newFileName;
    string data;
    char *n = argv[2];
    //char *n = "2";
    string filePath = argv[1];//"/Users/MiniYoga/Documents/Cpp/readAndWriteFile/readAndWriteFile/ManyYearsAgo.txt";
    //string filePath = "/Users/MiniYoga/Documents/Cpp/readAndWriteFile/readAndWriteFile/ManyYearsAgo.txt";
    string copy = filePath;
    long int index = findNameOfFile(copy);
    string str1 = filePath.substr(0,index+1);
    newFileName = str1+copy+"_upper.txt";
    newFile.open(newFileName,ios::out);
    file.open(filePath,ios::in);
    
    if (file.is_open()){
        while (!file.eof()) {
            file>>data;
            data = upper(data,n);
            if (newFile.is_open()){
                newFile<<data<<" ";
                cout<<data<<endl;
            }
        }
    }
    file.close();
    newFile.close();
}

