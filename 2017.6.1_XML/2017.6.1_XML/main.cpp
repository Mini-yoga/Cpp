//
//  main.cpp
//  2017.6.1_XML
//
//  Created by MiniYoga on 2017/6/1.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "xml.hpp"

int main(int argc, const char * argv[]) {
    
    //string filePath = argv[1];
    std::string filePath = "/Users/MiniYoga/Documents/Cpp/2017.6.1_XML/2017.6.1_XML/XML.xml";
    std::ifstream file(filePath);
    std::stringstream buff;
    std::string str;
    XMLData type,returnData;
    buff<<file.rdbuf();
    std::string fileString(buff.str());
    if(fileString.find('?xml') != -1){
        unsigned long i = fileString.find('?>');
        str = fileString.substr(i+3);
        //std::cout<<str;
    }
    else{
        str = fileString;
    }
    returnData = type.parse(str);
    
    
    char buffer[100];
    std::cout<<"Enter search:"<<std::endl;
    std::cin.getline(buffer,100,'\n');
    std::string inStr = buffer;
    int index1 = inStr.find_first_of("[");
    int index2 = inStr.find_last_of("]");
    inStr = inStr.substr(index1,index2-index1+1);
    returnData[inStr];
}



