#include <iostream>
using namespace std;

int playGround[20][5];
int row;
int answer;

int max(int x, int y){
    if(x>y) return x;
    else return y;
}

void getMaxCoins(int current_row, int current_col, bool bombUsed, int coins, int isRowSafe) {
    //base condition
    if(current_row < 0 || current_col >= 5 || current_col < 0){
        answer = max(answer, coins);
        return;
    }
    // for 0 and 1
    if(playGround[current_row][current_col] == 1 || playGround[current_row][current_col] == 0){
        int new_coins = coins;
        if(playGround[current_row][current_col] == 1){
            new_coins++;
        }
        if(bombUsed){
            isRowSafe--;
        }
        getMaxCoins(current_row-1, current_col, bombUsed, new_coins, isRowSafe);
        getMaxCoins(current_row-1, current_col + 1, bombUsed, new_coins, isRowSafe);
        getMaxCoins(current_row-1, current_col - 1, bombUsed, new_coins, isRowSafe);
    }
    // for 2, enamy
    else if(playGround[current_row][current_col] == 2){
        // for no safe row and bomb already used
        if(bombUsed && isRowSafe <= 0){
            answer = max(answer, coins);
            return;
        }
        // for bomb already used but have safe row
        else if(bombUsed && isRowSafe > 0){
            isRowSafe--;
            getMaxCoins(current_row-1, current_col, bombUsed, coins, isRowSafe);
            getMaxCoins(current_row-1, current_col + 1, bombUsed, coins, isRowSafe);
            getMaxCoins(current_row-1, current_col - 1, bombUsed, coins, isRowSafe);
        }
        else{
            bombUsed = true;
            isRowSafe = 4;
            getMaxCoins(current_row-1, current_col, bombUsed, coins, isRowSafe);
            getMaxCoins(current_row-1, current_col + 1, bombUsed, coins, isRowSafe);
            getMaxCoins(current_row-1, current_col - 1, bombUsed, coins, isRowSafe);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> row;
        for(int i=0; i<row; i++){
            for(int j=0; j<5; j++){
                cin >> playGround[i][j];
            }
        }
        int isRowSafe = 0;
        answer = -999999;
        getMaxCoins(row-1, 1, false, 0, 0);
        getMaxCoins(row-1, 2, false, 0, 0);
        getMaxCoins(row-1, 3, false, 0, 0);
        cout << "Max Coins: " << answer <<endl;
    }
}