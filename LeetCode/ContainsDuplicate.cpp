#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int pf[N];

int main(){
    int n;
    cin >> n; 
    int arr[n];
    for(int i=0; i<n; i++){
        cin >>arr[i];
        pf[arr[i]]++;
    }
    string answer = "false";
    for(int i=0; i<n; i++){
        cout << pf[i] <<" ";
    }
    cout <<endl;
    for(int i=0; i<n; i++){
        if(pf[i]>=2){
            answer = "true";
        }
    }
    cout << answer <<endl;
}




//Another Way.
// unordered_map<int,int>m;
// for(int i=0;i<nums.size();i++){
//     m[nums[i]]++;
// }
// for(auto x:m){
//     if(x.second>1){
//         return 1;
//     }
// }
// return 0;
// }