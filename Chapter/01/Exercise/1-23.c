/* Exercise 1-23. Write a program to remove all comments 
 * from a C program. Don't forget to handle quoted strings
 * and character constants properly. C comments do not 
 * nest.
 */

/* Procedure:

   Process the input per character.
   If the character is a '/'
   		Check if the next character is an '*', if true, 
		set state = IN. Otherwise save the '/' and the
		recently read character.
   If the character is an '*'
   		Check if state = IN, if true, check if the next 
		character is a '/',
				If true, set state = OUT.
		otherwise, save the character.
   For other characters
   		Check if the state = OUT, if true, save the 
		character.

*/

#include <stdio.h>
#define IN  1		/* inside a comment */
#define OUT 0		/* outside a comment */
#define MAX 1000	/* size of the array */

main()
{
	int c, temp, i, state;
	char s[MAX];

	i = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == '/' && state == OUT) {
			/* Save a copy of the character */
			temp = c;
			c = getchar();
			if (c == '*')
				state = IN;
			else {
				s[i] = temp;
				++i;
				/* Overflow check */
				if (i == MAX - 1) {
					s[i] = '\0';
					printf("%s", s);
					i = 0;
				}
				s[i] = c;
				++i;
			}
		} else if (c == '*') {
			/* Save a copy of the character */
			temp = c;
			if (state == IN) {
				c = getchar();
				if (c == '/')
					state = OUT;
			} else {
				s[i] = temp;
				++i;
			}
		} else {
			if (state == OUT) {
				s[i] = c;
				++i;
			}
		}

		/* Process the input if the array is full */
		if (i == MAX - 1) {
			s[i] = '\0';
			printf("%s", s);
			i = 0;
		}
	}
	/* Process the remaining input */
	s[i] = '\0';
	printf("%s", s);

	return 0;
}


  
