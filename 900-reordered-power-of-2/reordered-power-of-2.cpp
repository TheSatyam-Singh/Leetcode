class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        for(int i=0;i<=30;i++){
            int a=1<<i;
            string t=to_string(a);
            sort(t.begin(),t.end());
            if(s==t){
                return true;
            }
        }
        return false;
    }
};