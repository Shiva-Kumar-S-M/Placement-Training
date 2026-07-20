# Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

# Note that you must do this in-place without making a copy of the array.

def move_zeroes(nums):
    """
    This function moves all zeros in the input list 'nums' to the end while maintaining the order of non-zero elements.
    
    :param nums: List[int] - The input list of integers
    :return: None - The function modifies the list in place
    """
    # Initialize a pointer for the position of the next non-zero element
    last_non_zero_found_at = 0

    # Iterate through the array
    for current in range(len(nums)):
        # If the current element is not zero, we need to move it to the last_non_zero_found_at position
        if nums[current] != 0:
            # Swap the elements at last_non_zero_found_at and current
            nums[last_non_zero_found_at], nums[current] = nums[current], nums[last_non_zero_found_at]
            # Move the pointer to the next position
            last_non_zero_found_at += 1

# Given an unsorted integer array nums, return the smallest positive integer that is not present in nums.

# You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
def find_missing_positive(nums):
    """
    This function finds the smallest positive integer that is not present in the input list 'nums'.
    
    :param nums: List[int] - The input list of integers
    :return: int - The smallest missing positive integer
    """
    n = len(nums)

    # First, we will place each number in its right place (i.e., nums[i] should be i + 1)
    for i in range(n):
        while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
            # Swap nums[i] with the number at its correct position
            nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

    # Now, we will find the first index where the number is not equal to index + 1
    for i in range(n):
        if nums[i] != i + 1:
            return i + 1

    # If all numbers from 1 to n are present, then the missing number is n + 1
    return n + 1


# Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation
def product_except_self(nums):
    """
    This function returns an array where each element at index 'i' is the product of all elements in 'nums' except nums[i].
    
    :param nums: List[int] - The input list of integers
    :return: List[int] - The resulting list of products
    """
    n = len(nums)
    answer = [1] * n

    # Calculate the prefix products
    prefix_product = 1
    for i in range(n):
        answer[i] = prefix_product
        prefix_product *= nums[i]

    # Calculate the suffix products and multiply with the prefix products
    suffix_product = 1
    for i in range(n - 1, -1, -1):
        answer[i] *= suffix_product
        suffix_product *= nums[i]

    return answer


""" Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

"""
def trap(height):
    """
    This function calculates the amount of water that can be trapped after raining given an elevation map represented by 'height'.
    
    :param height: List[int] - The input list representing the elevation map
    :return: int - The total amount of trapped water
    """
    if not height:
        return 0

    n = len(height)
    left_max = [0] * n
    right_max = [0] * n

    # Fill left_max array
    left_max[0] = height[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], height[i])

    # Fill right_max array
    right_max[n - 1] = height[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], height[i])

    # Calculate the trapped water
    trapped_water = 0
    for i in range(n):
        trapped_water += min(left_max[i], right_max[i]) - height[i]

    return trapped_water