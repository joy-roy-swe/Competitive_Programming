#include <iostream>
using namespace std;

int minCost, n;
int path[15][15];
int visited[15];

void init(){
    for(int i=0; i<15; i++){
        visited[i] = 0;
    }
    minCost = 1000000;
}

void explore(int current,int cost, int nodeleft){
    if(nodeleft == 0){
        cost += path[current][0];
        if(cost < minCost)
            minCost = cost;
        return;
        
    }

    for(int i=1; i<n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            explore(i, cost+path[current][i], nodeleft-1);
            visited[i] = 0;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        init();
        cin >> n;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> path[i][j];
            }
        }
        explore(0, 0, n-1);
        cout << minCost << endl;
    }
    return 0;
}