//
//  xml.cpp
//  2017.6.1_XML
//
//  Created by MiniYoga on 2017/6/1.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include "xml.hpp"
#include <iostream>
#include <regex>
#include <sstream>

XMLData::T XMLData::parse(std::string str){
 
    std::regex reg1("<*/>*");
    std::regex reg2("<*>*</*>*");
    std::regex reg3("<*>*");
    std::regex reg4("<*><*>*</*></*>*");
    std::string newStr = str;
    std::string rStr;
    std::istringstream iss(str);
    std::smatch sm;
    if(str.length()>0){
        getline(iss,rStr);
        if(std::regex_match(rStr.begin(),rStr.end(),reg1)){//表示标签<...../>
            unsigned long i = str.find("/>");
            newStr = str.substr(i+2,str.length());
            e = parse(newStr);
            t = T::Object;
            return t;
        }
        
        if(!std::regex_match(rStr.begin(),rStr.end(),reg2)){//表示是String或者标签
            unsigned long p = rStr.find('<');
            if(p == -1){
                std::cout<<str<<std::endl;
                m_string = str;
                t = T::String;
                return t;
            }
            else{
                unsigned long q = rStr.find('>');
                std::string node = rStr.substr(p+1,q-p);
                node = "</"+node;
                unsigned long endNode = str.find(node);
                newStr = str.substr(q+3,endNode-q-3);
                std::cout<<newStr;
                e = parse(newStr);
                t = T::Object;
                m_type[node] = t;
                return t;
            }
        }
        else{//表示是个同行Object或者<><></></>
            t = T::Object;
            unsigned long index1 = rStr.find_first_of("<");
            unsigned long index2 = rStr.find_first_of(">");
            unsigned long index3 = rStr.find_last_of("<");
            unsigned long index4 = rStr.find_last_of(">");
            std::string node = rStr.substr(index1+1,index2-index1-1);
            std::string inStr = rStr.substr(index2+1,index3-index2-1);
            
            m_type[node] = t;
            parse(inStr);
            newStr = str.substr(index4+2,str.length()-index4-2);
            e = parse(newStr);
            return t;
        }
    }
    else{//""
        m_string = "";
        t = T::String;
        return t;
    }
    
}

XMLData::~XMLData(){
    
}







