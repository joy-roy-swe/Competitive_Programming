#include<bits/stdc++.h>
using namespace std;
const int n = 1e6+10;
int A[n];
int hash_Arr[n];

int main(){
    long long N, K;
    cin >> N >> K;
    string answer = "NO";
    for(int i=1; i<=N; i++){
        cin >> A[i];
        hash_Arr[i] = A[i]+A[i-1];
    }
    for(int i=1; i<=N; i++){
        if(hash_Arr[i]==K){
            answer = "YES";
        }
    }        
    cout << answer <<endl;
}