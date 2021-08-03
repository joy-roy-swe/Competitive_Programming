#include <bits/stdc++.h>
using namespace std;

int main(){
    string str, reverse_str;
    cin >> str;
    for(int i=str.size()-1; i>=0; i--){
        reverse_str += str[i];
    }
    if(str==reverse_str){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}