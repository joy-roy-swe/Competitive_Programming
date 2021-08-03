#include<bits/stdc++.h>
using namespace std;

int main(){
    string input_str;
    cin >> input_str;
    int Z=0,O=0;
    for(int i=0; i<input_str.size(); i++){
        if(input_str[i]=='z'){
            Z++;
        }
        else if(input_str[i]=='o'){
            O++;
        }
    }
    if(O%Z==0 && O!=Z){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}