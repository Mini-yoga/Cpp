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
#include <cstring>
#include <map>
#include <vector>
#include "xml.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    //string filePath = argv[1];
    string filePath = "/Users/MiniYoga/Documents/Cpp/2017.6.1_XML/2017.6.1_XML/XML.xml";
    ifstream file;
    XmlData xmlObject;
    file.open(filePath,ios::in);
    if (file.is_open()){
            xmlObject.dump(file);
    }
    file.close();
    
}

