class Solution(object):
    def threeSumClosest(self, nums, target):
        nums.sort()

        left, right, loop_sum, prev_sum = 0, 0, 0, 0
        result = nums[0] + nums[1] + nums[2]
        curr_diff = target - (nums[0] + nums[1] + nums[2])

        for i in range(len(nums)):
            left = i + 1
            right = len(nums) - 1

            while left < right:
                prev_sum = loop_sum
                loop_sum = nums[i] + nums[left] + nums[right]

                if abs(target - loop_sum) < curr_diff:
                    result = loop_sum
                    curr_diff = abs(target - loop_sum)

                if loop_sum == target:
                    return target

                if loop_sum < target:
                    left += 1
                
                if loop_sum > target:
                    right -= 1

        return result