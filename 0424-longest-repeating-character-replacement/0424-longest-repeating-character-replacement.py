class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        map={}
        l=0
        maxf=0
        for i in range(len(s)):
            map[s[i]]=1+map.get(s[i],0)
            maxf=max(maxf,map[s[i]])
            
            if (i-l+1)-maxf>k:
                map[s[l]]-=1
                l+=1
        return (i-l+1)
        