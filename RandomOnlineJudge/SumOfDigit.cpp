#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, sum=0, temp=0;
    cin >> t;
    while(t--){
        cin >> n;
        while(n>0){
            temp = n%10;
            sum += temp;
            n = n/10;
        }
        cout << sum << endl;
    }
}