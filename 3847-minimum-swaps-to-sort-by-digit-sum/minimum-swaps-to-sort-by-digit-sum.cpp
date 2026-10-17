class Solution {
public:
    int digitsum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end(),[&](int a,int b){
            int suma=digitsum(a);
            int sumb=digitsum(b);
            if(suma==sumb){
                return a<b;
            }
            return suma<sumb;
        });
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int swap=0;
        vector<bool>vist(n,false);
        for(int i=0;i<n;i++){
            if(vist[i]||sorted[i]==nums[i]){
                continue;
            }
            int j=i;
            int cycle=0;
            while(!vist[j]){
                vist[j]=true;
                j=mp[sorted[j]];
                cycle++;
            }
            swap+=cycle-1;
        }
        return swap;
    }
};