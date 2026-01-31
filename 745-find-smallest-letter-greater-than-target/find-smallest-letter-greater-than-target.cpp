class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int diff=0;
        char s=letters[0];
        int flag = false;
        for(int i=0;i<letters.size();i++){
            if(!flag){
                if(letters[i]>target){
                    s=letters[i];
                    flag=true;
                }
            }else{
                if(letters[i]>target && letters[i]<s) s=letters[i];
            }
        }
        return s;
    }
};