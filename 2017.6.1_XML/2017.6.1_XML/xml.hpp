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
class Type;
class Type{
public:
    enum T{
        String,
        Object
    }type;
    
    Type(){};
    T parse(std::string str);
    Type(const Type &obj);
    virtual ~Type();

private:
    //Type *type = new Type();
    std::string m_string;
    std::map<std::string,Type> m_type;
    
};


class XmlData{
public:
    
    XmlData();
    
    Type parse(std::ifstream &file);
    
    //const string operator[](const string &obj)const;
    XmlData(const XmlData &obj);
    virtual ~XmlData();
};



#endif /* xml_hpp */
