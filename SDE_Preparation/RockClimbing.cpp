#include<iostream>
using namespace std;

int N, M, l = 0, f = 0;
int path[15][15], visited[15][15];

void initVisited(){
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            visited[i][j]=0;
        }
    }
}
void readCase(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> path[i][j];
        }
    }
}

void dfs(int i, int j){
    if(i<0 || j<0 || i>=N || j>=M)
        return;
    if(visited[i][j] != 0)
        return;
    visited[i][j] = 1;

    if(path[i][j] == 3){
        f=1;
        return;
    }

    if(j+1<M && (path[i][j+1]==1 || path[i][j+1]==3) && visited[i][j+1]==0)
        dfs(i, j+1);
    
    if(j-1>=0 && (path[i][j-1]==1 || path[i][j-1]==3) && visited[i][j-1]==0)
        dfs(i, j-1);
    
    int h=1;
    for(h=1; h<=l; h++){
        if(h<=l && (i-h)>=0 && (path[i-h][j]==1 || path[i-h][j]==3) && visited[i-h][j]==0)
            dfs(i-h, j);
    }

    for(h=1; h<=l; h++){
        if(h<=l && i+h<N && (path[i+h][j]==1 || path[i+h][j]==3) && visited[i+h][j]==0)
            dfs(i+h, j);
    }
}

int main(){
    readCase();
    for(l=0; l<N; l++){
        initVisited();
        f = 0;
        dfs(N-1, 0);
        if(f){
            cout << l;
            break;
        }
    }
    return 0;
}