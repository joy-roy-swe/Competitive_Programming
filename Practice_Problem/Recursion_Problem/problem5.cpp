//problem 3+5+8+11+.....

#include<iostream>
#include<stdio.h>

using namespace std;

void recursionFun(int n){
    if(n==0){
        return;
    }
    recursionFun(n-1);
    int ans = 2+((n-1)*3);
    cout << ans << "+" ;
    
}

int main(){
    int n;
    cin >> n;
    recursionFun(n);
}