#include<bits/stdc++.h>
using namespace std;

int main(){
    pair <int, string> p;
    p = {1, "abc"};
    cout << p.first << " " << p.second << endl;

    int a[] = {1,2,3};
    int b[] = {4,5,6};
    pair<int,int> pair_arr[3];
    pair_arr[0] = {1,4};
    pair_arr[1] = {2,5};
    pair_arr[2] = {3,6};
    swap(pair_arr[0], pair_arr[2]);
    for(int i=0; i<3; i++){
        cout << pair_arr[i].first<< " " << pair_arr[i].second <<endl;
    }
    
}