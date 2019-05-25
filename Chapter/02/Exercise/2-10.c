/* Exercise 2-10. Rewrite the function lower, which converts upper
 * case letters to lower case, with a conditional expression instead
 * of if-else. */

#include <stdio.h>

int lower(int c);

main()
{
	char s[] = "the quick brown FOX JUMPS OVER.";
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		printf("%c", lower(s[i]));

	printf("\n");
	return 0;
}

/* lower: converts upper case letter to lower case */
int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;

}



