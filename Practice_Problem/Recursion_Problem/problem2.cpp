//problem 2+4+6+8+.....

#include<iostream>
#include<stdio.h>

using namespace std;

void recursionFun(int n){
    if(n==0){
        return;
    }
    recursionFun(n-1);
    if(n%2==0)
        cout << n << "+" ;
    
}

int main(){
    int n;
    cin >> n;
    recursionFun(n);
}