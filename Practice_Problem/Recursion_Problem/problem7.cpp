//problem 2*1+5*3+8*5+.....
//input n=8

#include<iostream>
#include<stdio.h>

using namespace std;

void recursionFun(int n, int m){
    if(m<=0){
        return;
    }
    recursionFun(n-3, m-2);
    cout << n <<"*" << m << "+" ;
    
}

int main(){
    int n;
    cin >> n;
    recursionFun(n, n-3);
}