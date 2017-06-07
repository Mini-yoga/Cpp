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
    T parse(std::string str);
    XMLData(const XMLData &obj);
    virtual ~XMLData();

private:
    T t,e;
    std::string m_string;
    std::map<std::string,T> m_type;
    
};


class XmlData{
public:
    
    XmlData();
    
    XMLData parse(std::ifstream &file);
    
    //const string operator[](const string &obj)const;
    XmlData(const XmlData &obj);
    virtual ~XmlData();
};



#endif /* xml_hpp */
