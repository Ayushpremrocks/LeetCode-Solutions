class Solution {
private:
    void generatePairs(vector<string>&temp, int leftBracket, int rightBracket, string s, int n){
        if(leftBracket>n || rightBracket>n || rightBracket>leftBracket) return;
        if(leftBracket==n && rightBracket==n){
            temp.push_back(s);
        }
        generatePairs(temp,leftBracket+1,rightBracket,s+'(',n);
        generatePairs(temp,leftBracket,rightBracket+1,s+')',n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>temp;
        string s="";
        generatePairs(temp,0,0,s,n);
        return temp;
    }
};