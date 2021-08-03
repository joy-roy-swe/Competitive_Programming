#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >>s;
        map <char,int> h_map;
        for(int i=0; i<s.length(); i++){
            h_map[s[i]]++;
        }
        int r=0, u=0, b=0, y=0;
        for(auto x: h_map){
            if(x.first == 'r'){
                r = x.second;
            }
            else if(x.first == 'u'){
                u = x.second;
            }
            else if(x.first == 'b'){
                b = x.second;
            }
            else if(x.first == 'y'){
                y = x.second;
            }
        }
        int m, n, result;
        m = min(r,u);
        n = min(b,y);
        result = min(m,n);
        cout << result<<endl;        
    }
}