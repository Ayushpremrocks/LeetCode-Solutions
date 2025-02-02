class Solution {
public:
    int trap(vector<int>& height) {
        int result=0;
        if(height.size()==0) return 0;
        int l=0; int r = height.size()-1; 
        int left = height[l]; int right = height[r];
        while(l<r){
            if(left<right){
                l++;
                left= max(left,height[l]);
                result = result + (left-height[l]);
            }else{
                r--;
                right=max(right,height[r]);
                result = result + (right-height[r]);
            }
        }
        return result;
    }
};