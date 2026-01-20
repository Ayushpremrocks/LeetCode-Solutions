class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zc=0;
        int m = flowerbed.size();
        int cost = 0;
        int seq=0;
        bool start=true;
        for(int i=0;i<m;i++){
            if(flowerbed[i]==0) seq++;
            else{
                if(start) cost+=seq/2;
                else cost+=((seq-1))/2;

                start = false;
                seq=0;
            }
        }

        if(start) cost+=(m+1)/2;
        else cost+=seq/2;
        if(cost>=n) return true;
        else return false;
    }
};