#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M, counter = 0;
    cin >> N >> M;
    long long A[N];
    long long B[M];

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int j = 0; j < M; j++)
        cin >> B[j];

    unordered_set<long long> set_value;
    for (int i = 0; i < M; i++){
        set_value.insert(B[i]);
    }
    vector<long long> Arr;
    for (int i = 0; i < N; i++){
        if (set_value.find(A[i]) == set_value.end()){
            Arr.push_back(A[i]);
        }
    }
    for (int i = 0; i < Arr.size(); i++)
        cout << Arr[i] <<endl;
}
