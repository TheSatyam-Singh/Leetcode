# Last updated: 20/07/2026, 11:25:20
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        count=0
        for i in 'abcdefghijklmnopqrstuvwxyz':
            last_lower=word.rfind(i)
            first_upper=word.find(i.upper())
            if last_lower!=-1 and first_upper!=-1:
                if last_lower<first_upper:
                    count+=1
        return count