#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin >> N >>K;
    int Arr[N];
    for(int i=0; i<N; i++){
        cin >> Arr[i];
    }
    for(int i=1; i<N; i++){
        Arr[i] = Arr[i]+Arr[i-1];
    }
    int MaxSum = Arr[K-1];
    for(int i=K; i<N; i++){
        MaxSum = max(MaxSum, Arr[i]-Arr[i-K]);
    }
    cout << MaxSum;
}