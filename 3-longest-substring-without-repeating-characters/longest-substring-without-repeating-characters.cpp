class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1); // Tracks the last index where each character appeared
        int maxLength = 0;
        int left = 0; // Left pointer of the sliding window

        for (int right = 0; right < s.length(); right++) {
            char currChar = s[right];

            // If the character was seen inside the current window, move the left pointer
            if (lastSeen[currChar] >= left) {
                left = lastSeen[currChar] + 1;
            }

            // Update last seen position of current character
            lastSeen[currChar] = right;

            // Calculate max window size
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};