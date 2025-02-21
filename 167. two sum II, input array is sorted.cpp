class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            unordered_map<int,int> hashmap;
            for(int i=0;i<numbers.size();i++){
                int compliment = target - numbers[i];
                if(hashmap.find(compliment)!=hashmap.end()){
                    return {hashmap[compliment]+1,i+1};
                }
                hashmap[numbers[i]]=i;
            }
            return {};
        }
    };