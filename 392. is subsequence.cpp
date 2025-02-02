class Solution {
public:
    bool isSubsequence(string s, string t) {
        string value;
        int j=0;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[j]){
                value = value + t[i];
                j++;
            }
        }
        if (value==s){
            return true;
        }else{
            return false;
        }
    }
};