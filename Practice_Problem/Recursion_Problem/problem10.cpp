//problem 1*1^2 + 2*3^2 + 3*5^2 + ......
// input n=5;

#include<iostream>
#include<stdio.h>

using namespace std;

void recursionFun(int n, int m){
    if(n<=0){
        return;
    }
    recursionFun(n-2,m-1);
    //if(n%2!=0)
    cout <<m <<"*"  <<n << "^" <<"2 + " ;
    
}

int main(){
    int n;
    cin >> n;
    recursionFun(n,n-2);
}