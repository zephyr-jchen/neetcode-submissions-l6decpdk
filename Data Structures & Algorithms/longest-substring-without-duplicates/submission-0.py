class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        left,right = 0,0
        length = 0
        max_set = set()
        while right < len(s):
            while s[right] in max_set:
                max_set.remove(s[left])
                left+=1
            max_set.add(s[right])
            right+=1
            length = max(length,len(max_set))
        return length

        