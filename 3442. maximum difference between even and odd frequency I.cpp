class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>map;
        vector<int>evenCount;
        vector<int>oddCount;
        for(char c:s){
            map[c]++;
        }
        for(const auto& it:map){
            if(it.second%2==0){
                evenCount.push_back(it.second);
            }else{
                oddCount.push_back(it.second);
            }
        }
        int maxOdd = *max_element(oddCount.begin(),oddCount.end());
        int evenMin = *min_element(evenCount.begin(),evenCount.end());
        return maxOdd - evenMin;
    }
};