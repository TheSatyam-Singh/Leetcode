// Last updated: 20/07/2026, 11:23:40
var totalWaviness = function(num1, num2) {
    let ans = 0;
    for (let num = num1; num <= num2; num++) {
        const s = num.toString();
        for (let i = 1; i < s.length - 1; i++) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                ans++;
            }
        }
    }
    return ans;
};