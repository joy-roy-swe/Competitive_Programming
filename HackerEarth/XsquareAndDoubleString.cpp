#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string ans = "No";
        map < char, int > maping;
        for (int i = 0; i < s.size(); i++) {
            maping[s[i]]++;
        }
        for (auto x: maping) {
            if (x.second<=2) {
                ans = "Yes";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}