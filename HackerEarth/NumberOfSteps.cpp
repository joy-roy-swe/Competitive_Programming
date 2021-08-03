#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, min = INT_MAX, count = 0;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < min)
            min = a[i];
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++){
        while (a[i] > min && b[i] != 0){
            a[i] -= b[i];
            count++;
        }
        if (a[i] < min){
            min = a[i];
            i = -1;
        }
        if (a[i] < 0){
            count = -1;
            break;
        }
    }
    cout << count <<endl;
}