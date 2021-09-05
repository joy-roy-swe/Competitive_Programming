#include<iostream>
#include<stdio.h>

using namespace std;

void recursionFun(int n){
    if(n==0){
        return;
    }
    recursionFun(n-1);
    int ans = (8*n)-4;
    cout << ans << "+" ;
    
}

int main(){
    int n;
    cin >> n;
    recursionFun(n);
}