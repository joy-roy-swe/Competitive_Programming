#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    int len1 = 0, len2=0;
    len1 = a.size();
    len2 = b.size();
    cout << len1 << " " << len2 <<endl;
    string c = a+b;
    cout << c << endl;
    char ch;
    ch = a[0];
    a[0] = b[0];
    b[0] = ch;
    cout << a <<" " << b;

}