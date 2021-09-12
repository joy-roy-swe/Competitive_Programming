class Solution {
public:
    int reverse(int x) {
        bool nagetive=false;
        if(x<0){
            nagetive = true;
            x = abs(x);
        }

        string temp = to_string(x);
        string temp2 = "";
        
        for(int i=temp.size()-1; i>=0; i--){
            temp2 += temp[i];
        }
        long long checker = stoll(temp2);
        if(checker>INT_MAX || checker<INT_MIN){
            return 0;
        }
        else{
            if(nagetive){
                temp2 = "-"+temp2;
                x = stoll(temp2);            
            }
            else{
                x = stoll(temp2);
            }
        }
        return x;
    }
};