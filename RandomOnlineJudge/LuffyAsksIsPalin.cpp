#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int hash_arr[N][26];

int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i=0; i<N; i++){
            for(int j=0; j<26; j++){
                hash_arr[i][j] = 0;
            }
        }
        int n, q;
        cin >> n >>q;
        string s;
        cin >> s;
        for(int i=0; i<n; i++){
            hash_arr[i+1][s[i] - 'a']++;
        }
        for(int i=0; i<26; i++){
            for(int j=1; j<=n; j++){
                hash_arr[j][i] += hash_arr[j-1][i];
            }
        }
        while(q--){
            int l,r;
            cin >> l, r;
            int oddCT = 0;
            for(int i=0; i<26; i++){
                int charCT = hash_arr[r][i] - hash_arr[l-1][i];
                if(charCT % 2 != 0)
                    oddCT++;
            }
            if(oddCT>1)
                cout << "NO" <<endl;
            else cout << "YES" <<endl;
        }
    }

}