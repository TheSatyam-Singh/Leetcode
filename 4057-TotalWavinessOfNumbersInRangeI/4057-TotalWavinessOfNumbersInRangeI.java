// Last updated: 20/07/2026, 11:23:41
class Solution {
    public int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            String s = String.valueOf(i);
            for (int j = 1; j < s.length() - 1; j++) {
                if ((s.charAt(j) > s.charAt(j - 1) && s.charAt(j) > s.charAt(j + 1)) ||
                    (s.charAt(j) < s.charAt(j - 1) && s.charAt(j) < s.charAt(j + 1))) {
                    ans++;
                }
            }
        }
        return ans;
    }
}