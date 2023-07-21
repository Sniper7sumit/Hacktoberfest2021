def power_set_recursive(nums):
    def backtrack(start, path):
        result.append(path[:])
        for i in range(start, len(nums)):
            path.append(nums[i])
            backtrack(i + 1, path)
            path.pop()

    result = []
    backtrack(0, [])
    return result

# Example usage:
if __name__ == "__main__":
    nums = [1, 2, 3]
    print("Power Set (Recursive):")
    print(power_set_recursive(nums))
