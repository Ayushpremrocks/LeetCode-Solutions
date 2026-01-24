class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(128,0);
        int l=0,r=0,maxLen=0;
        int n=s.size();
        while(r<n){
            l=max(l,mpp[s[r]]);
            maxLen = max(maxLen,r-l+1);
            mpp[s[r]]=r+1;
            r++;
        }
        return maxLen;
    }
};