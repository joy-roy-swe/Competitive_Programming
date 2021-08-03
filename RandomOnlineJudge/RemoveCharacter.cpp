#include <bits/stdc++.h>
using namespace std;

int main(){
    string string1, string2;
    cin >> string1 >> string2;
    //int i,j;
    // for(i=0; i<string2.size(); i++){
    //     for(j=0; j<string1.size(); j++){
    //         if(string2[i]==string1[j]){
    //             string1.erase(j);
    //         }
    //     }
    // }
    for (char ch: string2){
        string1.erase(std::remove(
            string1.begin(),string1.end(), ch),
            string1.end());
    }
    cout << string1 <<endl;
}