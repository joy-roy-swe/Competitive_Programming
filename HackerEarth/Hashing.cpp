/*
Given array a of N integers. Giver Q quries and each query 
giver an number X, print count of that number in array.

Constraints
1 <= N <= 10^5;
1 <= a[i] <= 10^7;
1 <= Q <= 10^5;
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int hash_arr[N];

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        hash_arr[a[i]]++;
    }
    int q;
    cin >> q;
    while(q--){
        int x, cnt=0;
        cin >> x;
        cout << hash_arr[x] << endl;
    }

}