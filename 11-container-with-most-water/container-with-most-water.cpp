class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int i=0;
        int j=height.size()-1;
        /*for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                int w=j-i;
                int h=min(height[i],height[j]);
                ans=max(ans,w*h);
            }
        }*/
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            ans=max(ans,w*h);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};