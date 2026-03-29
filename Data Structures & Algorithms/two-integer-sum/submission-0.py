class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        output = []
        record = {}
        for i in range(len(nums)):
            num1 = target - nums[i]
            if num1 in record:
                output.append(record[num1])
                output.append(i)
            else:
                record[nums[i]] = i
        return output 

            
            
