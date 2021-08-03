#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    long long i, N, match_sticks=0, temp=0;
    cin >> T;

    while(T--){
        cin >> N;
        long long j = N;
        if(N==0){
            match_sticks = 6;
        }
        while(j--){
            temp = N%10;
            N = N/10;
            j=N;
            if(temp == 0 || temp == 6 ||temp == 9){
                match_sticks += 6; 
            }
            else if(temp == 2 ||temp == 3 ||temp == 5){
                match_sticks += 5;
            }
            else if(temp == 1){
                match_sticks += 2;
            }
            else if (temp == 4){
                match_sticks += 4;
            }
            else if(temp == 7){
                match_sticks += 3;
            }
            else if(temp == 8){
                match_sticks += 7;
            }                 
        }
        if (match_sticks % 2 == 0){
            for(i=0; i<(match_sticks/2); i++){
                cout << "1";
            }
        } else{
            cout << "7";
            for(i=0; i<((match_sticks-3)/2); i++){
                cout << "1";
            }                        
        }
        cout <<endl;
        match_sticks = 0;
    }
} 