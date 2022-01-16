#include <iostream>
using namespace std;

int matrix[20][20];
int n, m, k;
int answer;

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrix[i][j] = 0;
        }
    }
}

void flip(int i){
    for(int j=0; j<n; j++){
        if(matrix[j][i] == 1)
            matrix[j][i] = 0;
        else matrix[j][i] = 1;
    }
}
void printCase(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout <<matrix[i][j] <<" ";
        }
        cout <<endl ;
    }
    cout <<endl ;
}
void getMaxRow(int k_v){
    if(k_v==0){
        int temp=0;
        for(int i=0; i<n; i++){
            int flag = 1;
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    flag = 0;
                    break;
                }         
            }
            if(flag)
                temp+=1;
        }
        //cout <<"temp : " << temp <<endl;
        if(answer<temp)
            answer = temp;
        return;
    }
    for(int i=0; i<m; i++){
        flip(i);
        getMaxRow(k_v-1);
        flip(i);
    }
}

int main(){
    init();
    cin >> n >> m >>k;
    answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }
    getMaxRow(k);
    cout << answer <<endl;
}


