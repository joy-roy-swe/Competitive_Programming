#include <iostream>
using namespace std;

int n, sx, sy, dx, dy, shortestRoute;
int X[10], Y[10], visited[10];

int ABS(int a){
    if(a<0) return -a;
    else return a;
}

int getDistance(int sx, int sy, int dx, int dy){
    int xd = ABS(dx-sx);
    int yd = ABS(dy-sy);
    return (xd+yd);
}

void explore(int current, int cost, int nodeLeft){
    if(nodeLeft <= 1){
        if(cost+getDistance(X[current], Y[current], dx, dy) < shortestRoute){
            shortestRoute = cost + getDistance(X[current], Y[current], dx, dy);
        }
        return;
    }
    visited[current] = 1;
    for(int i=0; i<n; i++){
        if(visited[i] == 0){
            explore(i, cost+getDistance(X[current], Y[current], X[i], Y[i]), nodeLeft-1);
        }
    }
    visited[current] = 0;
}

int main() {
    int t=10;
    while(t--){
        cin >> n;
        cin >> sx >> sy >> dx >> dy;
        for(int i=0; i<n; i++){
            cin >> X[i] >> Y[i];
            visited[i] = 0;
        }
        shortestRoute = 1000000;
        for(int i=0; i<n; i++){
            explore(i, getDistance(X[i], Y[i], sx, sy), n);
        }
        cout << "# " << (10-t) << " " << shortestRoute << endl;
    }
    return 0;
}