/* Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes
 * each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

main()
{
	char s1[] = "The quick brown fox jumps over the lazy dog.\n";
	char s2[] = "abcaaabbbcc";

	squeeze(s1, s2);
	printf("%s", s1);

	return 0;
}

/* squeeze: delete each character in s1 that matches any character is s2 */
void squeeze (char s1[], char s2[])
{
	int i, j, k;

	for (k = 0; s2[k] != '\0'; k++) {
		for (i = j = 0; s1[i] != '\0'; i++)
			if (s1[i] != s2[k])
				s1[j++] = s1[i];
		s1[j] = '\0';
	}

}

/* Note:

   If you are in linux, test this program against a program called tr, which has
   an option that does the same thing. E.g. 

   % echo "The quick brown fox jumps over the lazy dog." | tr -d abcaaabbbcc


   The output should be similar to the output of our program.

   */
