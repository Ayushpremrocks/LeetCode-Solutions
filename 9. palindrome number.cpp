class Solution {
public:
    bool isPalindrome(int x) {
        int value=0,temp=x;
        while(temp>0){
            int remainder = temp%10;
            if (value > (INT_MAX - remainder) / 10) {
                return false;
            }
            temp = temp/10;
            value = value*10+remainder;
        }
        if(x<0 || x!=0 && x%10==0){
            return false;
        }else if(x==value){
            return true;
        }else{
            return false;
        }
    }
};