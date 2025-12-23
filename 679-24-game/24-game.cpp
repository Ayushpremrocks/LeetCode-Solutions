class Solution {
private:
    bool solve(vector<double>& cards){
        //base case
        double n=cards.size();
        double epsilon=1e-6;
        if(n==1) return abs(cards[0]-24)<=epsilon;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j) continue;
                vector<double>temp;
                for(int k=0;k<n;k++){
                    if(i!=k && j!=k) temp.push_back(cards[k]);
                }
                double a = cards[i];
                double b = cards[j];
                vector<double>posOut = {a+b,a*b,a-b,b-a};
                if(abs(b)>epsilon) posOut.push_back(a/b);
                if(abs(a)>epsilon) posOut.push_back(b/a);

                // backtracking yaha hui
                for(auto it:posOut){
                    temp.push_back(it); // mark
                    if(solve(temp)) return true; //check
                    temp.pop_back(); //unmarked
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double>a(cards.size());
        for(int i=0;i<cards.size();i++) a[i]=(1.0*cards[i]);
        return solve(a);
    }
};