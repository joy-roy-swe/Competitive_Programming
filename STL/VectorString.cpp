#include <bits/stdc++.h>
using namespace std;

void printVector(vector<string> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] <<" ";
    }
    cout << endl;

}
int main(){
    vector <string> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string x;
        cin >>x;
        v.push_back(x);
    }
    printVector(v);
}