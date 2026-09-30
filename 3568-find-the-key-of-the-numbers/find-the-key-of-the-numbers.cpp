class Solution {
public:
    int generateKey(int nums1, int nums2, int nums3) {
        int ans=0;
        int place=1;
        for(int i=0;i<4;i++){
            int a1=nums1%10;
            int a2=nums2%10;
            int a3=nums3%10;
            int digit=min(a1,min(a2,a3));
            ans+=digit*place;
            place*=10;
            nums1/=10;
            nums2/=10;
            nums3/=10;
        }
        return ans;
    }
};