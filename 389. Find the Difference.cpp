class Solution {
    public:
        char findTheDifference(string s, string t) {
            char add=0;
            for(char c:s) add ^= c;
            for(char c:t) add ^= c;
            return add;
        }
    };