# Last updated: 20/07/2026, 11:25:10
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        count=0
        for i in set(word):
            if i.islower() and i.upper() in word:
                count+=1
        return count