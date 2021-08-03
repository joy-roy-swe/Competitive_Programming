#include <bits/stdc++.h>
using namespace std;

int main(){

    int test_case;
    cin >> test_case;

    while(test_case--){
        int color1, color2, participants, one, two;
        int cost1=0, cost2=0;
        cin >> color1 >> color2;
        cin >> participants;
        for (int i = 0; i < participants; i++){
            cin >> one >> two;
            cost1 = cost1+(one*color1)+(two*color2);
            cost2 = cost2+(one*color2)+(two*color1);
        }
        int result = min(cost1,cost2);
        cout << result << endl;      

    }
}