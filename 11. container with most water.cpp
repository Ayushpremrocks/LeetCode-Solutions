class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int result=0;
        for(int i=0;i<height.size()-1;i++){
            while(i<j){
                int value = min(height[i],height[j])*(j-i);
                result = max(result,value);
                if(height[i]<height[j]){
                    i++;
                }else{
                    j--;
                }
            }
        }
        return result;
    }
};