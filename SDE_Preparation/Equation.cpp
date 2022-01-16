/*
X = A * N + B*log(N) + C*N*N*N
INTPUT A B C X
OUTPUT N
1 <= A <=100
1 <= B <=100
0 <= C <=100
0 <= X <=10^15
N must be integer
0 <= N <=10^13
*/
#include <iostream>
using namespace std;

long long A, B, C, X, N;
int Case;

void readCase(){
    cin >> A >>B >>C >>X;
}

int log(long long n){
    double d = (double)n;
    int value = 0;
    while(d>=2.71828){
        d = d/2.71828;
        value++;
    }
    return value;
}

void solveCase(){
    long long low, mid, high, result;
    N = -1;
    low = 0;
    if(C == 0){
        high = 10000000000000;
    }
    else{
        high = 100000;
    }

    while(low <= high){
        mid = (low+high)/2;
        result = A*mid + B*log(mid) + C*mid*mid*mid;
        if(result<X)
            low = mid+1;
        else if(result > X)
            high = mid-1;
        else{
            N = mid;
            break;
        }
    }
}

void printCase(){
    cout << N <<endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        readCase();
        solveCase();
        printCase();
    }
}