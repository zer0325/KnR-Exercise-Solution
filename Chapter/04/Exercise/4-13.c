/* Exercise 4-13. Write a recursive version of the function
 * reverse(s), which reverses the string s in place */


/*
    General Idea;

	Let us look at the original source of reverse(s) function.

	#include <stdio.h>
	void reverse(char s[])
	{
		int c, i, j;

		for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}

	Based on the code above, the reverse function is just a simple
	swap operation. In this case the elements that are being swapped
	are the elements beginning at the leftmost and the rightmost
	elements.

	Applying this concept, we can recursively call the reverse
	function until the left element is equal to the right element, or
	the left element goes past the right element. 

	Once we reach this condition, we perform the swap. In code;

		if(left < right)
			reverse(s);

		swap(s, left, right);
		return;
	
	Based on the original code, we start at the leftmost element and
	the rightmost element. Meaning our left variable will start at 0,
	and the right variable will start at strlen(s) - 1. Since we are
	going to call the reverse function recursively, we also need to
	provide a different value for the left and the right variables.
	To have access to the value of the left variable, we are going to
	make it an external variable. And the value of the right variable
	will depend on the value of the left varible. So our code will
	become,

	int left = 0;
	void reverse(char s[])
	{
		int right;

		right = strlen(s) - 1 - left;
		if(left < right)
			reverse(s);

		swap(s, left, right);
		return;
	}
	
	Based on the original, we need to incremet the left variable,
	before calling the reverse function. So our code becomes,

	....
		if(left < right) {
			++left;
			reverse(s)
		}
	...

	Note that when the value of the left and right are equal or the
	left value goes past the right value, we need to go back to the
	previous values of the left and the right variables, before
	doing the swap operation. So our code now becomes,

	...
		if(left >= right) {
			--left, ++right;
			return;
		}
		swap(s, left, right);
		return;
	...
	
	And after every swap, we need to decrement left, and increment
	right. So our final code will be,
*/
#include <string.h>

int left = 0;
void reverse(char s[])
{
	int right;
	void swap(char s[], int i, int j);

	right = strlen(s) - 1 - left;
	if(left < right) {
		++left;
		reverse(s);
	}
	if(left >= right) {
		--left, ++right;
		return;
	}
	swap(s, left--, right++);

	return;
}

void swap(char s[], int i, int j)
{
	char c;

	c = s[i];
	s[i] = s[j];
	s[j] = c;

	return;
}



