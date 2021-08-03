#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,flag=0;
    string s;
    cin >> n >> s;

    for(int i=0; i<n; i++){
        if(s[i]=='H' && s[i+1]=='H'){
            if(flag==0){
                cout << "No" <<endl;
                flag++;
            }
        }
        else if(s[i]=='.'){
            s[i]='B';
        }
    }
    if(flag!=1){
        cout << "Yes" <<endl;
        for(int i=0; i<n; i++){
            cout <<s[i];
        }
    }
}