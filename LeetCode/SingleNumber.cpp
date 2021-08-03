#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    map<int, int> h_arr;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        h_arr[arr[i]]++;
    }
    int result = 0; 
    for(auto x: h_arr){
        if(x.second <2 ){
            result = x.first;
        }
    }
    cout <<result;

}