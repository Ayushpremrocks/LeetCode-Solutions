class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxLen=0,maxFreq=0;
        int n=s.size();
        vector<int>mpp(26,0);
        while(r<n){
            mpp[s[r]-'A']++;
            maxFreq=max(maxFreq,mpp[s[r]-'A']);
            if(((r-l+1)-maxFreq)>k){
                mpp[s[l]-'A']--;
                l++;
            }
            if(((r-l+1)-maxFreq)<=k) maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};