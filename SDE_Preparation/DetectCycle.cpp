#include <iostream>
using namespace std;

int graph[11][51], visited[11];
int answer[11], stack[11], cycleSum = 999999;
int top = -1, answerSize = -1, n, m;

void init(){
    for(int i=0; i<11; i++){
        visited[i] = 0;
        for(int j=0; j<51; j++){
            graph[i][j] = 0;
        }
    }
}
void isCyclic(int current){
    if(visited[current]==1 && top != -1){
        int i, localSum = stack[top];
        for(i=top-1; i>=0 && stack[i] != current; i--){
            localSum += stack[i];
        }
        if(i != -1 && localSum<cycleSum){
            answerSize = -1;
            cycleSum = localSum;
            answer[++answerSize] = stack[top];
            for(i=top-1; i>=0 && stack[i] != current; i--){
                answer[++answerSize] = stack[i];
            }
        }
        return;
    }
    else{
        visited[current] = 1;
        for(int i=1; i<=n; i++){
            if(graph[current][i] == 1){
                stack[++top] = i;
                isCyclic(i);
                top--;
            }
        }
        visited[current] = 0;
    }
}
void SWAP(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1])
				SWAP(&arr[j], &arr[j+1]);
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        init();
        cin >> n >> m;
        int t1, t2;
        while(m--){
            cin >> t1 >>t2;
            graph[t1][t2] = 1;
        }
        for(int i=1; i<n; i++){
            if(visited[i] == 0){
                stack[++top] = 1;
                isCyclic(i);
                top--;
            }
        }
        bubbleSort(answer, answerSize+1);
        printArray(answer, answerSize+1);
        
    }    
}