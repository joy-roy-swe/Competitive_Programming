#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, A;
        int profit=0, max_profit=0, L,R;
        cin >> N >> A;
        int C[N], D[N], C_sum[N];
        C_sum[0] = 0;
        for(int i=1; i<=N; i++){
            cin >> L >> R;
            C[i] = L; 
            D[i] = R;
            C_sum[i] = L+C_sum[i-1];
        }
        for(int l=1; l<=N; l++){
            int maximum = D[l];
            int minimum = D[l];
            for(int r=l; r<=N; r++){
                maximum = max(maximum,D[r]);
                minimum = min(minimum,D[r]);
                profit = max(profit, (r-l+1)*A - (maximum-minimum)*(maximum-minimum) 
                                        - C_sum[r]+C_sum[l-1]);
            }
        }
        cout << profit <<endl;
    }
}

// 1
// 3 10
// 1 3
// 3 1
// 2 2
//output: 20