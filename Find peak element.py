https://leetcode.com/problems/find-peak-element/
def findPeakElement(self, nums):
    left = 0
    right = len(nums)-1

    # handle condition 3
    while left < right-1:
        mid = (left+right)/2
        if nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]:
            return mid

        if nums[mid] < nums[mid+1]:
            left = mid+1
        else:
            right = mid-1

    #handle condition 1 and 2
    return left if nums[left] >= nums[right] else right
