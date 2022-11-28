/*

Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-.
Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:
    -231 <= x <= 231 - 1

*/

bool isPalindrome(int x)
{
	int dup;
	unsigned int rev;
	int last_digit;

	if (x < 0)
		return false;
	if (x >= 0 && x <= 9)
		return true;
	dup = x;
	rev = 0;
	while (dup > 0)
	{
		last_digit = dup % 10;
		rev = rev * 10 + last_digit;
		dup /= 10;
	}
	if (x == rev)
		return true;
	return false;
}
