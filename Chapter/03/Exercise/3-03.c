/* Exercise 3-3. Write a function expand(s1,s2) that expands
 * shorthand notations like a-z in the string s1 into the equivalent
 * list abc..xyz in s2. Allow for letters of either case and digits,
 * and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */

/* General idea:

   This is somewhat similar to the file copy program from the
   previous topic on the book. The only difference is that when we
   have a shorthand notation, we replace the "-" character with a
   character or a series of characters  that  is between the
   characters in the shorthand notation.

   Given a string s1 which contains c0c1c2..cN-1, where c is the
   character, 0,1,2,..,(N-1) is the index, and N is the length of the
   string s1. Test if c[i] = '-' and together with the characters
   c[i-1] and  c[i+1], it form a proper shorthand notation. If true,
   read into s2 a character or a series of characters between c[i-1]
   and c[i+1]. We are going to do this for i = 1,2,3,...,N-2. Because
   we don't need to test the last character in s1. If it is not a
   proper shorthand notation, we just copy the character into s2.
   When we are finished with all the characters except the last, we
   copy the last character to s2. Then we put a null character at the
   end of s2.

   A proper shorthand notation is the pattern "letter-dash-letter" or
   "digit-dash-digit". Neither the patterns "letter-dash-digit" nor
   "digit-dash-letter" is a proper shorthand notation.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 1000

void expand(char s1[], char s2[]);

main()
{
	char s1[] = "expand this: --a-z a-b-c a-z0-9 -a-z---";
	char s2[SIZE];
	
	printf("original string: %s\n", s1);
	expand(s1, s2);
	printf("expanded string: %s\n", s2);

	printf("\n");
	return 0;
}

void expand(char s1[], char s2[])
{
	int i, j, c;

	s2[0] = s1[0];		/* copy the first character to s2. */

	for (i = 1, j = 1; i < strlen(s1) - 1; ++i) {
		if (s1[i] == '-' && isalpha(s1[i-1]) && isalpha(s1[i+1])) {
			for (c = s1[i-1] + 1; c < s1[i+1] - 1; ++c)
				s2[j] = c, ++j;
		} else if (s1[i] == '-' && isdigit(s1[i-1]) &&
				isdigit(s1[i+1])) {
			for (c = s1[i-1] + 1; c < s1[i+1] - 1; ++c)
				s2[j] = c, ++j;
		} else
			s2[j] = s1[i], ++j;
	}

	s2[j++] = s1[i];
	s2[j] = '\0';
}
