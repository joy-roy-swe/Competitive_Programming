// problem 1^2 + 3^2 + 5^2 +
//input n=5

#include<iostream>
#include<stdio.h>

using namespace std;

void recursionFun(int n){
    if(n==0){
        return;
    }
    recursionFun(n-1);
    if(n%2!=0)
        cout << n << "^" <<"2 + " ;
    
}

int main(){
    int n;
    cin >> n;
    recursionFun(n);
}