/* Exercise 2-5. Write a function any(s1, s2), which returns the first location
 * in the string s1 where any character from string s2 occurs, or -1 if s1
 * contains no character from s2. (The standard library function strpbrk does
 * the same job but returns a pointer to the location.)
 */

#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
	char s1[] = "The quick brown fox jumps over the lazy dog.\n";
	char s2[] = "23235234*099ez";

	printf("%d\n", any(s1, s2));

	return 0;
}

/* any: returns first location in the string s1 where any character from string
 * s2 occurs otherwise return -1.
 */
int any(char s1[], char s2[])
{
	int i, j;
	int found_match = 0;

	for (i = 0; s2[i] != '\0' && !found_match; ++i)
		for (j = 0; s1[j] != '\0' && !found_match; ++j)
			if (s1[j] == s2[i])
				found_match = 1;

	if (found_match)
		return j;
	else 
		return -1;
}
