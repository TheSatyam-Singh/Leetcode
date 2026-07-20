# Last updated: 20/07/2026, 10:38:48
from typing import List
from collections import defaultdict
class Solution:
    def countWordOccurrences(self, chunks: List[str], queries: List[str]) -> List[int]:
        s = "".join(chunks)
        n = len(s)
        word_counts = defaultdict(int)
        i = 0
        while i < n:
            if 'a' <= s[i] <= 'z':
                start = i
                j = i + 1
                while j < n:
                    c = s[j]
                    if 'a' <= c <= 'z':
                        j += 1
                    elif c == '-':
                        if j + 1 < n and 'a' <= s[j+1] <= 'z':
                            j += 1
                        else:
                            break
                    else:
                        break
                word = s[start:j]
                word_counts[word] += 1
                i = j
            else:
                i += 1
        return [word_counts[q] for q in queries]