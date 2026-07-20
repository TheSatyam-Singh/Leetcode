// Last updated: 20/07/2026, 10:39:30
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> next_ge(n, n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                next_ge[i] = st.top();
            }
            st.push(i);
        }
        
        vector<long long> left_counts(n);
        vector<int> last(31, -1);
        
        for (int i = 0; i < n; ++i) {
            int max_bad = -1;
            for (int b = 0; b <= 30; ++b) {
                if ((nums[i] & (1 << b)) == 0) {
                    if (last[b] > max_bad) {
                        max_bad = last[b];
                    }
                }
            }
            left_counts[i] = i - max_bad;
            
            for (int b = 0; b <= 30; ++b) {
                if (nums[i] & (1 << b)) {
                    last[b] = i;
                }
            }
        }
        
        long long total = 0;
        vector<int> next_occ(31, n);
        
        for (int i = n - 1; i >= 0; --i) {
            int min_bad = n;
            for (int b = 0; b <= 30; ++b) {
                if ((nums[i] & (1 << b)) == 0) {
                    if (next_occ[b] < min_bad) {
                        min_bad = next_occ[b];
                    }
                }
            }
            
            int limit_right = next_ge[i];
            if (min_bad < limit_right) {
                limit_right = min_bad;
            }
            
            long long right_count = limit_right - i;
            total += left_counts[i] * right_count;
            
            for (int b = 0; b <= 30; ++b) {
                if (nums[i] & (1 << b)) {
                    next_occ[b] = i;
                }
            }
        }
        
        return total;
    }
};