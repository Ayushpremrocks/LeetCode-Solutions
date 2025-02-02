class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> sum(nums1.size()+nums2.size());
        double medium;
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),sum.begin());
        int mid = sum.size()/2;
        if((sum.size()%2)==0){
            medium = (sum[mid-1]+sum[mid])/2.0;
        }else{
            medium = sum[mid];
        }
        return medium;
    }
};