#include <bits/stdc++.h>
using namespace std;

void printVector(vector<pair<int,int>> v){
    cout << "Size: " <<v.size() << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i].first <<" " << v[i].second << endl;
    }
    cout << endl;

}
int main(){
    vector <pair<int,int>> v;  //v={{1,2},{3,4}};
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x,y}); //v.push_back(make_pair(x,y));
    }
    printVector(v);
}