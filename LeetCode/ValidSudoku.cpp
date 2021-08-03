#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<string> s;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] == '.')
                continue;

            string x = to_string(board[i][j]);

            string row = "[" + to_string(i) + x;
            string column = "{" + to_string(j) + x;
            string boxes = "(" + to_string(i / 3) + x + to_string(j / 3);

            if (s.find(row) != s.end() || s.find(column) != s.end() || s.find(boxes) != s.end())
                return false;
            else{
                s.insert(row);
                s.insert(column);
                s.insert(boxes);
            }
        }
    }
    return true;
}