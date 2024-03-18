#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str, answer;

void asciiToText(int idx){
    if(idx>=str.length())
        return;
    string tempStr = str.substr(idx, 2);
    int current = stoi(tempStr);
    if(current==32)
        answer += " ";
    else if((current>=65 && current<=90) || (current>=97 && current<=122))
        answer += char(current);
    else{
        tempStr = str.substr(idx, 3);
        answer += char(stoi(tempStr));
        asciiToText(idx + 3);
        return;
    }
    asciiToText(idx + 2);
}

int main(){
    
    cin >> str;
    reverse(str.begin(), str.end());
    asciiToText(0);
    cout << "Decoded password is : " << answer << endl;

}