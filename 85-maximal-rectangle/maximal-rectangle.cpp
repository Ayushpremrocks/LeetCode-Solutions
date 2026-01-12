class Solution {
private:
    // next smallest to right
    vector<int>calNSR(vector<int>& height){
        stack<int>s;
        int n=height.size();
        vector<int>NSR(n);

        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                NSR[i]=n; // out of bounds
            }else{
                while(!s.empty() && height[s.top()]>=height[i]) s.pop();
                if(s.empty()) NSR[i]=n;
                else NSR[i]=s.top();
            }
            s.push(i);
        }
        return NSR;
    }

    // next smallest to left
    vector<int>calNSL(vector<int>& height){
        stack<int>s;
        int n=height.size();
        vector<int>NSL(n);

        for(int i=0;i<n;i++){
            if(s.empty()){
                NSL[i]=-1; // out of bounds
            }else{
                while(!s.empty() && height[s.top()]>=height[i]) s.pop();
                if(s.empty()) NSL[i]=-1;
                else NSL[i]=s.top();
            }
            s.push(i);
        }
        return NSL;
    }

    int findArea(vector<int>& height){
        vector<int>NSR = calNSR(height);
        vector<int>NSL = calNSL(height);
        int n=height.size();
        vector<int>width(n);
        for(int i=0;i<n;i++) width[i]=NSR[i]-NSL[i]-1;

        int maxArea=0;
        for(int i=0;i<n;i++) maxArea = max(maxArea,height[i]*width[i]);
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        // phele height nikaloge first row ki
        vector<int>height(m,0);
        for(int i=0;i<m;i++) height[i]=matrix[0][i]-'0';

        int maxArea = findArea(height);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') height[j]=0;
                else height[j]++;
            }
            maxArea = max(maxArea,(findArea(height)));
        }
        return maxArea;
    }
};