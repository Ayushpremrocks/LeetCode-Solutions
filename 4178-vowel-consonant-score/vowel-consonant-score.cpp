class Solution {
public:
    int vowelConsonantScore(string s) {
        int vc=0,cc=0;
        for(auto it:s){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u') vc++;
            else if(it>='a' && it<='z')cc++;
        }
        if(cc>0) return floor(vc/cc);
        else return 0;
    }
};