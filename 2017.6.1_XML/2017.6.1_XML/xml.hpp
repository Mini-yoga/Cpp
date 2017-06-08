//
//  xml.hpp
//  2017.6.1_XML
//
//  Created by MiniYoga on 2017/6/1.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#ifndef xml_hpp
#define xml_hpp
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
class XMLData;
class XMLData{
public:
    enum T{
        String,
        Object
    };
    XMLData(){};
    XMLData parse(std::string str);
    XMLData addMap(XMLData xmlData,std::string node,XMLData data);
    void operator[](std::string inStr);
    //void toNode(std::string inStr,std::string &searchNode,std::string &leftStr,int i);
    //XMLData(const XMLData &obj);
    virtual ~XMLData();
private:
    T t;
    std::string m_string;
    std::map<std::string,XMLData> m_map;
    std::map<std::string,int> m_map_count;
};


#endif /* xml_hpp */
