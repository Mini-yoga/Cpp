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
    Type type,returnType;
    buff<<file.rdbuf();
    std::string fileString(buff.str());
    if(fileString.find('?xml') != -1){
        int i = fileString.find('?>');
        str = fileString.substr(i+2);
        std::cout<<str;
    }
    else{
        str = fileString;
    }
    returnType.type = type.parse(str);
    
}



