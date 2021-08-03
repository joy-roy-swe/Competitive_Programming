#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, row, column, i, j, result=0, upper=0,lower=0;
    char ch;
    cin >> t;
    while(t--){
        cin >> row >> column;
        char arr[row][column];
        //cin.ignore();
        for(i=0; i<row; i++){
            for(j=0; j<column; j++){
                cin>>ch; 
                arr[i][j] = ch;
            }
        }
        
        for(i=0; i<1; i++){
            for(j=0; j<column; j++){
                if(arr[i][j]=='#'){
                    upper+=1;
                }
            }
        }
        for(i=row-1; i<row; i++){
            for(j=0; j<column; j++){
                if(arr[i][j]=='#'){
                    lower+=1;
                }
            }
        }
        result = max(upper,lower);
        cout << "Result: "<<result << endl;
        upper=0;
        lower=0;
        result=0;
    }
}