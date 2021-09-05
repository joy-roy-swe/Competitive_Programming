//problem 1*3+3*5+5*7+.....
//input n=7

#include<iostream>
#include<stdio.h>

using namespace std;

void recursionFun(int n, int m){
    if(n<=0){
        return;
    }
    recursionFun(n-2, m-2);
    cout << n <<"*" << m << "+" ;
    
}

int main(){
    int n;
    cin >> n;
    recursionFun(n-2, n);
}