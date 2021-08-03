#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,temp;
    cin >> t;
    while(t--){
        cin >> n;
        int reverse=0;
        while(n>0){
            temp = n%10;
            //cout << temp;
            reverse = reverse*10+temp;
            n = n/10;
        }
        cout <<reverse << endl;
    }
}