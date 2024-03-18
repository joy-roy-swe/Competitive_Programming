#include <iostream>
#include <string>

using namespace std;

// Function to perform the append and delete operation
string appendAndDelete(string s, string t, int k) {
    int s_size = s.length();
    int t_size = t.length();
    int temp, similar = 0;

    // Determine the length of the longest string
    if(s_size > t_size)
        temp = s_size;
    else
        temp = t_size;

    // Calculate the number of similar characters at the beginning of both strings
    for(int idx = 0; idx < temp; ++idx) {
        if(s[idx] == t[idx])
            ++similar;
        else
            break;
    }

    // Check if it is possible to perform the operation within k steps
    if(s_size + t_size <= k)
        return "Yes";
    else if(k - (s_size + t_size - 2 * similar) >= 0) {
        if((k - (s_size + t_size - 2 * similar)) % 2 == 0)
            return "Yes";
    } else
        return "No";

    return "No";
}

int main() {
    // Example usage
    string s = "hackerhappy";
    string t = "hackerrank";
    int k = 9;
    cout << "Can the operation be performed within " << k << " steps? " << appendAndDelete(s, t, k) << endl;
    return 0;
}
