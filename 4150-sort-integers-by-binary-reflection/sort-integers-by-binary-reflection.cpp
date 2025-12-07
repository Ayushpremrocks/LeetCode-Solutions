class Solution {
private:
    int convert(int a){
        string b=bitset<32>(a).to_string();
        int j=0;
        for(int i=0;i<b.size();i++){
            if(b[i]=='1'){
                j=i;
                break;
            }
        }
        string bnew = b.substr(j);
        reverse(bnew.begin(),bnew.end());
        return stoi(bnew,nullptr,2);
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            int newa = convert(a);
            int newb = convert(b);
            if(newa==newb) return a<b;
            return newa<newb;
        });
        return nums;
    }
};