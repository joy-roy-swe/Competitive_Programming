#include<bits/stdc++.h>
using namespace std;

string solve (vector<int> A) {
   string ans;
   int temp=0;
   int n = A.size();
   for(int i=0; i<n; i++){
      if(i < n/2){
          //first digit
         while(A[i]>=10){
            A[i] /= 10;
         }
      }
      else{
          //last digit
         A[i] = A[i]%10;
       }
       //first and last digit store in temp        
      temp = (temp*10)+A[i];
   }
   if(temp % 11 == 0){
        ans="OUI";
   }
   else ans="NON";
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