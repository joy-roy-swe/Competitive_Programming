//problem 1+2+3+4+.....
#include<iostream>
#include<stdio.h>

using namespace std;

void recursionFun(int n){
    if(n==0){
        return;
    }
    recursionFun(n-1);
    cout << n << "+" ;
}

int main(){
    int n;
    cin >> n;
    recursionFun(n);
}