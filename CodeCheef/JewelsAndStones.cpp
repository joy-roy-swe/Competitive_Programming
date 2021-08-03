#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, result; 
    string J, S;
    cin >> t;
    while (t--){
        cin >> J >> S;
        result=0;
        for(int i=0; i<S.size(); i++){
            for(int k=0; k<J.size(); k++){
                if(S[i]==J[k]){
                    result++;
                    break;
                }
            }
        }
        cout << result <<endl;
    }
    
}