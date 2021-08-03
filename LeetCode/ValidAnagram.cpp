#include<bits/stdc++.h>
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;
    map<char,int> hash_map;
    bool result = true;
    for(int i=0; i<S.length(); i++){
        hash_map[S[i]]++;
    }
    for(int i=0; i<T.length(); i++){
        hash_map[T[i]]--;
    }
    for(auto x: hash_map){
        if(x.second!=0){
            result = false;
        }
    }
    cout << result;
}