//
//  xml.cpp
//  2017.6.1_XML
//
//  Created by MiniYoga on 2017/6/1.
//  Copyright © 2017年 MiniYoga. All rights reserved.
//

#include "xml.hpp"
#include <iostream>
using namespace std;
extern ifstream file;

char c[1000];
void XmlData::dump(ifstream &file){
    if(!file.eof()){
        file.getline(c, 1000, '\n');
        string str = c;
        int last = str.find_last_of('/');
        
        int index2 = str.find(">");
        if(last == -1 || last>index2){
            int index1 = str.find("<");
            int index3 = str.find_last_of("<");
            string subH = str.substr(index1+1,index2-index1-1);
            string subN = str.substr(index2+1,index3-index2-1);
            cout<<subH<<endl;
            cout<<subN<<endl;
            dump(file);
        }
        if(last == -1){
            dump(file);
        }
        
    }
}

const string XmlData::operator[](const string &obj)const{

}
