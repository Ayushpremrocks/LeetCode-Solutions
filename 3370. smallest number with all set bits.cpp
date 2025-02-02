class Solution {
public:
    int smallestNumber(int n) {
        int x=(floor(log (n)/log (2)));
        int result;
        for(int i=0;i<=x;i++){
            result=result+pow(2,i);
        }
        return result;
    }
};