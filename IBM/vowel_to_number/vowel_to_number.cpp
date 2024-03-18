#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to convert vowels to numbers based on their occurrences
string vowelToNumber(string str) {
    string answer = "";
    unordered_map<char, bool> map;

    // Define vowels and mark them as true in the map
    map['a'] = true;
    map['e'] = true;
    map['i'] = true;
    map['o'] = true;
    map['u'] = true;
    map['A'] = true;
    map['E'] = true;
    map['I'] = true;
    map['O'] = true;
    map['U'] = true;

    int count = 1;

    // Iterate through the string
    for(int idx = 0; idx < str.length(); ++idx) {
        // If the character is a vowel, replace it with a number
        if(count > 9)
            count = 1;
        if(map.count(str[idx])) {
            answer += count + '0'; // Convert integer to character and append to answer
            count += 1;
        } else {
            answer += str[idx]; // Append non-vowel characters directly to the answer
        }
    }
    reverse(answer.begin(), answer.end()); // Reverse the answer string
    return answer;
}

int main() {
    // Example usage
    string str = "Australia";
    cout << "Original string: " << str << endl;
    cout << "After converting vowels to numbers: " << vowelToNumber(str) << endl;
    return 0;
}
