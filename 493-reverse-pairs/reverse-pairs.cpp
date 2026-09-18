class Solution {
public:
    int count=0;
    void countInversion(int low,int mid,int high,vector<int>&nums){
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && (long long)nums[i]>2LL*nums[j]){
                j++;
            }
            count+=j-(mid+1);
        }
    }
    void merge(int low,int mid,int high,vector<int>&nums){
        vector<int>temp;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=low;k<=high;k++){
            nums[k]=temp[k-low];
        }
    }
    void mergesort(int low,int high,vector<int>&nums){
        if(low>=high){
            return;
        }
        int mid=low+(high-low)/2;
        mergesort(low,mid,nums);
        mergesort(mid+1,high,nums);
        countInversion(low,mid,high,nums);
        merge(low,mid,high,nums);
    }
    int reversePairs(vector<int>& nums) {
        count=0;
        mergesort(0,nums.size()-1,nums);
        return count;
    }
};