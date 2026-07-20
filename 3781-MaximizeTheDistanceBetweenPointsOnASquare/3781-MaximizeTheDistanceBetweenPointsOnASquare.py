# Last updated: 20/07/2026, 10:42:38
class Solution:
    def maxDistance(self,side:int,points:List[List[int]],k:int)->int:
        pos=[]
        for x,y in points:
            if x==0:
                pos.append(y)
            elif y==side:
                pos.append(side+x)
            elif x==side:
                pos.append(3*side-y)
            else:
                pos.append(4*side-x)
        pos.sort()
        p=4*side
        def can(d):
            for s in pos:
                lim=s+p-d
                cur=s
                for i in range(k-1):
                    i=bisect_left(pos,cur+d)
                    if i==len(pos) or pos[i]>lim:
                        break
                    cur=pos[i]
                else:
                    return True
            return False
        l,h=1,side
        ans=0
        while l<=h:
            m=(l+h)//2
            if can(m):
                ans=m
                l=m+1
            else:
                h=m-1
        return ans