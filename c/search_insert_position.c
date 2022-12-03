/*

Given a sorted array of distinct integers and a target value, return the index if the target
is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:
    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums contains distinct values sorted in ascending order.
    -104 <= target <= 104

*/

int searchInsert(int* nums, int nums_size, int target)
{
	if (target < *nums)
		return 0;
	if (target > *(nums + nums_size - 1))
		return nums_size;
	for (int i = 0; i < nums_size; i++)
	{
		if (*(nums + i) == target)
			return i;
		if (*(nums + i) < target && *(nums + i + 1) > target)
			return i + 1;
	}
	return 0; // useless return statement
}
