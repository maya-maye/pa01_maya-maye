#include "utility.h"
#include <iostream>
using std::cout;
void printCard(int n){
    char a;
    int t;
    if (n-400>0){
        a='h';
        t=n-400;
    }
    else if (n-300>0){
        a='s';
        t=n-300;
    }
    else if (n-200>0){
        a='d';
        t=n-200;
    }
    else{
        a='c';
        t=n-100;
    }
    if (t==1){
        cout<<a<<" "<<"a"<<endl;
    }
    else if (t==11){
        cout<<a<<" "<<"j"<<endl;
    }
    else if (t==12){
        cout<<a<<" "<<"q"<<endl;
    }
    else if (t==13){
        cout<<a<<" "<<"k"<<endl;
    }
    else{
        cout<<a<<" "<<t<<endl;
    }
}

