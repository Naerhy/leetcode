/*

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters.

*/

#include <string.h>

int is_valid_prefix(char* word, int word_length, char** strs, int strs_size)
{
	for (int i = 1; i < strs_size; i++)
	{
		if (strncmp(word, *(strs + i), word_length))
			return 0;
	}
	return 1;
}

char* longestCommonPrefix(char** strs, int strs_size)
{
	int first_word_length;
	char* ret_word;

	first_word_length = strlen(*strs);
	ret_word = malloc((first_word_length + 1) * sizeof(char));
	memset(ret_word, '\0', first_word_length + 1);
	for (int i = 0; i < strs_size; i++)
	{
		if (!strlen(*(strs + i)))
			return strcpy(ret_word, "");
	}
	if (strs_size == 1)
		return strcpy(ret_word, *strs);
	while (first_word_length)
	{
		if (is_valid_prefix(*strs, first_word_length, strs, strs_size))
			return strncpy(ret_word, *strs, first_word_length);
		first_word_length--;
	}
	return strcpy(ret_word, "");
}
