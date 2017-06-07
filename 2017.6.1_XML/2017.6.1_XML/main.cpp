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
    XMLData type;
    XMLData::T returnType;
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
    returnType = type.parse(str);
    
}



