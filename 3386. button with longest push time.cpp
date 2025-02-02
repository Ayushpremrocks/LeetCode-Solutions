class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int longestPush = events[0][0];
        int maxTime = events[0][1];
        for(int i=1;i<events.size();i++){
            int pushtime = (events[i][1])-(events[i-1][1]);
            if(pushtime>maxTime || pushtime==maxTime && events[i][0]<longestPush){
                maxTime = pushtime;
                longestPush = events[i][0];
            }
        }
        return longestPush;
    }
};