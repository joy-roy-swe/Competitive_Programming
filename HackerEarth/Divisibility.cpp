#include <bits/stdc++.h>
using namespace std;

int main() {

    int N = 0;
    cin>>N;
    long long data[N];
    for(auto i=0; i<N; i++)
        cin>>data[i];

    string ans;
    int temp=0;
    for(int i=0; i<N; i++){
        temp = data[i]%10;
        if(temp%10==0){
            ans="Yes";
        }
        else ans="No";
    }
    cout<<ans;
    
    return 0;
}