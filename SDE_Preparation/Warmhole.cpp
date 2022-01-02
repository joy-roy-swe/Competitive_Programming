#include <iostream>
using namespace std;
int space[10][5], visited[10];
int ans, n, flag;

int MIN(int x, int y){
    if(x>y) return y;
    else return x;
}

int ABS(int a){
    if(a<0) return -a;
    else return a;
}

int getDistance(int sx, int sy, int dx, int dy){
    int xd = ABS(dx-sx);
    int yd = ABS(dy-sy);
    return (xd+yd);
}

void solve(int sx, int sy, int dx, int dy, int dis){
    ans = MIN(ans, getDistance(sx, sy, dx, dy)+dis);
    for(int i=0; i<n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            int temp = getDistance(sx, sy, space[i][0], space[i][1]) + dis + space[i][4];
            solve(space[i][2], space[i][3], dx, dy, temp);
            temp = getDistance(sx, sy, space[i][2], space[i][3]) + dis + space[i][4];
            solve(space[i][0], space[i][1], dx, dy, temp);
            visited[i] = 0;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int sx,sy,dx,dy;
        cin >>sx >>sy >>dx >>dy;

        for(int i=0; i<n; i++){
            visited[i] = 0;
            for(int j=0; j<5; j++){
                cin >> space[i][j];
            }
        }
        ans = 999999;
        solve(sx, sy, dx, dy, 0);
        cout << ans << endl;
    }
}