class Solution {
private:
    vector<vector<int>> solve(vector<int>& candidates, int target, int i,vector<vector<int>>& res,vector<int>& temp){
        int n = candidates.size();
        // base case
        if(i==n){
            if(target==0)
            res.push_back(temp);
            return res;
        }
        //take
        if(candidates[i]<=target){
            temp.push_back(candidates[i]); //visit
            solve(candidates,target-candidates[i],i,res,temp);
            temp.pop_back();
        }
        //not take
        solve(candidates,target,i+1,res,temp);
        return res;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        return solve(candidates,target,0,res,temp);
    }
};