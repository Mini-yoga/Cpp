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
#include <map>
using namespace std;

//template <typename T>
class XmlData{
public:
    
    XmlData();
    void dump(ifstream &file);
    const string operator[](const string &obj)const;
                       
    XmlData(const XmlData &obj);
    virtual ~XmlData();
private:
     map<string,string> xmlMap;
};



#endif /* xml_hpp */
