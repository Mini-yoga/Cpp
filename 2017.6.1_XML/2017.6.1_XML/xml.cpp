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


XMLData XMLData::parse(std::string str){
    XMLData xmlData;
    std::string leftStr;
    std::string getLineStr;
    std::istringstream iss(str);
    
    if(str.find("<") == -1){//string
        xmlData.t = String;
        xmlData.m_string = str;
        std::cout<<str<<std::endl;
        return xmlData;
    }
    else{
        do{
            std::istringstream iss(str);
            getline(iss,getLineStr);
            if(getLineStr.find("/") == -1){//是个标签<note>
                unsigned long index1 = getLineStr.find("<");
                unsigned long index2 = getLineStr.find(">");
                std::string node = getLineStr.substr(index1+1,index2-(index1+1));
                std::cout<<node<<":"<<std::endl;
                int i = 1;
                unsigned long p = index2;
                unsigned long index3 = 0;
                
                do{
                    unsigned long s1 = str.find("<"+node+">",p);
                    unsigned long s2 = str.find("</"+node,p);
                    if(s1<s2){
                        p = s2+1;
                    }
                    if(s1>s2){
                        index3 = s2;
                        i--;
                    }
                }while(i != 0);
                
                leftStr = str.substr(getLineStr.length()+1,index3-getLineStr.length()-1);
                int index4 = str.find("<",index3+1);
                if(index4 != -1){
                    str = str.substr(index4,str.length()-index4);
                    std::istringstream iss(str);
                }
                else{
                    str = "";
                    std::istringstream iss(str);
                }
                XMLData data = parse(leftStr);
                xmlData.t = Object;
                xmlData = addMap(xmlData,node,data);
            }
            else if(getLineStr.find("/>") != -1){
                continue;//<..../>
            }
            else if(getLineStr.find("/")-getLineStr.find("<") == 1){
                continue;//</>
            }
            else{//<></>或<><></></>
                unsigned long index1 = getLineStr.find_first_of("<");
                unsigned long index2 = getLineStr.find_first_of(">");
                unsigned long index3 = getLineStr.find_last_of("<");
                std::string node = getLineStr.substr(index1+1,index2-(index1+1));
                std::cout<<node<<":"<<std::endl;
                leftStr = getLineStr.substr(index2+1,index3-(index2+1));
                
                int index4 = str.find("<",index3+1);
                if(index4 != -1){
                    str = str.substr(index4,str.length()-index4);
                    std::istringstream iss(str);
                }
                else{
                    str = "";
                    std::istringstream iss(str);
                }
                XMLData data = parse(leftStr);
                xmlData.t = Object;
                xmlData = addMap(xmlData,node,data);
            }
        }while (!str.empty());
        return xmlData;
    }
}


XMLData XMLData::addMap(XMLData xmlData,std::string node,XMLData data){
    if(xmlData.m_map.find(node) == xmlData.m_map.end()){
        xmlData.m_map[node] = data;
        xmlData.m_map_count[node] = 1;
    }
    else{
        if(xmlData.m_map_count[node] == 1){
            XMLData temp = xmlData.m_map[node];
            xmlData.m_map.erase(node);
            std::string nodeNew = node + "1";
            xmlData.m_map[nodeNew] = temp;
        }
        xmlData.m_map_count[node]++;
        int i = xmlData.m_map_count[node];
        char *countNodeChar;
        sprintf(countNodeChar,"%d",i);
        std::string nodeNew = countNodeChar;
        nodeNew = node+countNodeChar;
        xmlData.m_map[nodeNew] = data;
    }
    return xmlData;
}


XMLData::~XMLData(){
    
}

std::string XMLData::operator[](std::string inStr){
    std::string searchNode,leftStr;
    int index1 = inStr.find_first_of("[");
    int index2 = inStr.find_first_of("]");
    int index3 = inStr.find_last_of("]");
    searchNode = inStr.substr(index1+2,index2-index1-3);
    leftStr = inStr.substr(index2+1,index3-index2);

//    if(t == String){
//        std::cout<<m_string<<std::endl;
//        return m_string;
//    }
    //else{
        if(leftStr != ""){
           std::string s = m_map[searchNode][leftStr];
            return s;
        }
        else{
        //std::cout<<m_map[searchNode].m_string<<std::endl;
            return m_map[searchNode].m_string;
        }
   // }
    

}

//void XMLData::toNode(std::string inStr,std::string &searchNode,std::string &leftStr,int i){
//    int j = inStr.find("[",i);
//    i = inStr.find("]",i);
//    //int index3 = inStr.find_last_of("]");
//    
//    searchNode = inStr.substr(j+1,i-j-1);
//    //leftStr = inStr.substr(index2+1,index3-index2);
//    
//}
//
//


