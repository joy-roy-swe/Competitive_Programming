#include <iostream>
#include <string>
#include <map>

using namespace std;

string compressString(string& str) {
    map<char, int> charFreq;

    // Parse the input string and store character frequencies
    for (int idx = 0; idx < str.size(); idx += 2) {
        char ch = str[idx];
        int freq = str[idx + 1]-'0';
        if (charFreq.find(ch) != charFreq.end())
            charFreq[ch] += freq;
        else
            charFreq[ch] = freq;
    }

    string answer = "";
    // Construct the compressed string based on character frequencies
    for (auto ch : charFreq) {
        while (ch.second != 0) {
            answer += ch.first;
            ch.second--;
        }
    }
    return answer;
}

int main() {
    string str = "a2b1c3d1a2";
    string compressedString = compressString(str);
    cout << "Compressed String: " << compressedString << endl;

    return 0;
}
