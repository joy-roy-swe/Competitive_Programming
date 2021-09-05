//problem 1*2+ 2*3+ 3*4+ 4*5+.....
//input n = 5
#include<iostream>
#include<stdio.h>

using namespace std;

void recursionFun(int n){
    if(n==1){
        return;
    }
    recursionFun(n-1);
    cout << n-1 << "*" <<n <<"+";
    
}

int main(){
    int n;
    cin >> n;
    recursionFun(n);
}