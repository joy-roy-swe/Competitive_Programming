class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1){
            return s;
        }
        vector<string> v(numRows);
        int row = 0;
        bool forward = true;
        for(int i=0; i<s.length(); i++){
            v[row].push_back(s[i]);
            if(row == numRows - 1)
                forward = false;
            else if(row == 0)
                forward = true;

            if(forward)
                row++;
            else
                row--; 
        }
        string answer = "";
        for(int i=0; i<numRows; i++){
            answer.append(v[i]);
        }
        return answer;
    }
};