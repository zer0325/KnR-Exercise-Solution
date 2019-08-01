/* Exercise 4-1. Write the function strrindex(s,t), which returns the
 * position of the rightmost occurrence of t in s, or -1 if there is
 * none.
 */

/* General idea:

   Given a string s, find if a pattern t exist. If more than 1
   pattern is found,  return the position of the last pattern.

   Lets set p as the position. Starting from the first character in
   s, test if the pattern t is found. If it is found, save the
   position. Do the same for the succeeding character until the last
   character in s. If a pattern is not found, return -1.
   
*/
#include <stdio.h>

main()
{
	char source[] = "the quick brown fox jumps over the lazy dog.";
	char pattern[] = "the";

	printf("%d\n", strrindex(source,pattern));

	return 0;
}

int strrindex(char s[], char t[])
{
	int i, j, k;
	int p;

	p = -1;
	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
			;
		if (k > 0 && t[k] == '\0')
			p = i;
	}
	return p;
}

