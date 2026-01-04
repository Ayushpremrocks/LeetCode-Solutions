class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        int i=0;
        for(i=n-1;i>=0;i--){
            if(s[i]=='2') break;
        }
        if(s[n-1]=='1') return s.substr(0,i+1);
        return s;
    }
};