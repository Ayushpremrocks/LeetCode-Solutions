class Solution {
  public:
    int merge(vector<int> &a, int low, int mid, int high){
        vector<int>temp;
        int left=low;
        int right = mid+1;
        int count=0;
        while(left<=mid && right<=high){
            if(a[left]<=a[right]){
                temp.push_back(a[left]);
                left++;
            }else{
                temp.push_back(a[right]);
                count+=(mid-left+1);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(a[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(a[right]);
            right++;
        }
        
        for(int i=low;i<=high;i++){
            a[i]=temp[i-low];
        }
        return count;
    }
    
    int mergeSort(vector<int>& a, int low, int high){
        if(low>=high) return 0;
        int count=0;
        int mid=(low+high)/2;
        count+=mergeSort(a,low,mid);
        count+=mergeSort(a,mid+1,high);
        count+=merge(a,low,mid,high);
        return count;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergeSort(arr,0,arr.size()-1);
    }
};