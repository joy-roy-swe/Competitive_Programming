#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int absent=0, late=0, max_late=0;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='A'){
            absent++;
            if(absent==2) cout << "false";
            late=0;
        }
        else if(s[i]=='L'){
            late++;
            max_late = max(late,max_late);
            if(max_late==3) cout << "false";
        }
        else{
            late=0;
            continue;
        }
    }
    cout << "true";
}