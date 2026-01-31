class Solution {
public:
    string removeStars(string s) {
       string res="";
       int i=s.size()-1;
       int jump=0;
       while(i>=0){
            if(s[i]=='*'){
                jump++;
                i--;
            }
            else{
                if(jump>0){
                    jump--;
                    i--;
                }else{
                    res+=s[i];
                    i--;
                }
            }
       }
       reverse(res.begin(),res.end());
       return res;
    }
};