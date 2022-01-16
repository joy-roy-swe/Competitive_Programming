#include <iostream>
using namespace std;

int region[22][22], location[5][2];
int visited[22][22];
int answer, n, C, top, rear;

struct ReseachCenter{
    int row, col;
};
ReseachCenter queue[10000];

void init(){
    top = -1; rear = -1;
    for(int i=0; i<22; i++){
        for(int j=0; j<22; j++){
            visited[i][j] = 0;
        }
    }
    for(int i=0; i<10000; i++){
        queue[i].row = 0;
        queue[i].col = 0;
    }
}

void discover(int row, int col, int val){
    int count = 0;

    for(int i=0; i<C; i++){
        if(visited[location[i][0]][location[i][1]] > 0){
            count++;
        }
    }
    if(count >= C)
        return;

    if((row-1) >= 1 && visited[row-1][col] == 0 && (region[row-1][col] == 1 || region[row-1][col] == 3)){
        visited[row-1][col] = val+1;
        ++rear;
        queue[rear].row = row-1;
        queue[rear].col = col;
    }
    if((row+1) <= n && visited[row+1][col] == 0 && (region[row+1][col] == 1 || region[row+1][col] == 3)){
        visited[row+1][col] = val+1;
        ++rear;
        queue[rear].row = row+1;
        queue[rear].col = col;
    }
    if((col-1) >= 1 && visited[row][col-1]==0 && (region[row][col-1]==1 || region[row][col-1]==3)){
        visited[row][col-1] = val+1;
        ++rear;
        queue[rear].row = row;
        queue[rear].col = col-1;
    }

    if((col+1) <= n && visited[row][col+1] == 0 && (region[row][col+1] == 1 || region[row][col+1] == 3)){
        visited[row][col+1] = val+1;
        ++rear;
        queue[rear].row = row;
        queue[rear].col = col+1;
    }
    while(top < rear){
        ++top;
        discover(queue[top].row, queue[top].col, visited[queue[top].row][queue[top].col]);
    }
}


int main(){
    
    int tc, temp;
    cin >> tc;
    while(tc--){
        init();
        cin >> n >> C;
        int x, y;
        for(int i=0; i<C; i++){
            cin >> x >> y;
            location[i][0] = x;
            location[i][1] = y;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> region[i][j];
            }
        }

        for(int i=0; i<C; i++){
            region[location[i][0]][location[i][1]] = 3;
        }
        
        answer = 9999;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                init();
                temp = 0;
                if(region[i][j] == 1){
                    visited[i][j] = 1;
                    discover(i, j, 1);
                    for(int k=0; k<C; k++){
                        if(temp < visited[location[k][0]][location[k][1]])
                            temp = visited[location[k][0]][location[k][1]];
                    }
                    if(answer>temp)
                        answer = temp;
                }
            }
        }
        cout << answer-1 <<endl;
    }
    
}