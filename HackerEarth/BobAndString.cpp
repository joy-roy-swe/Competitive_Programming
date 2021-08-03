#include<bits/stdc++.h>
using namespace std;

int main(){
    int test_case;
    cin >> test_case;
    while(test_case--){
        string S, T;
        cin >> S >> T;
        map<char,int> hash_map;
        for(int i=0; i<S.length(); i++){
            hash_map[S[i]]++;
        }
        for(int i=0; i<T.length(); i++){
            hash_map[T[i]]--;
        }
        int operations = 0;
        for(auto x: hash_map){
            if(x.second>0){
                operations+=x.second;
            }
            else if(x.second<0){
                operations+=abs(x.second);
            }
        }
        cout << operations <<endl;
    }
}