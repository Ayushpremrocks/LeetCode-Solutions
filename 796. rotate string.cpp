class Solution {
public:
    bool rotateString(string s, string goal) {
        bool value = false;
        int n = s.size();
        for(int i=0;i<n;i++){
            string temp = s;
            for(int j=0;j<n;j++){
                temp[j] = s[(j+1)%n];
            }
            s = temp;
            if (s==goal) value = true;
        }
        return value;
    }
};