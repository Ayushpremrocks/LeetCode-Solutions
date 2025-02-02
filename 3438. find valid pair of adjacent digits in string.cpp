class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char,int>result;
        for(char c:s){
            result[c]++;
        }
        for(int i=0;i<s.size();i++){
            char digitFirst = s[i];
            char digitSecond = s[i+1];
            if(digitFirst!=digitSecond){
                if (result[digitFirst] == (digitFirst - '0') && result[digitSecond] == (digitSecond - '0')){
                    return string(1, digitFirst) + string(1, digitSecond);
                }
            }
        }
        return "";
    }
};