class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        c=[]
        l=0
        mx=0
        for i in range(len(s)):
            while s[i] in c:
                c.remove(s[l])
                l+=1
            c.append(s[i])
            mx=max(mx,i-l+1)
        return mx