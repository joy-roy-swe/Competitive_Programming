#include <iostream>
using namespace std;
int gates[4];
int fisherman[4];
int visited[20];
int N, Answer = 999;

void permutation(int l, int r){
    if(l==r){
        int i, j, k, dist=0;

        for(i=0; i<fisherman[0]; i++){
            dist = dist + abs(visited[i]-gates[0]);
        }

        for(j=0; j<fisherman[1]; j++){
            dist = dist + abs(visited[i]-gates[1]);
            i++;
        }

        for(k=0; k<fisherman[2]; k++){
            dist = dist + abs(visited[i]-gates[2]);
            i++;
        }
        dist = dist+i;
        Answer = min(Answer, dist);
        return;
    }
    else{
        for(int i=l; i<=r; i++){
            swap(visited[i], visited[l]);
            permutation(l+1, r);
            swap(visited[i], visited[l]);
        }
    }
}

int main(){
    
    cin >> N;

    for(int i=0; i<3; i++){
        cin >> gates[i];
    }
    for(int i=0; i<3; i++){
        cin >> fisherman[i];
    }
    for(int i=0; i<N; i++){
        visited[i] = i+1;
    }
    permutation(0, N-1);
    cout << Answer <<endl;
    return 0;
}