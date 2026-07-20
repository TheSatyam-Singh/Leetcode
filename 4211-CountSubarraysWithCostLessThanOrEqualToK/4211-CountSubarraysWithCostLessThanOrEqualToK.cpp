// Last updated: 20/07/2026, 10:39:40
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int size = nums.size();
        int left = 0;
        long long total = 0;

        deque<int> smallest, biggest;

        for(int right = 0; right < size; right++) {
            while(!smallest.empty() && nums[smallest.back()] >= nums[right])
                smallest.pop_back();
            smallest.push_back(right);

            while(!biggest.empty() && nums[biggest.back()] <= nums[right])
                biggest.pop_back();
            biggest.push_back(right);

            while((long long)(nums[biggest.front()] - nums[smallest.front()]) * (right - left + 1) > k) {
                if(smallest.front() == left)
                    smallest.pop_front();
                if(biggest.front() == left)
                    biggest.pop_front();
                left++;
            }
            total += (right - left + 1);
        }
        return total;
    }
};