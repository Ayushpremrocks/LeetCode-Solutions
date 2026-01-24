class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>map(128,-1);
        int n=s.size();
        int l=0,r=0,maxLen=0;
        while(r<n){
            if(map[s[r]]!=-1) l=max(l,map[s[r]]+1);
            map[s[r]]=r;
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};