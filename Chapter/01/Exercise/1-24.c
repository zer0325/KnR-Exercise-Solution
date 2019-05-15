/* Exercise 1-24. Write a program to check a C program for 
 * rudimentary syntax errors like unbalanced parenthesis,
 * brackets and braces. Don't forget about quotes, both 
 * single and double, escape sequences, and comments. 
 * (This program is hard if you do it in full generality.)
 */

/* Procedure:

   Process the input per character. 
   To check for unbalanced parenthesis, we count the total 
   number of open parenthessis and close parenthesis. 
   Compare the open and close parenthesis, if they are 
   equal, they are balanced. Provided if they are
   outside a comment.

   Prior to this exercise the escape sequence that have 
   been discussed are:

   \t, \n, \b, \" and \\.
 
*/

#include <stdio.h>
#define IN  1		/* inside a comment */
#define OUT 0		/* outside a comment */

main()
{
	int c, state, comment, paren, brace, bracket;
	int double_q, single_q, esc_sequence;

	comment = paren = brace = bracket = 0;
	double_q = single_q = esc_sequence = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == '/' && state == OUT) {
			/* Check if the next character is an '*' */
			c = getchar();
			if (c == '*') {
				state = IN;
				++comment;
			}
		} else if (c == '*' && state == IN) {
			/* Check if the next character is a '/' */
			c = getchar();
			if (c == '/') {
				state = OUT;
				--comment;
			}
		} else if (state == OUT) {
			if (c == '(')
				++paren;
			else if (c == ')')
				--paren;
			else if (c == '{')
				++bracket;
			else if (c == '}')
				--bracket;
			else if (c == '[')
				++bracket;
			else if (c == ']')
				--bracket;
			else if (c == 0x22) /* double quote in ASCII */
				++double_q;
			else if (c == 0x27)	/* single quote in ASCII */ 
				++single_q;
			else if (c == 0x5c) { /* if escape sequence 
								  * Get the next character 
								  */
				c = getchar();
				if (c != 'n' && c != 't' && c != 'b' && c != 0x22 && c != 0x5c)
					++esc_sequence;
			}
		}

	}

	if (comment != 0 || paren != 0 || bracket != 0 || brace != 0)
		printf("Syntax Error !!!\n");
	if (double_q % 2 != 0 || single_q % 2 != 0 && esc_sequence != 0)
		printf("Syntax Error !!!\n");


	return 0;
}
