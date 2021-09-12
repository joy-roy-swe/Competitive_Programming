class Solution {
public:
    bool isPalindrome(int x) {
        bool answer;
        if(x<0){
            return false;
        }
        else{
            string pld = to_string(x);
            string pld2 = "";
            for(int i=pld.length()-1; i>=0; i--){
                pld2 += pld[i];
            }
            if(pld == pld2){
                answer = true;
            }
            else{
                answer = false;
            }
        }
        return answer;
    }
};