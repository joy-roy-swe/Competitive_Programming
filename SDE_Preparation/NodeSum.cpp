#include <iostream>
using namespace std;

char str[1050];
int k, answer;

void getSum(){
    int level=-1;
    int i=0;
    while(str[i] != '\0'){
        if(str[i]=='('){
            level++;
        }
        else if(str[i]==')'){
            level--;
        }
        else if(level == k){
            int x = str[i] - '0';
            i++;
            while(str[i]>=48 && str[i]<=57){
                int temp = str[i] - '0';
                x = x*10+temp;
                i++;
            }
            i--;
            answer+=x;
        }
        i++;
    }
}

int main(){
    cin >> k;
    scanf("%s", &str);
    answer = 0;
    getSum();
    cout << answer <<endl;
}