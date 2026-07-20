// Last updated: 20/07/2026, 10:39:10
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                if (isValid(nums, k)) {
                    answer += k;
                }
            }
        }
        return answer;
    }

private:
    bool isValid(const vector<int>& nums, int size) {
        int n = nums.size();
        int previousEnd = -1e9; 

        for (int start = 0; start < n; start += size) {
            int breakPoints = 0;
            int smallestIdx = 0;

            for (int i = 0; i < size; ++i) {
                int curr = start + i;
                int next = start + (i + 1) % size;

                if (nums[curr] > nums[next]) {
                    breakPoints++;
                    smallestIdx = (i + 1) % size;
                }
            }

            if (breakPoints > 1) return false;

            int blockMin, blockMax;
            if (breakPoints == 0) {
                blockMin = nums[start];
                blockMax = nums[start + size - 1];
            } else {
                blockMin = nums[start + smallestIdx];
                int lastIdx = (smallestIdx - 1 + size) % size;
                blockMax = nums[start + lastIdx];
            }

            if (blockMin < previousEnd) return false;
            previousEnd = blockMax;
        }

        return true;
    }
};
