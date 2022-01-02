#include <iostream>
using namespace std;

int pipes[51][51], visited[51][51];
int N, M, X, Y, L, top, rear, answer;

struct endoscope {
    int x,y,l;
};
endoscope queue[1000];

void init(){
    top = rear = 0;
    answer = 0;
}
void enqueue(endoscope temp){
    queue[top++] = temp;
    visited[temp.x][temp.y] = 1;
}
endoscope dequeue(){
    return queue[rear++];
}

bool isValid(int x, int y){
    return (x>=0 && x<N && y>=0 && y<M);
}

bool left(int x, int y){
    return (pipes[x][y] == 1 || pipes[x][y] == 3 || pipes[x][y] == 6 || pipes[x][y] == 7);
}

bool right(int x, int y){
    return (pipes[x][y] == 1 || pipes[x][y] == 3 || pipes[x][y] == 4 || pipes[x][y] == 5);
}

bool up(int x, int y){
    return (pipes[x][y] == 1 || pipes[x][y] == 2 || pipes[x][y] == 4 || pipes[x][y] == 7);
}

bool down(int x, int y){
    return (pipes[x][y] == 1 || pipes[x][y] == 2 || pipes[x][y] == 5 || pipes[x][y] == 6);
}

void readCase(){
    cin >> N >> M >> X >> Y >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> pipes[i][j];
            visited[i][j] = 0;
        }
    }
}

int explore(int x, int y, int l){
    enqueue({x,y,l});
    visited[x][y] = 1;
    while(top!=rear){
        endoscope temp = dequeue();
        int x = temp.x;
        int y = temp.y;
        int l = temp.l;

        if(l==0){
            continue;
        }
        answer++;
        if(isValid(x,y-1) && left(x,y) && right(x, y-1) && visited[x][y-1]==0){
            enqueue({x,y-1,l-1});
        }
        if(isValid(x, y+1) && right(x, y) && left(x, y+1) && visited[x][y+1]==0){
            enqueue({x, y+1, l-1});
        }
        if(isValid(x-1, y) && up(x, y) && down(x-1, y) && visited[x-1][y]==0){
            enqueue({x-1, y, l-1});
        }
        if(isValid(x+1, y) && down(x, y) && up(x+1, y) && visited[x+1][y]==0){
            enqueue({x+1, y, l-1});
        }
    }
    return answer;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        init();
        readCase();
        cout << explore(X, Y, L) << endl;
    }
}