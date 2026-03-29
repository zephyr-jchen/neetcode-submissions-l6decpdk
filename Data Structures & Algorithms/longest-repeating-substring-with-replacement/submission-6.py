class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count_dic = defaultdict(int)
        left,max_length,max_count,length = 0,0,0,0
        for right in range(len(s)):
            count_dic[s[right]] += 1
            max_count = max(max_count,count_dic[s[right]])
            if right - left + 1 > k + max_count:
                count_dic[s[left]] -= 1
                left += 1
            max_length = max(max_length,right-left+1)

        return max_length