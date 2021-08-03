#include<bits/stdc++.h>
using namespace std;

string solve (vector<int> A) {
    int i, temp, N, Num;
    int even_sum = 0, odd_sum = 0;
    string ans;
    N = A.size();

    for (i = 0; i < N / 2; i++){
        temp = A[i];
        while (temp / 10 > 0){
            temp = temp / 10;
        }
        if (i % 2 == 0)
            even_sum += temp;
        else
            odd_sum += temp;
    }

    for (i = N / 2; i < N; i++){
        temp = A[i] % 10;
        if (i % 2 == 0)
            even_sum += temp;
        else
            odd_sum += temp;
    }
    Num = abs(even_sum - odd_sum);
    if (Num == 0 || Num % 11 == 0)
        ans = "OUI";
    else
        ans = "NON";

    return ans;

}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A=0; i_A<N; i_A++)
    {
    	cin >> A[i_A];
    }

    string out_;
    out_ = solve(A);
    cout << out_;
}